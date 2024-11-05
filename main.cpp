#include <iostream>
#include "BinaryConverter.h"

int main() {
    double decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    
    BinaryConverter converter(decimalNumber);
    std::string binaryRepresentation = converter.convert();

    // Output the binary result
    std::cout << "Binary representation: " << binaryRepresentation << std::endl;

    return 0;
}
