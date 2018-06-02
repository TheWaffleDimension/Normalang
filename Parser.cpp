/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.cpp
 * Author: thewaffledimension
 * 
 * Created on May 14, 2018, 4:56 PM
 */

#include <assert.h>

#include "Parser.h"

Parser::Parser(std::vector<Token> tokens)
    : m_tokens(tokens) {
    m_pos = 0;
}

Parser::Parser() {
    m_tokens = std::vector<Token>();
    m_pos = 0;
}

std::vector<std::unique_ptr<AST>>* Parser::parse() {
    while (m_pos < m_tokens.size()) {
        std::unique_ptr<AST> result = std::move(parseToken());
        if (result.get() != nullptr) {
            m_tree.push_back(std::move(result));
        }
        
        m_pos++;
    }
    
    return getTree();
}

std::vector<std::unique_ptr<AST>>* Parser::getTree() {
    return &m_tree;
}

void Parser::setTokens(std::vector<Token> tokens) {
    m_tokens = tokens;
}

std::unique_ptr<AST> Parser::parseToken() {
    Token token = m_tokens[m_pos];
    TokenType type = token.getType();
    
    switch(type) {
        case IDENTIFIER:
            return std::move(parseIdentifier());
            break;
        case FUNCTION:
            return std::move(parseFunctionDefinition());
            break;
        case WHILE:
            return std::move(parseWhile());
            break;
        case FOR:
            return std::move(parseFor());
            break;
        case REPEAT:
            return std::move(parseRepeat());
            break;
        case IF:
            return std::move(parseIf());
            break;
    }
}

std::unique_ptr<AST> Parser::parseIdentifier() {
    Token token = m_tokens[m_pos];
    Token op = m_tokens[m_pos + 1];
    if (op.getType() == TokenType::OPERATOR) {
        if (op.getFull() == "=") {
            Token value = m_tokens[m_pos + 2];
            if (value.getType() == TokenType::STRING_LITERAL || value.getType() == TokenType::NUMBER_LITERAL || value.getType() == TokenType::BOOLEAN_LITERAL || value.getType() == TokenType::IDENTIFIER) {
                switch(value.getType()) {
                    case STRING_LITERAL:
                        return std::unique_ptr<AST>(new SetNode(token, std::unique_ptr<AST>(new StringNode(value, value.getFull()))));
                        break;
                    case NUMBER_LITERAL:
                        return std::unique_ptr<AST>(new SetNode(token, std::unique_ptr<AST>(new NumberNode(value, std::stof(value.getFull())))));
                        break;
                    case BOOLEAN_LITERAL:
                        return std::unique_ptr<AST>(new SetNode(token, std::unique_ptr<AST>(new BooleanNode(value, ((value.getFull() == "true") ? true : false)))));
                        break;
                }
            }
        } else if (op.getFull() == "(") { // function call
            std::cout << "Found function call" << std::endl;
            return std::move(parseFunctionCall());
        }
    }
}

std::unique_ptr<AST> Parser::parseFunctionDefinition() {
    assert(m_tokens[m_pos].getType() == TokenType::FUNCTION);
    Token func = m_tokens[m_pos++];
    assert(m_tokens[m_pos].getType() == TokenType::IDENTIFIER);
    Token id = m_tokens[m_pos++];
    
    Token token = m_tokens[m_pos];
    
    std::vector<std::unique_ptr<AST>> arguments;
    Token tok = m_tokens[m_pos];
    while (tok.getType() != TokenType::RIGHT_PARENTHESIS && m_pos < m_tokens.size()) {
        tok = m_tokens[m_pos];
        assert(tok.getType() == TokenType::IDENTIFIER);

        arguments.push_back(std::unique_ptr<AST>(new AST(tok)));

        if ((m_tokens[m_pos + 1].getType() == TokenType::OPERATOR) && (m_tokens[m_pos + 1].getFull() == ",")) {
            m_pos += 2;
        } else if (m_tokens[m_pos + 1].getType() == TokenType::RIGHT_PARENTHESIS) {
            m_pos += 2;
            break;
        } else {
            throw std::string("Error: Expected comma at: " + tok.getPos());
        }
    }

    assert(m_tokens[m_pos++].getType() == TokenType::LEFT_BRACE);

    std::vector<std::unique_ptr<AST>> body;
    while (m_pos < m_tokens.size() && m_tokens[m_pos].getType() != TokenType::RIGHT_BRACE) {
        body.push_back(std::move(parseToken()));
        m_pos++;
    }
    
    assert(m_tokens[m_pos].getType() == TokenType::RIGHT_BRACE);
    
    Token function = Token(func.getType(), func.getPos(), id.getFull());

    return std::unique_ptr<AST>(new FunctionDefinitionNode(function, std::move(arguments), std::move(body)));
}

