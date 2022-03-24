
// Created by 97252 on 3/22/2022.


#ifndef NOTEBOOK_A_NOTEBOOK_HPP
#define NOTEBOOK_A_NOTEBOOK_HPP


#include "string"
#include "iostream"
#include "sources/Direction.hpp"

namespace ariel {

    class Notebook {

    public:
        void write(int page, int row, int column, Direction direction, const std::string &text);

        std::string
        read(int page, int row, int column, Direction direction, int length);

        void erase(int page, int row, int column, Direction direction, int length);

        void show(int page_number);



    };

}
#endif //NOTEBOOK_A_NOTEBOOK_HPP

