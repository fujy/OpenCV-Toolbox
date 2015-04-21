#ifndef MEDIANBLURCOMMAND_H
#define MEDIANBLURCOMMAND_H

#include "acommand.h"

class MedianBlurCommand : public ACommand
{
public:
    MedianBlurCommand();
    ~MedianBlurCommand();
    int execute(cv::Mat image);
};

#endif // MEDIANBLURCOMMAND_H
