/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 9:02 AM
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "TokenType.h"

class Token {
public:
    inline Token() {
        m_type = TokenType::NONE;
        m_pos = 0;
        m_full = "";
    };
    
    inline Token(TokenType type, int pos, std::string full) {
        m_type = type;
        m_pos = pos;
        m_full = full;
    };
    
    inline TokenType& getType() { return m_type; };
    inline int& getPos() { return m_pos; };
    inline std::string& getFull() { return m_full; };
private:
    TokenType m_type;
    int m_pos;
    std::string m_full;
};

#endif /* TOKEN_H */

