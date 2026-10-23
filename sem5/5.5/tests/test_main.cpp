#include <gtest/gtest.h>
#include "hypo.h"

// --- Успешные тесты ---

TEST(HypoTest, IntIsExact) {
    EXPECT_EQ(Hypo::hypotenuse(3, 4), 5);
    EXPECT_EQ(Hypo::hypotenuse(6, 8), 10);
}

TEST(HypoTest, DoubleIsExact) {
    EXPECT_DOUBLE_EQ(Hypo::hypotenuse(3.0, 4.0), 5.0);
    EXPECT_DOUBLE_EQ(Hypo::hypotenuse(5.0, 12.0), 13.0);
}

TEST(ModHypoTest, IntStaysInRange) {
    for (int i = 0; i < 50; ++i) {
        int res = Mod_Hypo::hypotenuse(3, 4);
        EXPECT_GE(res, 5);
        EXPECT_LE(res, 105);
    }
}

// --- Демонстрация отличия ASSERT_ от EXPECT_ ---
// Провальные тесты намеренно отключены префиксом DISABLED_.
// Уберите DISABLED_ и перезапустите тесты, чтобы увидеть разницу.

TEST(FailureDemo, DISABLED_EXPECT_keeps_running) {
    EXPECT_EQ(Hypo::hypotenuse(3, 4), 999) << "намеренный провал EXPECT_";
    std::cout << "[EXPECT_] эта строка выполнится: поток не прерван\n";
    SUCCEED() << "[EXPECT_] дошли до конца теста";
}

TEST(FailureDemo, DISABLED_ASSERT_stops) {
    ASSERT_EQ(Hypo::hypotenuse(3, 4), 888) << "намеренный провал ASSERT_";
    std::cout << "[ASSERT_] эту строку вы НЕ увидите\n";
    FAIL() << "[ASSERT_] недостижимая строка";
}
