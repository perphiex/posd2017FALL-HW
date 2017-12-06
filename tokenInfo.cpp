#include "tokenInfo.h"

TokenInfo::TokenInfo() {}
TokenInfo* TokenInfo::_instance = nullptr;

TokenInfo* TokenInfo::getInstance() {
    if (_instance) return _instance;
    _instance = new TokenInfo();
    return _instance;
}

bool TokenInfo::isSpecialChar(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '<' ||
           c == '>' || c == '.' || c == '&' || c == '\\' || c == '~' ||
           c == '^' || c == '$' || c == '#' || c == '@' || c == '?' || c == ':';
}