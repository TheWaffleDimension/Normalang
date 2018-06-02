/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 15, 2018, 10:49 AM
 */

#include "StringNode.h"

StringNode::StringNode(Token token, std::string value) {
    m_token = token;
    m_value = value;
}

std::string StringNode::getValue() {
    return m_value;
}

