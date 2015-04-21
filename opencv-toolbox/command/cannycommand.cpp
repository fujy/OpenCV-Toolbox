#include "cannycommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

CannyCommand::CannyCommand()
    : ACommand()
{

}

CannyCommand::~CannyCommand()
{
}

int CannyCommand::execute(cv::Mat image)
{
    int lowThreshold = 125;
    int highThreshold = 350;
    cv::cvtColor(image,image,CV_BGR2GRAY);
    cv::Canny(image,image,lowThreshold,highThreshold);
    return 1;
}

