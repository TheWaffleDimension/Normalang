/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BooleanNode.cpp
 * Author: thewaffledimension
 * 
 * Created on May 16, 2018, 5:20 PM
 */

#include "BooleanNode.h"

BooleanNode::BooleanNode(Token token, bool value) {
    m_token = token;
    m_value = value;
}

bool BooleanNode::getValue() {
    return m_value;
}