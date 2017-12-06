#pragma once

class TokenInfo {
   private:
    static TokenInfo* _instance;

   protected:
    TokenInfo();

   public:
    const int NONE = -1;
    const int EOS = '\0';
    const int NUMBER = 256;
    const int ATOM = 257;
    const int ATOMSC = 258;
    const int VARIABLE = 259;
    bool isSpecialChar(char);
    static TokenInfo* getInstance();
};