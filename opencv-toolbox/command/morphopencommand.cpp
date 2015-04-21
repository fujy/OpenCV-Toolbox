#include "morphopencommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

MorphOpenCommand::MorphOpenCommand()
    : ACommand()
{

}

MorphOpenCommand::~MorphOpenCommand()
{
}

int MorphOpenCommand::execute(cv::Mat image)
{
    cv::Mat elements(5,5,image.depth(),cv::Scalar(1000));
    cv::morphologyEx(image,image,cv::MORPH_OPEN, elements);
    return 1;
}

