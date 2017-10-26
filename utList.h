#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using std::string;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST(List, constructor) {
    List list;
    EXPECT_EQ("[]", list.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
    Number pn1(496);
    Number pn2(8128);
    vector<Term*> v = {&pn1, &pn2};
    List list(v);
    ASSERT_EQ("[496, 8128]", list.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao,
// alan_mathison_turing]"
TEST(List, Atoms) {
    Atom terence_tao("terence_tao");
    Atom alan_mathison_turing("alan_mathison_turing");
    vector<Term*> v = {&terence_tao, &alan_mathison_turing};
    List list(v);
    ASSERT_EQ("[terence_tao, alan_mathison_turing]", list.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
    Variable X("X");
    Variable Y("Y");
    vector<Term*> v = {&X, &Y};
    List list(v);
    ASSERT_EQ("[X, Y]", list.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
    Atom tom("tom");
    Atom terence_tao("terence_tao");
    Number n1(496);
    Variable X("X");
    vector<Term*> v = {&n1, &X, &terence_tao};
    List list(v);
    ASSERT_FALSE(tom.match(list));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    List list(v);
    Number pn2(8128);
    EXPECT_FALSE(pn2.match(list));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    List list(v);
    vector<Term*> v2 = {&X};
    Struct s(Atom("s"), v);
    EXPECT_FALSE(s.match(list));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    List list(v);
    Variable Y("Y");
    EXPECT_TRUE(Y.match(list));
    EXPECT_EQ("[496, X, terence_tao]", Y.value());
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    List list(v);
    EXPECT_TRUE(X.match(list));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    List list(v);
    List list2(v);
    EXPECT_TRUE(list.match(list2));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    Variable Y("Y");
    vector<Term*> v2 = {&pn1, &Y, &terence_tao};
    List list(v);
    List list2(v2);
    EXPECT_TRUE(list.match(list2));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    List list(v);
    Number pn2(8128);
    vector<Term*> v2 = {&pn1, &pn2, &terence_tao};
    List list2(v2);
    EXPECT_TRUE(list.match(list2));
    EXPECT_EQ("8128", X.value());
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
    Number pn1(496);
    Variable X("X");
    Atom terence_tao("terence_tao");
    vector<Term*> v = {&pn1, &X, &terence_tao};
    List list(v);
    Variable Y("Y");
    Atom alan_mathison_turing("alan_mathison_turing");
    EXPECT_TRUE(Y.match(list));
    EXPECT_TRUE(X.match(alan_mathison_turing));
    EXPECT_EQ("[496, alan_mathison_turing, terence_tao]", Y.value());
    EXPECT_EQ("alan_mathison_turing", X.value());
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
    Atom f("first"), s("second"), t("third");
    vector<Term*> args = {&f, &s, &t};
    List l(args);

    EXPECT_EQ(string("first"), l.head()->symbol());
    EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
    Atom f("first"), s("second"), t("third");
    vector<Term*> args = {&f, &s, &t};
    List l(args);

    EXPECT_EQ(string("second"), l.tail()->head()->value());
    EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
    Atom f("first"), s("second"), t("third");
    vector<Term*> v1 = {&f};
    List l1(v1);
    vector<Term*> v2 = {&l1, &s, &t};
    List l2(v2);

    EXPECT_EQ("[first]", l2.head()->value());
    EXPECT_EQ("[second, third]", l2.tail()->value());
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
    Atom f("first"), s("second"), t("third");
    vector<Term*> v = {&f, &s, &t};
    List l(v);

    EXPECT_EQ("third", l.tail()->tail()->head()->value());
    EXPECT_EQ("[]", l.tail()->tail()->tail()->value());
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an
// exception.
TEST(List, emptyExecptionOfHead) {
    List l;

    ASSERT_THROW(l.head(), string);
    try {
        l.head();
    } catch (string s) {
        EXPECT_EQ("Accessing head in an empty list", s);
    }
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an
// exception.
TEST(List, emptyExecptionOfTail) {
    List l;

    ASSERT_THROW(l.tail(), string);
    try {
        l.tail();
    } catch (string s) {
        EXPECT_EQ("Accessing tail in an empty list", s);
    }
}

#endif