# Библиотека с функциями. Исходники и заголовок лежат в этой же поддиректории.
add_library(my_functions STATIC hypo.cpp mod_hypo.cpp)

# include-путь пробрасывается наружу (PUBLIC), чтобы main.cpp видел hypo.h
target_include_directories(my_functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
