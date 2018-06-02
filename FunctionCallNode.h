/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FunctionNode.h
 * Author: thewaffledimension
 *
 * Created on May 15, 2018, 10:11 AM
 */

#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include <memory>
#include <vector>
#include "AST.h"

class FunctionCallNode : public AST {
public:
    FunctionCallNode(Token token, std::vector<std::unique_ptr<AST>> args);
    
    std::vector<std::unique_ptr<AST>>* getArguments();
private:
    std::vector<std::unique_ptr<AST>> m_arguments;
};

#endif /* FUNCTIONNODE_H */

