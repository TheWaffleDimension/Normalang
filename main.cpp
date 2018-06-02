/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: thewaffledimension
 *
 * Created on May 14, 2018, 8:35 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Token.h"
#include "Tokenizer.h"
#include "AST.h"
#include "Parser.h"
#include "Util.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tokenizer tokenizer("");
    Parser parser = Parser();
    
    if (argc >= 2) {
        std::string input = Files::readFile(argv[1]);
        
        std::cout << input << std::endl;
        
        tokenizer.setInput(input);
        std::vector<Token> tokens = tokenizer.tokenize();
        
        for (Token token : tokens ) {
            std::cout << "::TOKEN::" << std::endl;
            std::cout << "\tFull: " << token.getFull() << std::endl;
            std::cout << "\tPosition: " << token.getPos() << std::endl;
            std::cout << "\tType: " << token.getType() << std::endl;
        }

        std::cout << "--------------------------" << std::endl;
        
        parser.setTokens(tokens);
        
        std::vector<std::unique_ptr<AST>>* parseTree = std::move(parser.parse());
        for (int i = 0; i < parseTree->size(); i++) {
            AST* node = parseTree->at(i).get();
            if (node != nullptr) {
                Token& token = node->getToken();
                std::cout << token.getFull() << std::endl;
            } else {
                break;
            }
        }
    } else {
        std::cout << "CL REPL" << std::endl;
        std::cout << "Run \"::q\" to quit." << std::endl;
        std::string input = "";
        std::cout << "> ";
        while (getline(std::cin, input) && input != "::q") {
            std::cout << "> ";
            std::cout << input << std::endl;
            tokenizer.setInput(input);
            std::vector<Token> tokens = tokenizer.tokenize();
    
            for (Token token : tokens ) {
                std::cout << "::TOKEN::" << std::endl;
                std::cout << "\tFull: " << token.getFull() << std::endl;
                std::cout << "\tPosition: " << token.getPos() << std::endl;
                std::cout << "\tType: " << token.getType() << std::endl;
            }
            
            std::cout << "--------------------------" << std::endl;
    
            parser.setTokens(tokens);
            std::vector<std::unique_ptr<AST>>* abstractSyntaxTree = parser.parse();
            for (int i = 0; i < abstractSyntaxTree->size(); i++) {
                AST* node = abstractSyntaxTree->at(i).get();
                std::cout << node->getToken().getFull() << std::endl;
            }
        }
    }
    
    return 0;
}

