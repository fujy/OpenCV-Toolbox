#include "flipcommand.h"
#include "opencv2/core.hpp"

FlipCommand::FlipCommand()
    : ACommand()
{

}

FlipCommand::~FlipCommand()
{
}

int FlipCommand::execute(cv::Mat image)
{
    cv::flip(image,image,1);
    return 1;
}

