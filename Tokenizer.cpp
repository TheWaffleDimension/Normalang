/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tokenizer.cpp
 * Author: thewaffledimension
 * 
 * Created on May 14, 2018, 9:01 AM
 */

#include "Tokenizer.h"
#include "Token.h"

Tokenizer::Tokenizer(std::string input) {
    m_tokens = std::vector<Token>();
    m_input = input;
    m_pos = 0;
    
    initializeTokenEnumMap();
}

void Tokenizer::setInput(std::string input) {
    m_tokens.clear();
    m_input = input;
    m_pos = 0;
}

std::vector<Token> Tokenizer::tokenize() {
    std::string tkn = "";
    char c = getChar();
    int pos = -1;
    
    bool ateWhitespace = eatWhitespace();
    std::string parsedLiteral = "";
    
    while (m_pos < m_input.length()) {
        ateWhitespace = eatWhitespace();
        c = getChar();
        parsedLiteral = "";
        
        parsedLiteral = parseSpecialToken();
        if (parsedLiteral != "" && tkn != "") {
            Token token = getToken(tkn, pos);
            if (token.getType() != TokenType::NONE) {
                m_tokens.push_back(token);
                tkn = parsedLiteral;
                pos = m_pos;
            }
        } else if (parsedLiteral != "") {
            tkn = parsedLiteral;
        }
        
        if (parsedLiteral == "") {
            if (c == '\'' || c == '"') {
                tkn = parseStringLiteral();
                parsedLiteral = "string";
            } else if (isdigit(c) || c == '.') {
                tkn = parseNumberLiteral();
                parsedLiteral = "number";
            } else {
                parsedLiteral = "";
                tkn += eat();
            }
        }
        
        if (pos == -1)
            pos = m_pos;
        
        ateWhitespace = eatWhitespace();
        if (ateWhitespace || parsedLiteral != "" || (m_pos) == m_input.length()) {
            Token token = getToken(tkn, pos);
            if (token.getType() != TokenType::NONE) {
                m_tokens.push_back(token);
                tkn = "";
                pos = -1;
            }
        }
    }
    
    return getTokens();
}

std::vector<Token> Tokenizer::getTokens() {
    return m_tokens;
}

std::string Tokenizer::parseSpecialToken() {
    std::string string = "";
    char c = getChar();
    if (mStringToToken.count(std::string(&c)) > 0) {
        string += eat();
        if (string == "=") {
            if (getChar() == '=') {
                string += eat();
            }
        } else if (string == ">") {
            if (getChar() == '=') {
                string += eat();
            }
        } else if (string == "<") {
            if (getChar() == '=') {
                string += eat();
            }
        } else if (string == "+") {
            if (getChar() == '+') {
                string += eat();
            }
        } else if (string == "-") {
            if (getChar() == '-') {
                string += eat();
            }
        }
    }
    
    return string;
}

std::string Tokenizer::parseStringLiteral() {
    std::string string = "";
    char c;
    char endChar = eat();
    string += endChar;
    
    while (m_pos < m_input.length() && c != endChar) {
        c = eat();
        string += c;
    }
    
    return string;
}

std::string Tokenizer::parseNumberLiteral() {
    std::string string = "";
    char c = getChar();
    
    while (m_pos < m_input.length() && (isdigit(c) || c == '.')) {
        c = getChar();
        if (isdigit(c) || c == '.')
            string += eat();
    }
    
    return string;
}

char Tokenizer::getChar() {
    return m_input[m_pos];
}

bool Tokenizer::eatWhitespace() {
    char c = getChar();
    bool ate = false;
    while (m_pos < m_input.length() && isspace(c)) {
        m_pos++;
        c = getChar();
        ate = true;
    }
    
    return ate;
}

char Tokenizer::eat() {
    return m_input[m_pos++];
}

Token Tokenizer::getToken(std::string text, int pos) {
//    switch (getTokenEnum(text)) {
//        case PLUS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case MINUS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case MULTIPLY:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case DIVIDE:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case MODULUS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case INCREMENT:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case DECREMENT:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case OPEN_PARENTHESIS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case CLOSE_PARENTHESIS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case OPEN_BRACE:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case CLOSE_BRACE:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case EQUAL:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case NOT:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case EQUALS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case LESS_THAN:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case GREATER_THAN:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case NOT_EQUALS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case LESS_THAN_OR_EQUALS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case GREATER_THAN_OR_EQUALS:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case DOT:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case COLON:
//            return Token(TokenType::OPERATOR, pos, text);
//            break;
//        case FUNCTION_TOKEN:
//            return Token(TokenType::FUNCTION, pos, text);
//            break;
//        case IF_TOKEN:
//            return Token(TokenType::IF, pos, text);
//            break;
//        case ELSE_TOKEN:
//            return Token(TokenType::ELSE, pos, text);
//            break;
//        case ELSEIF_TOKEN:
//            return Token(TokenType::ELSEIF, pos, text);
//            break;
//        case WHILE_TOKEN:
//            return Token(TokenType::WHILE, pos, text);
//            break;
//        case FOR_TOKEN:
//            return Token(TokenType::FOR, pos, text);
//            break;
//        case REPEAT_TOKEN:
//            return Token(TokenType::REPEAT, pos, text);
//            break;
//        case UNTIL_TOKEN:
//            return Token(TokenType::UNTIL, pos, text);
//            break;
//        case RETURN_TOKEN:
//            return Token(TokenType::RETURN, pos, text);
//            break;
//        case BREAK_TOKEN:
//            return Token(TokenType::BREAK, pos, text);
//            break;
//        case STRING:
//            return Token(TokenType::STRING_LITERAL, pos, text);
//            break;
//        case NUMBER:
//            return Token(TokenType::NUMBER_LITERAL, pos, text);
//            break;
//        case BOOLEAN:
//            return Token(TokenType::BOOLEAN_LITERAL, pos, text);
//            break;
//        case IDENTIFIER:
//            return Token(TokenType::IDENTIFIER, pos, text);
//            break;
//        default:
//            return Token(TokenType::NONE, 0, "");
//            break;
//    }
    
    return Token(getTokenEnum(text), pos, text);
}

