#ifndef MORPHDILATECOMMAND_H
#define MORPHDILATECOMMAND_H

#include "acommand.h"

class MorphDilateCommand : public ACommand
{
public:
    MorphDilateCommand();
    ~MorphDilateCommand();
    int execute(cv::Mat image);
};

#endif // MORPHDILATECOMMAND_H
