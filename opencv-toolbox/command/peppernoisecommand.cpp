#include "peppernoisecommand.h"
#include "opencv2/core.hpp"

PepperNoiseCommand::PepperNoiseCommand()
    : ACommand()
{

}

PepperNoiseCommand::~PepperNoiseCommand()
{
}

int PepperNoiseCommand::execute(cv::Mat image)
{
    int pepperNoise = 1000;

    for (int k=0; k<pepperNoise; k++) {
        int i= rand()%image.cols;
        int j= rand()%image.rows;
        if (image.channels() == 1) {
            image.at<uchar>(j,i)= 255;
        } else if (image.channels() == 3) {
            image.at<cv::Vec3b>(j,i)[0]= 255;
            image.at<cv::Vec3b>(j,i)[1]= 255;
            image.at<cv::Vec3b>(j,i)[2]= 255;
        }
    }

    return 1;
}

