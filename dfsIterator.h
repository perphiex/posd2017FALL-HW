#ifndef DFSITERATOR_H
#define DFSITERATOR_H

#include <stack>
#include "iterator.h"
#include "term.h"

class DFSIterator : public Iterator {
 public:
  DFSIterator(Term*);
  void first();
  void next();
  bool isDone();
  Term* currentItem();

 private:
  std::stack<Iterator*> _iteratorStack;
  std::stack<Term*> _termStack;
  Term* _term;
};

#endif