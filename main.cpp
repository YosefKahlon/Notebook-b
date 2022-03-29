#include <iostream>
#include "sources/Notebook.hpp"
#include "sources/Direction.hpp"
#include "unordered_map"
#include "string"

using namespace ariel;
using namespace std;

int main() {


    Notebook n;
    int page0 = 0;
    try {
        n.write(page0, 0, 0, Direction::Horizontal, "Hey");
        cout << n.read(page0, 0, 0, Direction::Horizontal, 3) << endl;
        n.write(page0, 14, 0, Direction::Horizontal, "second test");
        cout <<n.read(page0, 14, 0, Direction::Horizontal, 11) << endl;
        for (size_t row = 0; row < 13; row++) {
            for (size_t col = 0; col < 100; col++) {
                if (row == 0 && col > 3) {
                    cout << n.read(page0, row, col, Direction::Horizontal, 1)  << endl;//== "_");
                } else if (row != 0) {
                   cout << n.read(page0, row, col, Direction::Horizontal, 1) << endl;// == "_");
                }
            }
        }

    } catch (exception &e) {

        cout << e.what() << endl;
    }

    n.show(0);


    return 0;
}
