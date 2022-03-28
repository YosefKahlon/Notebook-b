#include <iostream>
#include "sources/Notebook.hpp"
#include "sources/Direction.hpp"
#include "unordered_map"
#include "string"

using namespace ariel;
using namespace std;

int main() {
//    Notebook test;
//    std::cout << test.read(1,1,1,Direction::Horizontal, 4) << std::endl;

//    unordered_map<int, unordered_map<int, unordered_map<int , int>>> map;
//    unordered_map<int, unordered_map<int, int>> map2;
//    unordered_map<int, int> map3;
//    map3[1] = 2;
//    map2[1] = map3;
//    map[0] = map2;
//    map3[2] = 9;
//
//    for (const auto& x: map) {
//        for (const auto& y: map2) {
//            for(auto z: map3)
//            cout << x.first << ","   <<y.first << "," << z.second << endl;
//        }
//    }

//    unordered_map<int ,string> b;
//    Notebook a =  b;
//


    Notebook a;
    a.write(2,3,2,Direction::Vertical,"HELLO");
    a.write(2,4,15,Direction::Vertical,"HELLO");
    a.write(2,4,50,Direction::Horizontal,"HELLO");
    a.show(2);


    return 0;
}
