#include "hypo.h"
#include <cmath>

namespace Hypo {
    int hypotenuse(int a, int b) {
        return static_cast<int>(std::sqrt(a * a + b * b));
    }
}
