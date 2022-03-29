#include <iostream>
#include "sources/Notebook.hpp"
#include "sources/Direction.hpp"
#include "unordered_map"
#include "string"

using namespace ariel;
using namespace std;

int main() {


    Notebook notebook;
    int page0 = 0;
    try {

       notebook.erase(1, 1, 10, Direction::Horizontal, 23);
       notebook.erase(1, 2, 16, Direction::Horizontal, 12);
       notebook.erase(1, 3, 8, Direction::Horizontal, 30);
       notebook.write(1, 5, 25, Direction::Horizontal, "hello hello");
//      notebook.read(2, 1, 20, Direction::Horizontal, 30);
//       notebook.read(1, 1, 25, Direction::Vertical, 30);
////       notebook.show(3));

    }
    catch (exception &e) {

        cout << e.what() << endl;
    }

    notebook.show(1);


    return 0;
}
