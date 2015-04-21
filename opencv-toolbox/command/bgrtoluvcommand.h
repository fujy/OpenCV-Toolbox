#ifndef BGRTOLUVCOMMAND_H
#define BGRTOLUVCOMMAND_H

#include "acommand.h"

class BGRToLUVCommand : public ACommand
{
public:
  BGRToLUVCommand();
  ~BGRToLUVCommand();
  int execute(cv::Mat image);
};

#endif // BGRTOLUVCOMMAND_H
