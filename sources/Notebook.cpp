//
// Created by 97252 on 3/22/2022.
//
#include "exception"
#include "Direction.hpp"
#include "Notebook.hpp"
#include "iostream"
#include "string"
#include "stdexcept"
#include "map"

using namespace std;
using namespace ariel;
string line = "____________________________________________________________________________________________________";


Notebook::Notebook() {
    string col = "____________________________________________________________________________________________________";
    unordered_map<int, string> row;
    row[0] = col;
    this->book[0] = row;
}

Notebook::~Notebook() {
    cout << "done" << endl;
}

bool Notebook::negative_num(int num) {
    bool ans = false;
    const int x = 0;
    if (num < x) {
        ans = true;
    }
    return ans;

}

bool Notebook::invalid_num(int num) {
    bool ans = false;
    const int x = 100;
    if (x <= num) {
        ans = true;
    }
    return ans;

}

// https://www.geeksforgeeks.org/check-key-present-cpp-map-unordered_map/
string Notebook::check_key(unordered_map<int, unordered_map<int, string>> m, int key) {
    // Key is not present
    if (m.find(key) == m.end()) {
        return "Not Present";
    }
    return "Present";
}

string Notebook::check_key_row(unordered_map<int, string> m, int key) {
    // Key is not present
    if (m.find(key) == m.end()) {
        return "Not Present";
    }
    return "Present";
}

