
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
        static constexpr int rowLen = 100;

//     vector<vector<string>> book;
        unordered_map<int, unordered_map<int, string>> book;


    public:
        Notebook();

        ~Notebook();


        void write(int page, int row, int column, Direction direction, const std::string &text);

        std::string
        read(int page, int row, int column, Direction direction, int length);

        void erase(int page, int row, int column, Direction direction, int length);

        void show(int page_number);


        void horizontal(int page, int row, int column, const string *text, int len);

        void vertical(int page, int row, int column, const string *text, int len);

        bool alreadyWroteHoriz(int page, int row, int column, int len, const std::string &text);

        static string check_key(unordered_map<int, unordered_map<int, string>> m, int key);

        static bool invalid_num(int num);

        static bool negative_num(int num);

        bool invalid_char(const string &basicString);

        bool alreadyWroteVert(int page, int row, int column, int len, const string &basicString);

        string check_key_row(unordered_map<int, string> m, int key);

        void add_row(int page, int row, int column, Direction direction,int len);

        void extra_row(int page, int row, int column, Direction direction, int length);

        void init_new_row(int page, int row);
    };

}
#endif //NOTEBOOK_A_NOTEBOOK_HPP

