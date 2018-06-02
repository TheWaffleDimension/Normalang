/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenType.h
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 11:56 AM
 */

#ifndef TOKENTYPE_H
#define TOKENTYPE_H

enum TokenType {
    NONE, IDENTIFIER, OPERATOR,
    NUMBER_LITERAL, STRING_LITERAL, BOOLEAN_LITERAL,
    FUNCTION,
    IF, ELSE, ELSEIF,
    EXPRESSION,
    
    WHILE, FOR,
    REPEAT, UNTIL,
    RETURN, BREAK,
    
    LEFT_PARENTHESIS, RIGHT_PARENTHESIS,
    LEFT_BRACE, RIGHT_BRACE
};

#endif /* TOKENTYPE_H */

