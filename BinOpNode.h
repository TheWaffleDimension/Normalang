/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinOpNode.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 5:08 PM
 */

#ifndef BINOPNODE_H
#define BINOPNODE_H

#include <memory>
#include "Token.h"
#include "AST.h"

class BinOpNode : public AST {
public:
    BinOpNode(std::unique_ptr<AST> left, Token op, std::unique_ptr<AST> right);
    
    AST* getLeft();
    Token getOp();
    AST* getRight();
private:
    std::unique_ptr<AST> m_left;
    Token m_op;
    std::unique_ptr<AST> m_right;
};

#endif /* BINOPNODE_H */

