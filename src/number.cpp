#include "../include/number.h"

Number::Number(int value)
{
    _value = std::to_string(value);
    _symbol = std::to_string(value);
}
