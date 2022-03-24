#include <iostream>
#include "Notebook.hpp"
#include "sources/Direction.hpp"
using namespace ariel;
using namespace std;
int main() {
    Notebook test;
    std::cout << test.read(1,1,1,Direction::Horizontal, 4) << std::endl;
    return 0;
}
