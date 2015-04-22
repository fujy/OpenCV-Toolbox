#ifndef LAPLACIANCOMMAND_H
#define LAPLACIANCOMMAND_H

#include "acommand.h"

class LaplacianCommand : public ACommand
{
public:
    LaplacianCommand();
    ~LaplacianCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // LAPLACIANCOMMAND_H
