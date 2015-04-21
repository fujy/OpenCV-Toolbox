#ifndef FLIPCOMMAND_H
#define FLIPCOMMAND_H

#include "acommand.h"

class FlipCommand : public ACommand
{
public:
    FlipCommand();
    ~FlipCommand();
    int execute(cv::Mat image);
};

#endif // FLIPCOMMAND_H
