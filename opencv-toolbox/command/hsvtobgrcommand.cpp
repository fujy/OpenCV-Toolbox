#include "hsvtobgrcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

HSVToBGRCommand::HSVToBGRCommand()
    : ACommand()
{

}

HSVToBGRCommand::~HSVToBGRCommand()
{
}

int HSVToBGRCommand::execute(cv::Mat image)
{
    cv::cvtColor(image, image, cv::COLOR_HSV2BGR);
    return 1;
}

