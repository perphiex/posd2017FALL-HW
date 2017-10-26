#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>
#include <vector>
#include "term.h"
#include "variable.h"

using std::string;
using std::ostringstream;
using std::vector;

class List : public Term {
   public:
    List() : _elements() {}
    List(vector<Term*> const& elements) : _elements(elements) {}
    Term* head() const;
    List* tail() const;
    string symbol() const;
    string value() const;
    bool match(Term& term);

   protected:
    Term* elements(int) const;
    size_t size() const;

   private:
    vector<Term*> _elements;
};

#endif