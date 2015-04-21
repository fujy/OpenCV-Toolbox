#include "bgrtoluvcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

BGRToLUVCommand::BGRToLUVCommand()
    : ACommand()
{

}

BGRToLUVCommand::~BGRToLUVCommand()
{
}

int BGRToLUVCommand::execute(cv::Mat image)
{
    cv::cvtColor(image, image, cv::COLOR_BGR2Luv);
    return 1;
}

