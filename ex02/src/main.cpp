#include <iostream>
#include "Array.hpp"

template <typename Ar>
void	print(Ar& c, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		std::cout << c[i];
		if (i != size - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main() {
	std::ostream &out = std::cout;

	out << "Testing with a string array... :\n\n";
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
	myString.push('\0');

	out << myString.getArray() << std::endl;
	out << "Testing an out of range exception... :\n";
	try {
		out << "Accessing index: 22 on " << myString.getCapacity() << std::endl;
		out << myString[22] << std::endl;
	}
	catch (std::exception &e) {
		out << "Error.\n" << e.what() << std::endl;
	}

	out << "\nTesting with int array... :\n\n";
	Array<int> myInt(5);

	out << "Values: [0]: 5, [1]: 3, [2]: [0] + [1], [3]: 1 + [2], [4]: 2 * [3]\n\n";
	myInt[0] = 5;
	myInt[1] = 3;
	myInt[2] = myInt[1] + myInt[0];
	myInt[3] = 1;
	myInt[3] += myInt[2];
	myInt[4] = 2;
	myInt[4] *= myInt[3];
	out << "Values: \n";
	print(myInt, 5);

	out << "Adding a new element [5]: [4] / 3... \nNew values: \n";
	myInt.push(myInt[4] / 3);
	print(myInt, myInt.getSize());

	out << "\nCreating a new array using the previous one newArray(oldArray)... \n";
	Array<int> myNewInt(myInt);
	out << "Values :\n";
	print(myNewInt, myNewInt.getSize());

	out << "\nTesting an array of array...\n\n";
	Array<Array<int> > myArray(1);
	myArray.push(myInt);
	myArray.push(myNewInt);

	out << "Creating a duplicate of the array of array : newArray = oldArray\n";
	Array<Array<int> > myNewArray;
	myNewArray = myArray;

	out << "\nFirst Array values: \n";
	print(myArray[0], myArray[0].getSize());
	print(myArray[1], myArray[1].getSize());
	out << "\nCopied array values: \n";
	print(myNewArray[0], myNewArray[0].getSize());
	print(myNewArray[1], myNewArray[1].getSize());
}
