/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExpressionNode.h
 * Author: thewaffledimension
 *
 * Created on May 16, 2018, 1:11 PM
 */

#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include <memory>
#include <vector>
#include "AST.h"
#include "Token.h"

class ExpressionNode : public AST {
public:
    ExpressionNode(Token token, std::vector<std::unique_ptr<AST>> nodes);
    
    std::vector<std::unique_ptr<AST>>* getNodes();
private:
    std::vector<std::unique_ptr<AST>> m_nodes;
};

#endif /* EXPRESSIONNODE_H */

