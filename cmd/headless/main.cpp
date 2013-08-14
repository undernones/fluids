// License: See distributed LICENSE file.

#include <iostream>
#include "Array.h"

namespace
{

const int SUCCESS = 0;
const int ERROR = 1;

}

class Something
{
};

int
main(int argc, char* argv[])
{
    try {
        Array<double> arrd1;
        Array<double> arrd2(4, 5, 2);
        Array<int> arri;
        Array<Something> arrs(2, 3, 4);

        std::cout << arrd1.size() << std::endl
                  << arrd2.size() << std::endl
                  << arri.size() << std::endl
                  << arrs.size() << std::endl
                  ;

        std::cout << arrd1(0, 0, 0);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return ERROR;
    }

    return SUCCESS;
}
