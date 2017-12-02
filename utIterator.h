#include <iostream>


#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"

#include "nullIterator.h"
#include "listIterator.h"
#include "structIterator.h"
#include "dfsIterator.h"

TEST(Iterator, nullIterator) {
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

TEST(Iterator, structIterator) {
  Atom a("a");
  Number b(1);
  Variable X("X");
  Struct s(Atom("s"), {&a, &b, &X});
  Iterator* it = s.createIterator();
  it->first();
  EXPECT_EQ(false, it->isDone());
  EXPECT_EQ("a", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ(false, it->isDone());
  EXPECT_EQ("1", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ(false, it->isDone());
  EXPECT_EQ("X", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ(true, it->isDone());
}

TEST(Iterator, listIterator) {
  Atom a("a");
  Number b(1);
  Variable X("X");
  List l(&a, new List(&b, new List(&X, new List())));
  Iterator* it = l.createIterator();
  it->first();
  EXPECT_EQ(false, it->isDone());
  EXPECT_EQ("a", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ(false, it->isDone());
  EXPECT_EQ("1", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ(false, it->isDone());
  EXPECT_EQ("X", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ(true, it->isDone());
}

// TEST(Iterator, structDFSIterator) {
//   Struct s(Atom("s"), {new Struct(Atom("a"), {new Atom("b"), new Atom("c")}),
//                        new Struct(Atom("d"), {new Atom("e"), new Atom("f")}),
//                        new Struct(Atom("g"), {new Atom("h"), new
//                        Atom("i")})});
//   Iterator* it = s.createDFSIterator();
//   it->first();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("a(b, c)", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("b", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("c", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("d(e, f)", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("e", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("f", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("g(h, i)", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("h", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(false, it->isDone());
//   EXPECT_EQ("i", it->currentItem()->symbol());
//   it->next();

//   EXPECT_EQ(true, it->isDone());
// }
