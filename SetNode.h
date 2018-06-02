/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SetNode.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 6:33 PM
 */

#ifndef SETNODE_H
#define SETNODE_H

#include <memory>
#include "AST.h"
#include "Token.h"

class SetNode : public AST {
public:
    SetNode(Token identifier, std::unique_ptr<AST> value);
    
    Token getIdentifier();
    AST* getValue();
private:
    Token m_identifier;
    std::unique_ptr<AST> m_value;
};

#endif /* SETNODE_H */

