#ifndef MORPHCLOSECOMMAND_H
#define MORPHCLOSECOMMAND_H

#include "acommand.h"

class MorphCloseCommand : public ACommand
{
public:
    MorphCloseCommand();
    ~MorphCloseCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // MORPHCLOSECOMMAND_H
