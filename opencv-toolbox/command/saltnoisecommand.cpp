#include "saltnoisecommand.h"
#include "opencv2/core.hpp"

SaltNoiseCommand::SaltNoiseCommand()
    : ACommand()
{

}

SaltNoiseCommand::~SaltNoiseCommand()
{
}

cv::Mat SaltNoiseCommand::execute(cv::Mat image)
{
    int saltNoise = 1000;

    for (int k=0; k<saltNoise; k++) {
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

    return image;
}

