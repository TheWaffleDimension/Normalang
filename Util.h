/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.h
 * Author: thewaffledimension
 *
 * Created on May 16, 2018, 9:03 AM
 */

#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <fstream>

struct Files {
    static std::string readFile(std::string filepath) {
        std::ifstream inFile;
        inFile.open(filepath);
        if (!inFile) {
            std::cerr << "Unable to open file " << filepath << "!" << std::endl;
            exit(1);
        }

        std::string contents;
        std::string line;
        while (std::getline(inFile, line))
            contents = contents + "\n" + line;
        
        inFile.close();
        
        return contents;
    }
};


#endif /* UTIL_H */

