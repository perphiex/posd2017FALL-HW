#pragma once

#include <vector>
#include <stack>
#include <map>

class Term;
class Atom;
class Node;

class Scanner;
class TokenInfo;

class Parser {
   private:
    Scanner* _scanner;
    TokenInfo* _tokenInfo;
    std::pair<std::string, size_t> _currentToken;

    std::vector<Term*> _terms;
    std::map<std::string, Term*> _symbolTable;
    Node* _tree;
    Term* createStruct(Atom*);
    Term* createAtomOrStruct();
    Term* createList();
    Term* actualCreateTerm();
    std::vector<Term*> getArgs();
    bool isEndOfStruct();

   public:
    Parser(Scanner&);
    Term* createTerm();
    void createTerms();
    std::vector<Term*> getTerms();

    void matchings();
    Node* expressionTree();
};
