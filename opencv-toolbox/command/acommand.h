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
    virtual cv::Mat execute(cv::Mat image) = 0;
    QString CommandName();

protected:
    QString commandName;
};

#endif // ACOMMAND_H
