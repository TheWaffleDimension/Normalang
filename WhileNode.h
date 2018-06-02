/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WhileNode.h
 * Author: thewaffledimension
 *
 * Created on May 16, 2018, 12:44 PM
 */

#ifndef WHILENODE_H
#define WHILENODE_H

#include <memory>
#include <vector>
#include "AST.h"
#include "Token.h"

class WhileNode : public AST {
public:
    WhileNode(Token token, std::unique_ptr<AST> expression, std::vector<std::unique_ptr<AST>> body);
    
    AST* getExpression();
    std::vector<std::unique_ptr<AST>>* getBody();
private:
    std::unique_ptr<AST> m_expression;
    std::vector<std::unique_ptr<AST>> m_body;
};

#endif /* WHILENODE_H */

