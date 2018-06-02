/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FunctionDefinitionNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 16, 2018, 3:11 PM
 */

#include "FunctionDefinitionNode.h"

FunctionDefinitionNode::FunctionDefinitionNode(Token token, std::vector<std::unique_ptr<AST>> args, std::vector<std::unique_ptr<AST>> body) {
    m_token = token;
    m_arguments = std::move(args);
    m_body = std::move(body);
}

std::vector<std::unique_ptr<AST>>* FunctionDefinitionNode::getArguments() {
    return &m_arguments;
}

std::vector<std::unique_ptr<AST>>* FunctionDefinitionNode::getBody() {
    return &m_body;
}

