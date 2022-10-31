//
// Created by jorge on 28/10/2022.
//

#ifndef HEXAGON_CORE_EXCEPTION_H
#define HEXAGON_CORE_EXCEPTION_H

#include <exception>

class Core_Exception: public std:: runtime_error {
public:
public:
    explicit Core_Exception(const std::string& msg):runtime_error(msg.c_str()){}
};

#endif //HEXAGON_CORE_EXCEPTION_H