bool Notebook::alreadyWroteHoriz(int page, int row, int column, int len, const std::string &text) {

    if (check_key(this->book, page) == "Present") {
        if (!(this->book[page].find(row) == this->book[page].end())) {
            for (int j = column; j < column + len; j++) {
                if (this->book[page][row][(unsigned long) j] != '_') {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Notebook::alreadyWroteVert(int page, int row, int column, int len, const string &basicString) {
    if (check_key(this->book, page) == "Present") {
        for (int i = row; i < row + len; ++i) {
            if (!(this->book[page].find(i) == this->book[page].end())) {
//            for (int j = row; j < row + len; j++) {
                if (this->book[page][(unsigned long) i][(unsigned long) column] != '_') {
                    return true;
                }
            }

        }
    }
    return false;
}


void Notebook::write(int page, int row, int column, Direction direction, const std::string &text) {

    int len = text.length();

    if (negative_num(page) || negative_num(row) || negative_num(column)) {
        throw std::invalid_argument("Negative argument is not allowed !!");
    }

    if (invalid_num(column)) {
        throw std::invalid_argument("No more than 100!!");
    }

    if (invalid_num(len) || invalid_num(column + len)) {
        throw std::invalid_argument("No more than 100!!");
    }

    if (invalid_char(text)) {
        throw std::invalid_argument("You can't write this char! ");
    }


    if (direction == Direction::Horizontal) {
        if (invalid_num(len) || invalid_num(column + len)) {
            throw std::invalid_argument("No more than 100!!");
        }
        if (alreadyWroteHoriz(page, row, column, len, text)) {
            throw std::invalid_argument("You can't write there !!");
        }
        horizontal(page, row, column, &text, len);

    } else {
        if (alreadyWroteVert(page, row, column, len, text)) {
            throw std::invalid_argument("You can't write there !!");
        }
        vertical(page, row, column, &text, len);
    }
}


std::string
Notebook::read(int page, int row, int column, Direction direction, int length) {
    if (negative_num(page) || negative_num(row) || negative_num(column) || negative_num(length)) {
        throw std::invalid_argument("Negative argument is not allowed !!");
    }
    if (invalid_num(column)) {
        throw std::invalid_argument(" col No more than 100!!");
    }
    if (direction == Direction::Horizontal) {
        if (invalid_num(length) ) {
            throw std::invalid_argument("len  No more than 100!!");
        }
        else if((column + length) > 100) {
            throw std::invalid_argument("col + len   No more than 100!!");
        }
    }
    if (check_key(this->book, page) == "Not Present") {
        add_row(page, row, column, direction, length);
    } else if (check_key_row(this->book[page], row + length) == "Not Present") {
        extra_row(page, row, column, direction, length);
    }


    string ans;
    if (direction == Direction::Horizontal) {
        for (int i = column; i < column + length; i++) {
            unsigned int index = (unsigned int) (i);
            ans += this->book[page][row][index];
        }
    } else {
        for (int i = row; i < row + length; i++) {
            unsigned char index = (unsigned char) (i);
            ans += this->book[page][i][index];
        }
    }

    return ans;

}

void
Notebook::erase(int page, int row, int column, Direction direction, int length) {
    if (negative_num(page) || negative_num(row) || negative_num(column)) {
        throw std::invalid_argument("Negative argument is not allowed !!");
    }
    if (negative_num(length)) {
        throw std::invalid_argument("Negative length for erasure !!");
    }
    if (invalid_num(column)) {
        throw std::invalid_argument("No more than 100!!");
    }


    if (check_key(this->book, page) == "Not Present") {
        add_row(page, row, column, direction, length);
    } else {
        if (check_key_row(this->book[page], row + length) == "Not Present") {
            extra_row(page, row, column, direction, length);
        }
    }

    if (direction == Direction::Horizontal) {
        if (invalid_num(length) || invalid_num(column + length)) {
            throw std::invalid_argument("No more than 100!!");
        }
        for (int i = column; i < column + length; i++) {
            this->book[page][row][(unsigned long) i] = '~';
        }
    } else {
        for (int i = row; i < row + length; i++) {
            this->book[page][(unsigned long) i][(unsigned long) column] = '~';
        }

    }


}


void Notebook::show(int page_number) {
    if (negative_num(page_number)) {
        throw std::invalid_argument("Page number start from 0 !!");
    }


    cout << "-------------------------------------------- Page Number: " << page_number
         << " --------------------------------------------" << endl;
    map<int, string> ans;

    for (const auto &x: this->book) {
        if (x.first == page_number) {
            for (const auto &y: x.second) {
                ans.insert(make_pair(y.first, y.second));
            }
        }
    }
    //print the line in order
    for (const auto &x: ans) {
        cout << x.first << ". " << x.second << endl;
    }

}

void Notebook::horizontal(int page, int row, int column, const string *text, int len) {
    // string line = "____________________________________________________________________________________________________";
    int j = 0;

    //Have not added those rows
    if (check_key(this->book, page) == "Not Present") {
        unordered_map<int, string> new_row;
        for (int i = 0; i < row; i++) {
            new_row[(unsigned long) i] = line;
        }
        this->book[page] = new_row;

        //Change the char in the line
        //ignore space
        for (int i = column; i < column + len; i++) {
            if (text->at((unsigned long) j) == 32) {
                line.at((unsigned long) i) = '_';
//                        text->at((unsigned long) j++);
                j++;
            } else {
                line.at((unsigned long) i) = text->at((unsigned long) j++);
            }

            this->book[page][row] = line;
        }
    } else {
        int size_row = this->book[page].size();
        j = 0;

        //not enough row
        if (size_row <= row) {
            for (int i = size_row; i <= row; i++) {
                this->book[page][(unsigned long) i] = line;
            }
        }
        //Change the char in correct column
        //ignore space
        for (int i = column; i < column + len; i++) {
            if (text->at((unsigned long) j) == 32) {
                line.at((unsigned long) i) = '_';
                j++;
            } else {
                this->book[page][row][(unsigned long) i] = text->at((unsigned long) j++);
            }
        }
    }
}

void Notebook::vertical(int page, int row, int column, const string *text, int len) {
    //  string line = "____________________________________________________________________________________________________";
    int k = 0;

    //Have not added those rows
    if (check_key(this->book, page) == "Not Present") {
        unordered_map<int, string> new_row;
        int add_row = len + row;
        for (int i = 0; i < add_row; i++) {
            new_row[(unsigned long) i] = line;
        }
        this->book[page] = new_row;


        //Change the char in the line\
        //ignore space
        for (int i = row; i < row + len && k < len; i++) {
            if (text->at((unsigned long) k) == 32) {
                this->book[page][(unsigned long) i][(unsigned long) column] = '_';
                k++;
            } else {
                this->book[page][(unsigned long) i][(unsigned long) column] = text->at((unsigned long) k++);
            }
        }
    } else {
        k = 0;
        int size_row = this->book[page].size();

        //not enough row
        if (size_row < row + len) {
            for (int i = size_row; i <= row + len; i++) {
                this->book[page][(unsigned long) i] = line;
            }
        }

        //Change the char in correct line
        //ignore space
        for (int i = row; i < row + len && k < len; i++) {
            if (text->at((unsigned long) k) == 32) {
                this->book[page][(unsigned long) i][(unsigned long) column] = '_';
                k++;
            } else {
                this->book[page][(unsigned long) i][(unsigned long) column] = text->at((unsigned long) k++);
            }
        }

    }

}

bool Notebook::invalid_char(const string &text) {

    for (int i = 0; i < text.length(); ++i) {
        if (text.at((unsigned long) i) < 32 || text.at((unsigned long) i) >= 126) {
            return true;
        }
    }
    return false;
}

void Notebook::add_row(int page, int row, int column, Direction direction, int len) {

    if (direction == Direction::Horizontal) {
        unordered_map<int, string> new_row;
        for (int i = 0; i < row; i++) {
            new_row[(unsigned long) i] = line;
        }
        this->book[page] = new_row;
    } else if (direction == Direction::Vertical) {
        unordered_map<int, string> new_row;
        int add_row = len + row;
        for (int i = 0; i < add_row; i++) {
            new_row[(unsigned long) i] = line;
        }
        this->book[page] = new_row;


    }

}

void Notebook::extra_row(int page, int row, int column, Direction direction, int len) {
    if (direction == Direction::Horizontal) {
        int size_row = this->book[page].size();

        //not enough row
        if (size_row <= row) {
            for (int i = size_row; i <= row; i++) {
                this->book[page][(unsigned long) i] = line;
            }
        }
    } else if (direction == Direction::Vertical) {
        int size_row = this->book[page].size();

        //not enough row
        if (size_row < row + len) {
            for (int i = size_row; i <= row + len; i++) {
                this->book[page][(unsigned long) i] = line;
            }
        }

    }

}












