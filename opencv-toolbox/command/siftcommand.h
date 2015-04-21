#ifndef SIFTCOMMAND_H
#define SIFTCOMMAND_H

#include "acommand.h"

class SIFTCommand : public ACommand
{
public:
    SIFTCommand();
    ~SIFTCommand();
    int execute(cv::Mat image);
};

#endif // SIFTCOMMAND_H
