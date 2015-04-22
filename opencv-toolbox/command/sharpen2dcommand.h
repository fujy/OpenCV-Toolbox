#ifndef SHARPEN2DCOMMAND_H
#define SHARPEN2DCOMMAND_H

#include "acommand.h"

class Sharpen2DCommand : public ACommand
{
public:
    Sharpen2DCommand();
    ~Sharpen2DCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // SHARPEN2DCOMMAND_H
