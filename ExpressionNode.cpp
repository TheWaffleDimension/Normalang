/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExpressionNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 16, 2018, 1:11 PM
 */

#include "ExpressionNode.h"

ExpressionNode::ExpressionNode(Token token, std::vector<std::unique_ptr<AST>> nodes) {
    m_token = token;
    m_nodes = std::move(nodes);
}

std::vector<std::unique_ptr<AST>>* ExpressionNode::getNodes() {
    return &m_nodes;
}