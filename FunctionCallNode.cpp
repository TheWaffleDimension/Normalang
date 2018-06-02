/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FunctionNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 15, 2018, 10:11 AM
 */

#include "FunctionCallNode.h"

FunctionCallNode::FunctionCallNode(Token token, std::vector<std::unique_ptr<AST>> args) {
    m_token = token;
    m_arguments = std::move(args);
}

std::vector<std::unique_ptr<AST>>* FunctionCallNode::getArguments() {
    return &m_arguments;
}
