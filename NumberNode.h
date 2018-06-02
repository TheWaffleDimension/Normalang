/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberNode.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 5:20 PM
 */

#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include <memory>
#include "AST.h"
#include "Token.h"

class NumberNode : public AST {
public:
    NumberNode(Token token, float value);
    
    float getValue();
private:
    float m_value;
};

#endif /* NUMBERNODE_H */

