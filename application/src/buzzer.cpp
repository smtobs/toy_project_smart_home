#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/ioctl.h>

#include "buzzer.hpp"

Buzzer::Buzzer()
{
    if (access(this->dev_path, F_OK) != 0)
    {
        
    }

    if ((this->fd = open(this->dev_path, O_RDWR)) < 0)
    {
        std::cout << this->dev_path << " Open Failed [" << strerror(errno) << "]" <<  std::endl;
    }
}

void Buzzer::SuccessSound(void)
{
    ioctl(this->fd, IOCTL_CMD_SUCCESS_SOUND_BUZZER);
}

void Buzzer::ButtonPushSound(void)
{
    ioctl(this->fd, IOCTL_CMD_BUTTON_PUSH_SOUND_BUZZER);
}

Buzzer::~Buzzer()
{
    if (this->fd)
    {
        close(this->fd);
    }
}