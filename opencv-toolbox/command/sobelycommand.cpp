#include "sobelycommand.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

SobelYCommand::SobelYCommand()
    : ACommand()
{

}

SobelYCommand::~SobelYCommand()
{
}

cv::Mat SobelYCommand::execute(cv::Mat image)
{
    cv::cvtColor(image,image,CV_BGR2GRAY);
    cv::Sobel(image,image,image.depth(),0,1,3,0.4,128);
//    cv::imshow("Sobel",image);
    return image;
}

