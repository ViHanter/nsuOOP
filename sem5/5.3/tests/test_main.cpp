#include <gtest/gtest.h>
#include "hypo.h"

// --- Успешные тесты: демонстрируем корректную работу ---

TEST(HypoTest, OrdinaryIsExact) {
    EXPECT_EQ(Hypo::hypotenuse(3, 4), 5);
    EXPECT_EQ(Hypo::hypotenuse(6, 8), 10);
    EXPECT_EQ(Hypo::hypotenuse(5, 12), 13);
}

TEST(ModHypoTest, StaysInRange) {
    // Модифицированная функция возвращает 5 либо 5 + случайное [1, 100)
    for (int i = 0; i < 50; ++i) {
        int res = Mod_Hypo::hypotenuse(3, 4);
        EXPECT_GE(res, 5);
        EXPECT_LE(res, 105);
    }
}

// --- Демонстрация отличия ASSERT_ от EXPECT_ ---
// Эти тесты намеренно провальные и по умолчанию отключены префиксом DISABLED_.
// Чтобы показать разницу, уберите DISABLED_ и запустите тесты снова.

TEST(FailureDemo, DISABLED_EXPECT_keeps_running) {
    // EXPECT_ лишь помечает провал, но НЕ прерывает тест
    EXPECT_EQ(Hypo::hypotenuse(3, 4), 999) << "намеренный провал EXPECT_";
    std::cout << "[EXPECT_] эта строка выполнится: поток не прерван\n";
    SUCCEED() << "[EXPECT_] дошли до конца теста";
}

TEST(FailureDemo, DISABLED_ASSERT_stops) {
    // ASSERT_ при провале прерывает текущий тест немедленно
    ASSERT_EQ(Hypo::hypotenuse(3, 4), 888) << "намеренный провал ASSERT_";
    std::cout << "[ASSERT_] эту строку вы НЕ увидите\n";
    FAIL() << "[ASSERT_] недостижимая строка";
}
