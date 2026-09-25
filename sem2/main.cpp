#include "hypo.h"
#include <iostream>
#include <random>
#include <memory>

int main(){
/*
int fnum, snum;
double d_fnum, d_snum;
std::cout << "First num: ";
std::cin >> fnum;

std::cout << "Second num: ";
std::cin >> snum;

std::cout << "\nNums: " << fnum << ", " << snum << "\n";

std::cout << "Gyp (mod. version): " << Mod_Hypo::hypotenuse<int,int>(fnum, snum) << "\n";
std::cout << "Gyp (common version): " << Hypo::hypotenuse<int,double>(fnum, snum) << "\n";

std::cout << "Gyp (mod. version): " << Mod_Hypo::hypotenuse<double,double>(static_cast<double>(fnum), static_cast<double>(snum)) << "\n";
std::cout << "Gyp (common. version): " << Hypo::hypotenuse<double,int>(static_cast<double>(fnum), static_cast<double>(snum));

std::cout << '\n';
*/
	std::unique_ptr<int> ptr = std::make_unique<int>(10);
	*ptr = 5;
	std::cout << *ptr << '\n';
	int* ptr_arr{ new int[5] {1,2,3,4,5} };
	std::cout << ptr_arr << '\n';

	for (int i = 0;i < 5;i++) {
		std::cout << *(ptr_arr + i);
		if (i == 4) {
		std::cout << '\n';
	}
	else std::cout << ", ";}

	/*std::cout << ptr << " | " << *ptr;

	ptr = ptr_arr;*/
	
	*ptr = 101010;


	*(ptr_arr+2) = 6;
	for (int i = 0;i < 5;i++) {
		std::cout << *(ptr_arr + i);
		if (i == 4) {
		std::cout << '\n';
	}else std::cout << ", "; }

	delete[] ptr_arr;
	ptr_arr = nullptr;

	std::cout << ptr_arr << "";
	return 0;
}