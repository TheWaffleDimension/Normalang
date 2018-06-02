/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FunctionDefinitionNode.h
 * Author: thewaffledimension
 *
 * Created on May 16, 2018, 3:11 PM
 */

#ifndef FUNCTIONDEFINITIONNODE_H
#define FUNCTIONDEFINITIONNODE_H

#include <memory>
#include <vector>
#include "AST.h"
#include "Token.h"

class FunctionDefinitionNode : public AST {
public:
    FunctionDefinitionNode(Token token, std::vector<std::unique_ptr<AST>> args, std::vector<std::unique_ptr<AST>> body);
    
    std::vector<std::unique_ptr<AST>>* getArguments();
    std::vector<std::unique_ptr<AST>>* getBody();
private:
    std::vector<std::unique_ptr<AST>> m_arguments;
    std::vector<std::unique_ptr<AST>> m_body;
};

#endif /* FUNCTIONDEFINITIONNODE_H */

