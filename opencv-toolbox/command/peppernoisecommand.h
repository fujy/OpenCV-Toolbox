#ifndef PEPPERNOISECOMMAND_H
#define PEPPERNOISECOMMAND_H

#include "acommand.h"

class PepperNoiseCommand : public ACommand
{
public:
    PepperNoiseCommand();
    ~PepperNoiseCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // PEPPERNOISECOMMAND_H
