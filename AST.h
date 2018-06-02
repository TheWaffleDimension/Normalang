/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 4:58 PM
 */

#ifndef NODE_H
#define NODE_H

#include "Token.h"


class AST {
public:
    inline AST() {};
    inline AST(Token token) : m_token(token) {};
    
    inline Token& getToken() { return m_token; };
protected:
    Token m_token;
};

#endif /* NODE_H */

