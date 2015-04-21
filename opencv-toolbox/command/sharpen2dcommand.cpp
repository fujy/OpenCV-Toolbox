#include "sharpen2dcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

Sharpen2DCommand::Sharpen2DCommand()
    : ACommand()
{

}

Sharpen2DCommand::~Sharpen2DCommand()
{
}

int Sharpen2DCommand::execute(cv::Mat image)
{
    cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
    kernel.at<float>(1,1)= 5.0;
    kernel.at<float>(0,1)= -1.0;
    kernel.at<float>(2,1)= -1.0;
    kernel.at<float>(1,0)= -1.0;
    kernel.at<float>(1,2)= -1.0;
    cv::filter2D(image,image,image.depth(),kernel);
    return 1;
}

