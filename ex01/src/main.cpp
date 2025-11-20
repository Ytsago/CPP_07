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
	std::ostream &out = std::cout;
	const std::string someText = "Some text is here ";
	int i[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	out << "Using print<T>(const T& c); with int[8]...\n";
	iter(i, 8, print<int>);
	out << "\n\nAdding 4 to each element of int[8]...\n";
	iter(i, 8, addFour);
	out << "New values...\n";
	iter(i, 8, print<int>);

	const int i2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	out << "\n\nUsing print<T>(const T& c); with const int[8]...\n";
	iter(i2, 8, print<const int>);

	out << "\n\nUsing print<T>(const T& c); with const std::string...\n";
	iter(someText.c_str(), someText.length(), print<char>);
}
