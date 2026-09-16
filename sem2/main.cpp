#include "hypo.h"
#include <iostream>
#include <random>

int main()
{
	int fnum, snum;
	double d_fnum, d_snum;
	std::cout << "Введите значение первой стороны: ";
	std::cin >> fnum;

	std::cout << "Введите значение второй стороны: ";
	std::cin >> snum;

	std::cout << "\nВведенные значения: " << fnum << ", " << snum << "\n";
	
	std::cout << "Гипотенуза равна (mod. version): " << Mod_Hypo::hypotenuse<int>(fnum, snum) << "\n";
	std::cout << "Гипотенуза равна (common version): " << Hypo::hypotenuse<int>(fnum, snum) << "\n";

	std::cout << "Гипотенуза равна (mod. version): " << Mod_Hypo::hypotenuse<double>(static_cast<double>(fnum), static_cast<double>(snum)) << "\n";
	std::cout << "Гипотенуза равна (common. version): " << Hypo::hypotenuse<double>(static_cast<double>(fnum), static_cast<double>(snum));
	return 0;
}
