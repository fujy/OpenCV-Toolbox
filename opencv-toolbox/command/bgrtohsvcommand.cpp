#include "bgrtohsvcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

BGRToHSVCommand::BGRToHSVCommand()
    : ACommand()
{

}

BGRToHSVCommand::~BGRToHSVCommand()
{
}

cv::Mat BGRToHSVCommand::execute(cv::Mat image)
{
    cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
    return image;
}

