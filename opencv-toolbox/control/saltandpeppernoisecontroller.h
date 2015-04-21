#ifndef SALTANDPEPPERNOISECONTROLLER_H
#define SALTANDPEPPERNOISECONTROLLER_H

namespace cv {
class Mat;
}

class SaltAndPepperNoiseController
{

private:
    SaltAndPepperNoiseController();
    ~SaltAndPepperNoiseController();

    void salt(cv::Mat &image, int n);

public:
    static SaltAndPepperNoiseController *getInstance();

    // Creates the instance at first call
    bool apply(cv::Mat &image);
};

#endif // SALTANDPEPPERNOISECONTROLLER_H
