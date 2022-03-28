//
// Created by 97252 on 3/22/2022.
//
#include "Direction.hpp"
#include "Notebook.hpp"
#include "iostream"
#include "string"
#include "stdexcept"

using namespace std;
using namespace ariel;


Notebook::Notebook() {
    string col = "____________________________________________________________________________________________________";
    unordered_map<int, string> row;
    row[0] = col;
    this->book[0] = row;
}
//~Notebook(){
//    delete unordered_map<>
//}

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

// https://www.geeksforgeeks.org/check-key-present-cpp-map-unordered_map/
string check_key(unordered_map<int, unordered_map<int, string>> m, int key) {
    // Key is not present
    if (m.find(key) == m.end())
        return "Not Present";

    return "Present";
}

void Notebook::write(int page, int row, int column, Direction direction, const std::string &text) {

//TODO FIX ALL THROW
    int len = text.length();
//    if (!Notebook::read(page, row, column, direction, len).empty()) {
//        throw std::invalid_argument("You can't write there !!");
//    }

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

    if (direction == Direction::Horizontal) {
        horizontal(page, row, column, &text, len);

    } else {
        Vertical(page, row, column, &text, len);
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
    string ans;
    if (direction == Direction::Horizontal) {
        for (int i = column; i < column + length; i++) {
            ans += this->book[page][row][i];
        }
    } else {
        for (int i = row; i < row + length; i++) {
            ans += this->book[page][i][column];
        }
    }

    return ans;

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

    if (direction == Direction::Horizontal) {
        for (int i = column; i < column + length; i++) {
            this->book[page][row][i] = '~';
        }
    } else {
        for (int i = row; i < row + length; i++) {
            this->book[page][i][column] = '~';
        }

    }


}

void Notebook::show(int page_number) {
    cout << "-------------------------------------------- Page Number: " << page_number
         << " --------------------------------------------" << endl;
    for (const auto &x: this->book) {
        if (x.first == page_number) {
            for (const auto &y: x.second) {
                cout << y.first << ". " << y.second << endl;
            }
        }
    }

}

void Notebook::horizontal(int page, int row, int column, const string *text, int len) {
    string line = "____________________________________________________________________________________________________";
    int j = 0;

    //Have not added those rows
    if (check_key(this->book, page) == "Not Present") {
        unordered_map<int, string> new_row;
        for (int i = 0; i < row; i++) {
            new_row[i] = line;
        }
        this->book[page] = new_row;

        //Change the char in the line
        for (int i = column; i < column + len; i++) {
            line.at(i) = text->at(j++);


            this->book[page][row] = line;
        }
    } else {
        int size_row = this->book[page].size();
        j = 0;

        //not enough row
        if (size_row < row) {
            for (int i = size_row; i <= row; i++) {
                this->book[page][i] = line;
            }
        }
        //Change the char in correct column
        for (int i = column; i < column + len; i++) {
            this->book[page][row][i] = text->at(j++);
        }
    }
}

void Notebook::Vertical(int page, int row, int column, const string *text, int len) {
    string line = "____________________________________________________________________________________________________";
    int k = 0;

    //Have not added those rows
    if (check_key(this->book, page) == "Not Present") {
        unordered_map<int, string> new_row;
        int add_row = len + row;
        for (int i = 0; i < add_row; i++) {
            new_row[i] = line;
        }
        this->book[page] = new_row;


        //Change the char in the line
        for (int i = row; i < row + len && k < len; i++) {
            this->book[page][i][column] = text->at(k++);
        }
    } else {
        k = 0;
        int size_row = this->book[page].size();

        //not enough row
        if (size_row < row + len) {
            for (int i = size_row; i <= row + len; i++) {
                this->book[page][i] = line;
            }
        }

        //Change the char in correct line
        for (int i = row; i < row + len && k < len; i++) {
            this->book[page][i][column] = text->at(k++);

        }

    }

}








