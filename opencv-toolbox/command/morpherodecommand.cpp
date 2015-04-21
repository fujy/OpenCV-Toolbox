#include "morpherodecommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

MorphErodeCommand::MorphErodeCommand()
    : ACommand()
{

}

MorphErodeCommand::~MorphErodeCommand()
{
}

int MorphErodeCommand::execute(cv::Mat image)
{
    cv::erode(image,image,cv::Mat());
    return 1;
}

