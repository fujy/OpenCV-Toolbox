#ifndef BGRTOGRAYCOMMAND_H
#define BGRTOGRAYCOMMAND_H

#include "acommand.h"

class BGRToGrayCommand : public ACommand
{
public:
    BGRToGrayCommand();
    ~BGRToGrayCommand();
    int execute(cv::Mat image);
};

#endif // BGRTOGRAYCOMMAND_H
