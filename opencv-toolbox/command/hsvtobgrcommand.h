#ifndef HSVTOBGRCOMMAND_H
#define HSVTOBGRCOMMAND_H

#include "acommand.h"

class HSVToBGRCommand : public ACommand
{
public:
    HSVToBGRCommand();
    ~HSVToBGRCommand();
    cv::Mat execute(cv::Mat image);
};

#endif // HSVTOBGRCOMMAND_H
