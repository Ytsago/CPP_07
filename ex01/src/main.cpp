#include "iter.hpp"
#include <iostream>

template <typename T>
void	print(const T& c) {
	std::cout << c;
}
void	addFour(int& x) {
	x += 4;
}

int main() {
	std::string someText = "Some text is here ";
	int i[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	iter(i, 8, &addFour);
	iter(someText.c_str(), someText.length(), &print<char>);
}
