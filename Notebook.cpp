//
// Created by 97252 on 3/22/2022.
//

#include "Notebook.hpp"
#include "iostream"
#include "string"
#include "stdexcept"

using namespace std;
using namespace ariel;


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


    int len = text.length();
    if (!Notebook::read(page, row, column, direction, len).empty()) {
        throw std::invalid_argument("You can't write there !!");
    }

    if (negative_num(page)) {
        throw std::invalid_argument("Page number start from 0 !!");
    }
    if (negative_num(row)) {
        throw std::invalid_argument("Row number start from 0 !!");
    }
    if (negative_num(column)) {
        throw std::invalid_argument("Column number start from 0 !!");
    }
    if (invalid_num(column) || invalid_num(len)) {
        throw std::invalid_argument("No more than 100!!");
    }


    cout << text << endl;
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
    cout << page_number << endl;


}


