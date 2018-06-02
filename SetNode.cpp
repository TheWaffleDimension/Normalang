/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SetNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 14, 2018, 6:33 PM
 */

#include "SetNode.h"

SetNode::SetNode(Token identifier, std::unique_ptr<AST> value) {
    m_identifier = identifier;
    m_value = std::move(value);
    m_token = identifier;
}

Token SetNode::getIdentifier() {
    return m_identifier;
}

AST* SetNode::getValue() {
    return m_value.get();
}

