#include "tokenInfo.h"
#include "scanner.h"

Scanner::Scanner(std::string in)
    : _tokenInfo(TokenInfo::getInstance()), _buffer(in), _position(0) {}

size_t Scanner::skipLeadingWhiteSpace() {
    for (; (_position < _buffer.length() && _buffer[_position] == ' ') ||
           _buffer[_position] == '\t';
         _position++)
        ;
    return _position;
}

std::string Scanner::extractNumber() {
    int begin = _position;
    bool hasDot = false;
    for (; isdigit(_buffer[_position]) ||
           (!hasDot && (hasDot = _buffer[_position] == '.'));
         _position++)
        ;
    return _buffer.substr(begin, _position - begin);
}

std::string Scanner::extractAtom() {
    int begin = _position;
    for (; isalnum(_buffer[_position]); _position++)
        ;
    return _buffer.substr(begin, _position - begin);
}

std::string Scanner::extractAtomSC() {
    int begin = _position;
    for (; _tokenInfo->isSpecialChar(_buffer[_position]); _position++)
        ;
    return _buffer.substr(begin, _position - begin);
}

std::string Scanner::extractVariable() {
    int begin = position();
    for (; isalnum(_buffer[_position]) || _buffer[_position] == '_';
         _position++)
        ;
    return _buffer.substr(begin, _position - begin);
}

char Scanner::extractChar() { return _buffer[_position++]; }

char Scanner::currentChar() { return _buffer[_position]; }

size_t Scanner::position() { return _position; }

std::pair<std::string, int> Scanner::nextToken() {
    if (skipLeadingWhiteSpace() >= _buffer.length())
        return std::pair<std::string, int>("", _tokenInfo->EOS);
    else if (isdigit(currentChar()))
        return std::pair<std::string, int>(extractNumber(), _tokenInfo->NUMBER);
    else if (islower(currentChar()))
        return std::pair<std::string, int>(extractAtom(), _tokenInfo->ATOM);
    else if (_tokenInfo->isSpecialChar(currentChar()))
        return std::pair<std::string, int>(extractAtomSC(), _tokenInfo->ATOMSC);
    else if (isupper(currentChar()) || currentChar() == '_')
        return std::pair<std::string, int>(extractVariable(),
                                           _tokenInfo->VARIABLE);
    else {
        char c = extractChar();
        return std::pair<std::string, int>(std::string(1, c), c);
    }
}