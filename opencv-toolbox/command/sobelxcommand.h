#ifndef SOBELXCOMMAND_H
#define SOBELXCOMMAND_H

#include "acommand.h"

class SobelXCommand : public ACommand
{
public:
    SobelXCommand();
    ~SobelXCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // SOBELXCOMMAND_H
