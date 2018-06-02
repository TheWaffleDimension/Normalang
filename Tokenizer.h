/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tokenizer.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 9:01 AM
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include "Token.h"
#include "TokenType.h"

class Tokenizer {
public:
    Tokenizer(std::string input);
    void setInput(std::string input);
    std::vector<Token> tokenize();
    std::vector<Token> getTokens();
private:
    int m_pos;
    std::string m_input;
    std::vector<Token> m_tokens;
    
//    enum eStringToToken {
//        IDENTIFIER,
//        PLUS, MINUS, MULTIPLY, DIVIDE, MODULUS,
//        INCREMENT, DECREMENT,
//        PLUS_EQUAL, MINUS_EQUAL, MULTIPLY_EQUAL, DIVIDE_EQUAL, MODULUS_EQUAL,
//        OPEN_PARENTHESIS, CLOSE_PARENTHESIS,
//        OPEN_BRACE, CLOSE_BRACE,
//        EQUAL, NOT,
//        DOT, COLON,
//        STRING, NUMBER, BOOLEAN,
//        EQUALS, LESS_THAN, GREATER_THAN, LESS_THAN_OR_EQUALS, GREATER_THAN_OR_EQUALS, NOT_EQUALS,
//        
//        FUNCTION_TOKEN,
//        WHILE_TOKEN,
//        FOR_TOKEN,
//        REPEAT_TOKEN, UNTIL_TOKEN,
//        IF_TOKEN, THEN_TOKEN, ELSE_TOKEN, ELSEIF_TOKEN,
//        RETURN_TOKEN, BREAK_TOKEN
//    };
//    std::map<std::string, eStringToToken> mStringToToken;
    std::map<std::string, TokenType> mStringToToken;
    
    std::string parseSpecialToken();
    std::string parseStringLiteral();
    std::string parseNumberLiteral();
    
    char getChar();
    char eat();
    bool eatWhitespace();
    Token getToken(std::string text, int pos);
    
    void initializeTokenEnumMap();
    //eStringToToken getTokenEnum(std::string text);
    TokenType getTokenEnum(std::string text);
};

#endif /* TOKENIZER_H */

