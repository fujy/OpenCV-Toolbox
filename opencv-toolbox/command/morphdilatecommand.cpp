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

int MorphDilateCommand::execute(cv::Mat image)
{
    cv::dilate(image,image,cv::Mat());
    return 1;
}

