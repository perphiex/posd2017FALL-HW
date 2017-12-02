#ifndef Iterator_H
#define Iterator_H

class Term;

class Iterator {
   public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual Term* currentItem() = 0;
};

#endif