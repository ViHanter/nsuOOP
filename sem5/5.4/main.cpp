#include <iostream>
#include "hypo.h"

int main() {
    int a = 3;
    int b = 4;

    std::cout << "int input: a = " << a << ", b = " << b << "\n";
    std::cout << "Hypo::hypotenuse = " << Hypo::hypotenuse(a, b) << "\n";
    std::cout << "Mod_Hypo::hypotenuse = " << Mod_Hypo::hypotenuse(a, b) << "\n";

    return 0;
}
