#include "meanblurcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

MeanBlurCommand::MeanBlurCommand()
    : ACommand()
{

}

MeanBlurCommand::~MeanBlurCommand()
{
}

int MeanBlurCommand::execute(cv::Mat image)
{
    cv::blur(image,image,cv::Size(5,5));
    return 1;
}

