#include "iterator.h"

TEST(Iterator, nullIterator){
    Atom a("a");
    Number b(1);
    Variable X("X");

    Iterator* it = a.createIterator();
    it->first();
    EXPECT_EQ("a", it->currentItem()->symbol());
    it->next();
    EXPECT_EQ(true, it->isDone());

    it = b.createIterator();
    it->first();
    EXPECT_EQ("1", it->currentItem()->symbol());
    it->next();
    EXPECT_EQ(true, it->isDone());

    it = X.createIterator();
    it->first();
    EXPECT_EQ("X", it->currentItem()->symbol());
    it->next();
    EXPECT_EQ(true, it->isDone());
}
