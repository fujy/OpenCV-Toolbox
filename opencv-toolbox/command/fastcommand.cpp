#include "fastcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/xfeatures2d.hpp"

#include <QInputDialog>
#include <QObject>

using namespace std;

FASTCommand::FASTCommand()
    : ACommand()
{

}

FASTCommand::~FASTCommand()
{
}

int FASTCommand::execute(cv::Mat image)
{
    bool ok;
    int threshold = QInputDialog::getInt(0,QObject::tr("FAST Threshold"),
                                         QObject::tr("Please enter FAST Threshold (default is 40)"),
                                         1, 1, 1000, 1, &ok);
    if (ok)
    {
        cv::Mat grayImage;
        cv::cvtColor(image,grayImage,CV_BGR2GRAY);

        cv::Ptr<cv::FastFeatureDetector> fast = cv::FastFeatureDetector::create(threshold);
        vector<cv::KeyPoint> keypoints;
        fast->detect(grayImage,keypoints);

        cv::drawKeypoints(image,keypoints,image);
    }
    return 1;
}

