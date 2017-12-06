#pragma once

#include <string>
class Term;

class Number : public Term {
   private:
    double _value;
    std::string getString();

   public:
    Number(double);
    std::string symbol();
    std::string value();
    bool match(Term&);
    Number* getNumber();
};
