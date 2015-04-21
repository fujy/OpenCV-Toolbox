#include "siftcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/xfeatures2d.hpp"

#include <QInputDialog>

using namespace std;

SIFTCommand::SIFTCommand()
    : ACommand()
{

}

SIFTCommand::~SIFTCommand()
{
}

int SIFTCommand::execute(cv::Mat image)
{
    bool ok;
    int threshold = QInputDialog::getInt(0, QObject::tr("SIFT Min Hessian"),
                                         QObject::tr("Please enter SIFT min Hessian (default is 40)"), 1,
                                         1, 10000, 1, &ok);
    if (ok) {
        cv::Mat grayImage;
        cv::cvtColor(image,grayImage,CV_BGR2GRAY);

        cv::Ptr<cv::xfeatures2d::SIFT> surf= cv::xfeatures2d::SIFT::create(threshold);
        vector<cv::KeyPoint> keypoints;
        surf->detect(grayImage,keypoints);

        cv::drawKeypoints(image,keypoints,image);
    }
    return 1;
}

