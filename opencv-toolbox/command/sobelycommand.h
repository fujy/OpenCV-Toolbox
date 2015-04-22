#ifndef SOBELYCOMMAND_H
#define SOBELYCOMMAND_H

#include "acommand.h"

class SobelYCommand : public ACommand
{
public:
    SobelYCommand();
    ~SobelYCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // SOBELYCOMMAND_H
