#ifndef SALTNOISECOMMAND_H
#define SALTNOISECOMMAND_H

#include "acommand.h"

class SaltNoiseCommand : public ACommand
{
public:
    SaltNoiseCommand();
    ~SaltNoiseCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // SALTNOISECOMMAND_H
