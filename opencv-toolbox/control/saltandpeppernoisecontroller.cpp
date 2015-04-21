#include "saltandpeppernoisecontroller.h"

#include <opencv2/opencv.hpp>
#include <model/properties.h>

static SaltAndPepperNoiseController *singleton = 0;

SaltAndPepperNoiseController::SaltAndPepperNoiseController()
{

}

SaltAndPepperNoiseController::~SaltAndPepperNoiseController()
{

}

SaltAndPepperNoiseController* SaltAndPepperNoiseController::getInstance()
{
    if (singleton == 0)
        singleton = new SaltAndPepperNoiseController();
    return singleton;
}

bool SaltAndPepperNoiseController::apply(cv::Mat &image)
{
    salt(image,Properties::SaltAndPepperNoise());
    return 1;
}

void SaltAndPepperNoiseController::salt(cv::Mat &image, int n) {
    for (int k=0; k<n; k++) {
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
}
