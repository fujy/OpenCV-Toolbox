#include "surfcommand.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/xfeatures2d.hpp"

#include <QInputDialog>

using namespace std;

SURFCommand::SURFCommand()
    : ACommand()
{

}

SURFCommand::~SURFCommand()
{
}

int SURFCommand::execute(cv::Mat image)
{
    bool ok;
    int threshold = QInputDialog::getInt(0, QObject::tr("SURF Min Hessian"),
                                         QObject::tr("Please enter SURF min Hessian (default is 40)"), 1,
                                         1, 10000, 1, &ok);
    if (ok) {
        cv::Mat grayImage;
        cv::cvtColor(image,grayImage,CV_BGR2GRAY);

        cv::Ptr<cv::xfeatures2d::SURF> surf= cv::xfeatures2d::SURF::create(threshold);
        vector<cv::KeyPoint> keypoints;
        surf->detect(grayImage,keypoints);

        cv::drawKeypoints(image,keypoints,image);
    }
    return 1;
}

