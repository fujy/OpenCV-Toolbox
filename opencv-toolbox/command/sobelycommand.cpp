#include "sobelycommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

SobelYCommand::SobelYCommand()
    : ACommand()
{

}

SobelYCommand::~SobelYCommand()
{
}

int SobelYCommand::execute(cv::Mat image)
{
    cv::cvtColor(image,image,CV_BGR2GRAY);
    cv::Sobel(image,image,image.depth(),0,1,3,0.4,128);
    return 1;
}

