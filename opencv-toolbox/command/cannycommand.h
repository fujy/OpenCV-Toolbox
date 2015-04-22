#ifndef CANNYCOMMAND_H
#define CannyCOMMAND_H

#include "acommand.h"

class CannyCommand : public ACommand
{
public:
    CannyCommand();
    ~CannyCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // CannyCOMMAND_H
