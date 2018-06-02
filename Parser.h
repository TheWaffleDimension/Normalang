/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 4:56 PM
 */

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "AST.h"
#include "BinOpNode.h"
#include "NumberNode.h"
#include "StringNode.h"
#include "BooleanNode.h"
#include "ExpressionNode.h"
#include "FunctionDefinitionNode.h"
#include "FunctionCallNode.h"
#include "SetNode.h"
#include "WhileNode.h"
#include "Token.h"
#include "TokenType.h"

class Parser {
public:
    Parser();
    Parser(std::vector<Token> tokens);
    std::vector<std::unique_ptr<AST>>* parse();
    
    std::vector<std::unique_ptr<AST>>* getTree();
    
    void setTokens(std::vector<Token> tokens);
    
private:
    int m_pos;
    std::vector<Token> m_tokens;
    std::vector<std::unique_ptr<AST>> m_tree;
    
    std::unique_ptr<AST> parseToken();
    std::unique_ptr<AST> parseIdentifier();
    std::unique_ptr<AST> parseOperator();
    std::unique_ptr<AST> parseFunctionDefinition();
    std::unique_ptr<AST> parseFunctionCall();
    std::unique_ptr<AST> parseWhile();
    std::unique_ptr<AST> parseFor();
    std::unique_ptr<AST> parseRepeat();
    std::unique_ptr<AST> parseIf();
    std::unique_ptr<AST> parseExpression();
    
};

#endif /* PARSER_H */

