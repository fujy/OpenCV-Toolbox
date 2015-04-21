#include "bgrtograycommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

BGRToGrayCommand::BGRToGrayCommand()
    : ACommand()
{

}

BGRToGrayCommand::~BGRToGrayCommand()
{
}

int BGRToGrayCommand::execute(cv::Mat image)
{
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    return 1;
}

