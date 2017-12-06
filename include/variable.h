#pragma once

#include <string>
class Term;

class Variable : public Term {
   private:
    std::string _symbol;
    Term* _instance = nullptr;

   public:
    Variable(std::string);
    std::string symbol();
    std::string value();
    bool match(Term&);
    Variable* getVariable();
};
