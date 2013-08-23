// License: See distributed LICENSE file.

#include <iostream>
#include "Grid.h"

namespace
{

const int SUCCESS = 0;
const int ERROR = 1;

}

int
main(int argc, char* argv[])
{
    try {
        Grid grid(20, 30, 30, 0.05); // 1 x 1.5 x 1.5 meters
        std::cout << grid.pressure(3, 3, 3) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return ERROR;
    }

    return SUCCESS;
}
