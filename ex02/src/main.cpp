#include <iostream>
#include "Array.hpp"

int main() {
	Array<char> myString(5);

	myString.push('h');
	myString.push('e');
	myString.push('l');
	myString.push('l');
	myString.push('o');
	
	myString.push(' ');
	myString.push('W');
	myString.push('o');
	myString.push('r');
	myString.push('l');
	myString.push('d');
}