//Tokenizer::eStringToToken Tokenizer::getTokenEnum(std::string text) {
TokenType Tokenizer::getTokenEnum(std::string text) {
    bool isNumber = true;
    bool isString = (text[0] == '\'') || (text[0] == '"');
    
    for (int i = 0; i < text.length(); i++) {
        isNumber = (isdigit(text[i])) || (text[i] == '.');
        if (!isNumber)
            break;
    }
    
    if (isNumber && !isString) {
        return TokenType::NUMBER_LITERAL;
    } else if (isString && !isNumber) {
        return TokenType::STRING_LITERAL;
    } else if ((text == "true") || (text == "false")) {
        return TokenType::BOOLEAN_LITERAL;
    } else {
        if (mStringToToken.count(text) > 0)
            return mStringToToken[text];
        else
            return TokenType::IDENTIFIER;
    }
}

void Tokenizer::initializeTokenEnumMap() {
    mStringToToken["+"] = TokenType::OPERATOR; //eStringToToken::PLUS;
    mStringToToken["-"] = TokenType::OPERATOR; //eStringToToken::MINUS;
    mStringToToken["*"] = TokenType::OPERATOR; //eStringToToken::MULTIPLY;
    mStringToToken["/"] = TokenType::OPERATOR; //eStringToToken::DIVIDE;
    mStringToToken["%"] = TokenType::OPERATOR; //eStringToToken::MODULUS;
    mStringToToken["++"] = TokenType::OPERATOR; //eStringToToken::INCREMENT;
    mStringToToken["--"] = TokenType::OPERATOR; //eStringToToken::DECREMENT;
    
    mStringToToken["("] = TokenType::LEFT_PARENTHESIS; //eStringToToken::OPEN_PARENTHESIS;
    mStringToToken[")"] = TokenType::RIGHT_PARENTHESIS; //eStringToToken::CLOSE_PARENTHESIS;
    mStringToToken["{"] = TokenType::LEFT_BRACE; //eStringToToken::OPEN_BRACE;
    mStringToToken["}"] = TokenType::RIGHT_BRACE; //eStringToToken::CLOSE_BRACE;
    
    mStringToToken["="] = TokenType::OPERATOR; ////eStringToToken::EQUAL;
    
    mStringToToken["!"] = TokenType::OPERATOR; //eStringToToken::NOT;
    mStringToToken["=="] = TokenType::OPERATOR; //eStringToToken::EQUALS;
    mStringToToken["<"] = TokenType::OPERATOR; //eStringToToken::LESS_THAN;
    mStringToToken[">"] = TokenType::OPERATOR; //eStringToToken::GREATER_THAN;
    mStringToToken["!="] = TokenType::OPERATOR; //eStringToToken::NOT_EQUALS;
    mStringToToken["<="] = TokenType::OPERATOR; //eStringToToken::LESS_THAN_OR_EQUALS;
    mStringToToken[">="] = TokenType::OPERATOR; //eStringToToken::GREATER_THAN_OR_EQUALS;
    
    mStringToToken["."] = TokenType::OPERATOR; //eStringToToken::DOT;
    mStringToToken[":"] = TokenType::OPERATOR; //eStringToToken::COLON;
    
    mStringToToken["function"] = TokenType::FUNCTION; //eStringToToken::FUNCTION_TOKEN;
    
    mStringToToken["if"] = TokenType::IF; //eStringToToken::IF_TOKEN;
    mStringToToken["else"] = TokenType::ELSE; //eStringToToken::ELSE_TOKEN;
    mStringToToken["elseif"] = TokenType::ELSEIF; //eStringToToken::ELSEIF_TOKEN;
    
    mStringToToken["while"] = TokenType::WHILE; //eStringToToken::WHILE_TOKEN;
    mStringToToken["for"] = TokenType::FOR; //eStringToToken::FOR_TOKEN;
    
    mStringToToken["repeat"] = TokenType::REPEAT; //eStringToToken::REPEAT_TOKEN;
    mStringToToken["until"] = TokenType::UNTIL; //eStringToToken::UNTIL_TOKEN;
    
    mStringToToken["return"] = TokenType::RETURN; //eStringToToken::RETURN_TOKEN;
    mStringToToken["break"] = TokenType::BREAK; //eStringToToken::BREAK_TOKEN;
}