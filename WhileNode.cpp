/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WhileNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 16, 2018, 12:44 PM
 */

#include "WhileNode.h"

WhileNode::WhileNode(Token token, std::unique_ptr<AST> expression, std::vector<std::unique_ptr<AST>> body) {
    m_token = token;
    m_expression = std::move(expression);
    m_body = std::move(body);
}

AST* WhileNode::getExpression() {
    return m_expression.get();
}

std::vector<std::unique_ptr<AST>>* WhileNode::getBody() {
    return &m_body;
}

