#include "global.h"

Global::Global() {}

Global* Global::_instance = nullptr;

Global* Global::getInstance() {
    if (!_instance) _instance = new Global();
    return _instance;
}

bool Global::isSpecialChar(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '<' ||
           c == '>' || c == '.' || c == '&' || c == '\\' || c == '~' ||
           c == '^' || c == '$' || c == '#' || c == '@' || c == '?' || c == ':';
}
