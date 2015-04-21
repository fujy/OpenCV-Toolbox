#ifndef SURFCOMMAND_H
#define SURFCOMMAND_H

#include "acommand.h"

class SURFCommand : public ACommand
{
public:
    SURFCommand();
    ~SURFCommand();
    int execute(cv::Mat image);
};

#endif // SURFCOMMAND_H
