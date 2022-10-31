//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_SDL_EXCEPTION_H
#define HEXAGON_SDL_EXCEPTION_H


#include <exception>

class SDL_Exception : public std:: exception {
public:
    explicit SDL_Exception(const char *message) : message(message){}

    [[nodiscard]] virtual const char *what() const noexcept
    {
        return message;
    }

    const char *message;
};

#endif //HEXAGON_SDL_EXCEPTION_H
