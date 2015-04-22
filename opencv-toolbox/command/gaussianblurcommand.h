#ifndef GAUSSIANBLURCOMMAND_H
#define GAUSSIANBLURCOMMAND_H

#include "acommand.h"

class GaussianBlurCommand : public ACommand
{
public:
    GaussianBlurCommand();
    ~GaussianBlurCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // GAUSSIANBLURCOMMAND_H
