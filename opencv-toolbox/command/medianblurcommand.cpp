#include "medianblurcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

MedianBlurCommand::MedianBlurCommand()
    : ACommand()
{

}

MedianBlurCommand::~MedianBlurCommand()
{
}

int MedianBlurCommand::execute(cv::Mat image)
{
    cv::medianBlur(image,image,5);
    return 1;
}

