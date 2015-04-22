#include "morphclosecommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

MorphCloseCommand::MorphCloseCommand()
    : ACommand()
{

}

MorphCloseCommand::~MorphCloseCommand()
{
}

cv::Mat MorphCloseCommand::execute(cv::Mat image)
{
    cv::Mat elements(5,5,image.depth(),cv::Scalar(1000));
    cv::morphologyEx(image,image,cv::MORPH_CLOSE,elements);
    return image;
}

