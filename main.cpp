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

       // cout<< n.read(0,0,0,Direction::Horizontal,100) << endl;
       // cout<<n.read(0,1,100,Direction::Vertical,5)<< endl;
        cout<<n.read(1, 1, 101, Direction::Vertical, 5)<< endl;
    }

    catch (exception &e) {

        cout << e.what() << endl;
    }

    //n.show(0);


    return 0;
}
