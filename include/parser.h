#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <utility>
#include <stack>
#include <map>
#include "scanner.h"
#include "tokenInfo.h"
#include "term.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"
#include "node.h"

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

#endif