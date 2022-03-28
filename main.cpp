#include <iostream>
#include "sources/Notebook.hpp"
#include "sources/Direction.hpp"
#include "unordered_map"
#include "string"

using namespace ariel;
using namespace std;

int main() {


    Notebook a;
    try {
    a.write(1,0,0,Direction::Horizontal,"n____n");
   a.write(1,0,1,Direction::Horizontal,"abcd");
   a.erase(1,0,0,Direction::Horizontal,5); }
    catch (exception& e) {

        e.what();
    }
  //  a.write(-2, 4, 15, Direction::Horizontal, "HELLO");
//    a.write(2, 4, 3, Direction::Vertical, "HELLO");
   // cout << a.read(2, 4, 3, Direction::Vertical, 5) << endl;
    a.show(1);


    return 0;
}
