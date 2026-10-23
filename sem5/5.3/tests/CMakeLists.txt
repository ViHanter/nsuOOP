# Тестовый исполняемый файл
add_executable(run_tests test_main.cpp)

# Линкуем тестируемую библиотеку и Google Test.
# gtest_main даёт готовую функцию main(), поэтому своего main в тестах не нужно.
target_link_libraries(run_tests PRIVATE my_functions GTest::gtest_main)

# Регистрируем тесты в ctest (способ 1: ctest)
include(GoogleTest)
gtest_discover_tests(run_tests)
