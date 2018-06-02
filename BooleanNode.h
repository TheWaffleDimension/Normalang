/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BooleanNode.h
 * Author: thewaffledimension
 *
 * Created on May 16, 2018, 5:20 PM
 */

#ifndef BOOLEANNODE_H
#define BOOLEANNODE_H

#include "AST.h"
#include "Token.h"

class BooleanNode : public AST {
public:
    BooleanNode(Token token, bool value);
    
    bool getValue();
private:
    bool m_value;
};

#endif /* BOOLEANNODE_H */

