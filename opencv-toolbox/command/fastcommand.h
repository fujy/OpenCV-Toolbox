#ifndef FASTCOMMAND_H
#define FASTCOMMAND_H

#include "acommand.h"

class FASTCommand : public ACommand
{
public:
    FASTCommand();
    ~FASTCommand();
    int execute(cv::Mat image);
};

#endif // FASTCOMMAND_H
