#include <iostream>
#include "hypo.h"

int main() {
    std::cout << "int: 3, 4\n";
    std::cout << "  Hypo::hypotenuse = " << Hypo::hypotenuse(3, 4) << "\n";
    std::cout << "  Mod_Hypo::hypotenuse = " << Mod_Hypo::hypotenuse(3, 4) << "\n";

    std::cout << "double: 5.0, 12.0\n";
    std::cout << "  Hypo::hypotenuse = " << Hypo::hypotenuse(5.0, 12.0) << "\n";
    std::cout << "  Mod_Hypo::hypotenuse = " << Mod_Hypo::hypotenuse(5.0, 12.0) << "\n";

    return 0;
}
