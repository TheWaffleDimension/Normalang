/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinOpNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 14, 2018, 5:08 PM
 */

#include "BinOpNode.h"

BinOpNode::BinOpNode(std::unique_ptr<AST> left, Token op, std::unique_ptr<AST> right)
    : m_left(std::move(left)), m_op(op), m_right(std::move(right)) {
        m_token = op;
}

AST* BinOpNode::getLeft() {
    return m_left.get();
}

AST* BinOpNode::getRight() {
    return m_right.get();
}

Token BinOpNode::getOp() {
    return m_op;
}
