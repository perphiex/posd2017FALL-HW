#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <utility>
#include "global.h"
using std::pair;
using std::string;

class Scanner {
   private:
    Global* _global;
    string _buffer;
    int _position;

   public:
    Scanner(string = "");
    pair<string, int> nextToken();
    int skipLeadingWhiteSpace();
    string extractNumber();
    string extractAtom();
    string extractAtomSC();
    string extractVariable();
    char extractChar();
    char currentChar();
    int position();
};

#endif
