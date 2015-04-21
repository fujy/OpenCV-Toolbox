#ifndef MORPHOPENCOMMAND_H
#define MORPHOPENCOMMAND_H

#include "acommand.h"

class MorphOpenCommand : public ACommand
{
public:
    MorphOpenCommand();
    ~MorphOpenCommand();
    int execute(cv::Mat image);
};

#endif // MORPHOPENCOMMAND_H
