#ifndef MORPHCLOSECOMMAND_H
#define MORPHCLOSECOMMAND_H

#include "acommand.h"

class MorphCloseCommand : public ACommand
{
public:
    MorphCloseCommand();
    ~MorphCloseCommand();
    int execute(cv::Mat image);
};

#endif // MORPHCLOSECOMMAND_H