std::unique_ptr<AST> Parser::parseFunctionCall() {
    Token token = m_tokens[m_pos];
    
    std::vector<std::unique_ptr<AST>> arguments;
    Token tok(TokenType::NONE, 0, "");
    m_pos++;
    while (tok.getType() != TokenType::RIGHT_PARENTHESIS && m_pos < m_tokens.size()) {
        tok = m_tokens[m_pos];
        std::unique_ptr<AST> arg;
        if (tok.getType() == TokenType::IDENTIFIER) {
            arg = std::unique_ptr<AST>(new AST(tok));
        } else if (tok.getType() == TokenType::NUMBER_LITERAL) {
            arg = std::unique_ptr<AST>(new NumberNode(tok, std::stof(tok.getFull())));
        } else if (tok.getType() == TokenType::STRING_LITERAL) {
            arg = std::unique_ptr<AST>(new StringNode(tok, tok.getFull()));
        } else if (tok.getType() == TokenType::BOOLEAN_LITERAL) {

        }

        if (arg != nullptr)
            arguments.push_back(std::move(arg));

        if ((m_tokens[m_pos + 1].getType() == TokenType::OPERATOR) && (m_tokens[m_pos + 1].getFull() == ",")) {
            m_pos += 2;
        } else if (m_tokens[m_pos + 1].getType() == TokenType::RIGHT_PARENTHESIS) {
            m_pos += 2;
            break;
        } else {
            throw std::string("Error: Expected comma at: " + tok.getPos());
        }
    }

    return std::unique_ptr<AST>(new FunctionCallNode(token, std::move(arguments)));
}

std::unique_ptr<AST> Parser::parseWhile() {
    Token root = m_tokens[m_pos++];
    std::unique_ptr<AST> expression = std::move(parseExpression());
    assert(m_tokens[++m_pos].getType() == TokenType::LEFT_BRACE);
    m_pos++;
    
    std::vector<std::unique_ptr<AST>> body;
    while (m_pos < m_tokens.size() && m_tokens[m_pos].getType() != TokenType::RIGHT_BRACE) {
        body.push_back(std::move(parseToken()));
        m_pos++;
    }
    
    assert(m_tokens[m_pos].getType() == TokenType::RIGHT_BRACE);
    
    return std::unique_ptr<AST>(new WhileNode(root, std::move(expression), std::move(body)));
}

std::unique_ptr<AST> Parser::parseFor() {
    return std::unique_ptr<AST>(new AST(m_tokens[m_pos]));
}

std::unique_ptr<AST> Parser::parseRepeat() {
    return std::unique_ptr<AST>(new AST(m_tokens[m_pos]));
}

std::unique_ptr<AST> Parser::parseIf() {
    return std::unique_ptr<AST>(new AST(m_tokens[m_pos]));
}

std::unique_ptr<AST> Parser::parseExpression() {
    assert(m_tokens[m_pos++].getType() == TokenType::LEFT_PARENTHESIS);
    
    std::vector<std::unique_ptr<AST>> nodes;
    while (m_pos < m_tokens.size() && m_tokens[m_pos].getType() != TokenType::RIGHT_PARENTHESIS) {
        nodes.emplace_back(std::move(parseToken()));
        m_pos++;
    }
    
    assert(m_tokens[m_pos].getType() == TokenType::RIGHT_PARENTHESIS);
    
    return std::unique_ptr<AST>(new ExpressionNode(Token(TokenType::EXPRESSION, m_tokens[m_pos].getPos(), m_tokens[m_pos].getFull()), std::move(nodes)));
}