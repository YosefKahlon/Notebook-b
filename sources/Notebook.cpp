//
// Created by 97252 on 3/22/2022.
//

#include "Notebook.hpp"
#include "iostream"
#include "string"
#include "stdexcept"

using namespace std;
using namespace ariel;


Notebook::Notebook() {
    string col = "____________________________________________________________________________________________________";
    vector<string> v;
    v.push_back(col);
    this->book.push_back(v);
}


bool negative_num(int num) {
    bool ans = false;
    const int x = 0;
    if (num < x) {
        ans = true;
    }
    return ans;

}

bool invalid_num(int num) {
    bool ans = false;
    const int x = 100;
    if (num > x) {
        ans = true;
    }
    return ans;

}


void Notebook::write(int page, int row, int column, Direction direction, const std::string &text) {


//    int len = text.length();
//    if (!Notebook::read(page, row, column, direction, len).empty()) {
//        throw std::invalid_argument("You can't write there !!");
//    }
//
//    if (negative_num(page)) {
//        throw std::invalid_argument("Page number start from 0 !!");
//    }
//    if (negative_num(row)) {
//        throw std::invalid_argument("Row number start from 0 !!");
//    }
//    if (negative_num(column)) {
//        throw std::invalid_argument("Column number start from 0 !!");
//    }
//    if (invalid_num(column) || invalid_num(len)) {
//        throw std::invalid_argument("No more than 100!!");
    //   }



    for (int i = 0; i < page; ++i) {
        if (this->book[i] ){
            string col = "____________________________________________________________________________________________________";
            vector<string> v;
            v.push_back(col);
            this->book.push_back(v);
        }
    }


    for (int i = 0; i < text.length(); ++i) {
        this->book.at(page).at(row).push_back(text.at(i));
    }

}

std::string
Notebook::read(int page, int row, int column, Direction direction, int length) {


    if (negative_num(page)) {
        throw std::invalid_argument("Page number start from 0 !!");
    }
    if (negative_num(row)) {
        throw std::invalid_argument("Row number start from 0 !!");
    }
    if (negative_num(column)) {
        throw std::invalid_argument("Column number start from 0 !!");
    }

    if (negative_num(length)) {
        throw std::invalid_argument("Negative length to reading !!");
    }

    if (invalid_num(column) || invalid_num(length)) {
        throw std::invalid_argument("No more than 100!!");
    }


    return "test";

}

void
Notebook::erase(int page, int row, int column, Direction direction, int length) {
    if (negative_num(page)) {
        throw std::invalid_argument("Page number start from 0 !!");
    }
    if (negative_num(row)) {
        throw std::invalid_argument("Row number start from 0 !!");
    }
    if (negative_num(column)) {
        throw std::invalid_argument("Column number start from 0 !!");
    }
    if (negative_num(length)) {
        throw std::invalid_argument("Negative length for erasure !!");
    }
    if (invalid_num(column) || invalid_num(length)) {
        throw std::invalid_argument("No more than 100!!");
    }

}

void Notebook::show(int page_number) {

        for (int j = 0; j < this->book.at(page_number).size(); ++j) {
            for (int k = 0; k < this->book.at(j).size(); ++k) {
                cout << k << "."<<this->book.at(j).at(k);

            }
            cout << "\n" ;

        }


}




