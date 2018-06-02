/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringNode.h
 * Author: thewaffledimension
 *
 * Created on May 15, 2018, 10:49 AM
 */

#ifndef STRINGNODE_H
#define STRINGNODE_H

#include <string>
#include <memory>
#include "AST.h"
#include "Token.h"

class StringNode : public AST {
public:
    StringNode(Token token, std::string value);
    
    std::string getValue();
private:
    std::string m_value;

};

#endif /* STRINGNODE_H */

