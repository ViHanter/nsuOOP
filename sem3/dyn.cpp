#include <iostream>
#include <vector>
#include <memory>

int main(){
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