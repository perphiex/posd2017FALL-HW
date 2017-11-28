#ifndef TERMITERATOR_H
#define TERMITERATOR_H

class Term;

class TermIterator {
   public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual Term* CurrentItem() = 0;
};

#endif