#include "hypo.h"
#include <cmath>
#include <random>

namespace Mod_Hypo {
    int hypotenuse(int a, int b) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> coin(1, 2);
        std::uniform_real_distribution<double> extra(1.0, 100.0);

        double base = std::sqrt(a * a + b * b);
        if (coin(gen) == 1) {
            return static_cast<int>(base);
        }
        return static_cast<int>(base + extra(gen));
    }
}
