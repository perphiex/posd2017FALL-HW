#pragma once

#include <string>

class TokenInfo;

class Scanner {
   private:
    TokenInfo* _tokenInfo;
    std::string _buffer;
    size_t _position;
    size_t _peekPosition;

   public:
    Scanner(std::string = "");
    std::pair<std::string, int> nextToken();
    std::pair<std::string, int> peekNextToken();
    size_t peekSkipLeadingSpace();
    std::string peekAtom();
    std::string peekAtomSC();
    std::string peekNumber();
    std::string peekVariable();
    char peekCurrentChar();
    char peekChar();
    size_t skipLeadingWhiteSpace();
    std::string extractAtom();
    std::string extractAtomSC();
    std::string extractNumber();
    std::string extractVariable();
    char extractChar();
    char currentChar();
    size_t position();
};