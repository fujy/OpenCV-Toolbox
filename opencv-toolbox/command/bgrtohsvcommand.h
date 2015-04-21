#ifndef BGRTOHSVCOMMAND_H
#define BGRTOHSVCOMMAND_H

#include "acommand.h"

class BGRToHSVCommand : public ACommand
{
public:
    BGRToHSVCommand();
    ~BGRToHSVCommand();
    int execute(cv::Mat image);
};

#endif // BGRTOHSVCOMMAND_H
