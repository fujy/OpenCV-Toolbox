#include "laplaciancommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

LaplacianCommand::LaplacianCommand()
    : ACommand()
{

}

LaplacianCommand::~LaplacianCommand()
{
}

cv::Mat LaplacianCommand::execute(cv::Mat image)
{
    int aperture = 3;
    cv::GaussianBlur(image,image,cv::Size(5,5),1.5);
    cv::cvtColor(image,image,CV_BGR2GRAY);
    cv::Laplacian(image,image,image.depth(),aperture);
    cv::convertScaleAbs( image, image );
    return image;
}

