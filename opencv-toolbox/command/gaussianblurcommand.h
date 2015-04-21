#ifndef GAUSSIANBLURCOMMAND_H
#define GAUSSIANBLURCOMMAND_H

#include "acommand.h"

class GaussianBlurCommand : public ACommand
{
public:
    GaussianBlurCommand();
    ~GaussianBlurCommand();
    int execute(cv::Mat image);
};

#endif // GAUSSIANBLURCOMMAND_H
