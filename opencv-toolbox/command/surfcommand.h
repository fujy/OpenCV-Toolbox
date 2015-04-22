#ifndef SURFCOMMAND_H
#define SURFCOMMAND_H

#include "acommand.h"

class SURFCommand : public ACommand
{
public:
    SURFCommand();
    ~SURFCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // SURFCOMMAND_H
