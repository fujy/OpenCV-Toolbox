#include "gaussianblurcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

GaussianBlurCommand::GaussianBlurCommand()
    : ACommand()
{

}

GaussianBlurCommand::~GaussianBlurCommand()
{
}

int GaussianBlurCommand::execute(cv::Mat image)
{
    cv::GaussianBlur(image,image,cv::Size(5,5),1.5);
    return 1;
}

