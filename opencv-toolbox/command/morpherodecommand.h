#ifndef MORPHERODECOMMAND_H
#define MORPHERODECOMMAND_H

#include "acommand.h"

class MorphErodeCommand : public ACommand
{
public:
    MorphErodeCommand();
    ~MorphErodeCommand();
    int execute(cv::Mat image);
};

#endif // MORPHERODECOMMAND_H
