#ifndef GLOBAL_H
#define GLOBAL_H

#include "atom.h"

class Global {
   protected:
    Global();

   private:
    static Global* _instance;

   public:
    const int NONE = -1;
    const int EOS = '\0';
    const int NUMBER = 256;
    const int ATOM = 257;
    const int ATOMSC = 258;
    const int VARIABLE = 259;
    Atom EMPTY_LIST = Atom("[]");
    static Global* getInstance();
    bool isSpecialChar(char c);
};

#endif