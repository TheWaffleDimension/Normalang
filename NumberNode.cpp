/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 14, 2018, 5:20 PM
 */

#include "NumberNode.h"

NumberNode::NumberNode(Token token, float value)
    : m_value(value) {
    m_token = token;
}

float NumberNode::getValue() {
    return m_value;
}