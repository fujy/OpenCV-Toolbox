#include "flipcommand.h"
#include "opencv2/core.hpp"

#include <QString>

FlipCommand::FlipCommand()
    : ACommand()
{
    commandName = "Flip";
}

FlipCommand::~FlipCommand()
{
}

cv::Mat FlipCommand::execute(cv::Mat image)
{
    cv::flip(image,image,1);
    return image;
}

