#include "sobelxcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

SobelXCommand::SobelXCommand()
    : ACommand()
{

}

SobelXCommand::~SobelXCommand()
{
}

int SobelXCommand::execute(cv::Mat image)
{
    cv::cvtColor(image,image,CV_BGR2GRAY);
    cv::Sobel(image,image,image.depth(),1,0,3,0.4,128);
    return 1;
}

