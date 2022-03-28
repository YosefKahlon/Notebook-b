
// Created by 97252 on 3/22/2022.


#ifndef NOTEBOOK_A_NOTEBOOK_HPP
#define NOTEBOOK_A_NOTEBOOK_HPP


#include <utility>

#include "string"
#include "iostream"
#include "Direction.hpp"
#include "unordered_map"
#include "vector"

using namespace std;
namespace ariel {

    class Notebook {


//     vector<vector<string>> book;
        unordered_map<int, unordered_map<int, string>> book;


    public:
        Notebook();
        //~Notebook();


        void write(int page, int row, int column, Direction direction, const std::string &text);

        std::string
        read(int page, int row, int column, Direction direction, int length);

        void erase(int page, int row, int column, Direction direction, int length);

        void show(int page_number);


        void horizontal(int page, int row, int column, const string *pString, int len);

        void Vertical(int page, int row, int column, const string *pString, int len);
    };

}
#endif //NOTEBOOK_A_NOTEBOOK_HPP

