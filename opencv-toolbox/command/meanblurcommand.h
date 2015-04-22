#ifndef MEANBLURCOMMAND_H
#define MEANBLURCOMMAND_H

#include "acommand.h"

class MeanBlurCommand : public ACommand
{
public:
    MeanBlurCommand();
    ~MeanBlurCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // MEANBLURCOMMAND_H
