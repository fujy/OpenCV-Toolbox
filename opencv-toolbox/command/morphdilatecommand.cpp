#include "morphdilatecommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

MorphDilateCommand::MorphDilateCommand()
    : ACommand()
{

}

MorphDilateCommand::~MorphDilateCommand()
{
}

cv::Mat MorphDilateCommand::execute(cv::Mat image)
{
    cv::dilate(image,image,cv::Mat());
    return image;
}

