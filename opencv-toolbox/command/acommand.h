#ifndef ACOMMAND_H
#define ACOMMAND_H

#include <QObject>

namespace cv {
class Mat;
}

class ACommand
{

public:
    ACommand();
    virtual ~ACommand();
    virtual int execute(cv::Mat image) = 0;
};

#endif // ACOMMAND_H
