#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "term.h"

using std::string;

class Number : public Term
{
  public:
    Number(int);
};

#endif
