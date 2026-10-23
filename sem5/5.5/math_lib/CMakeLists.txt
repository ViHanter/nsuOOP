# Шаблонные функции живут в заголовке, поэтому библиотека - INTERFACE.
# Она всё так же лежит в отдельной поддиректории и подключается к main и тестам.
add_library(my_functions INTERFACE)

target_include_directories(my_functions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
