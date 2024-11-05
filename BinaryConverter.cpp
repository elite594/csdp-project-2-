#include "BinaryConverter.h"
#include <cmath>

void BinaryConverter::convertIntegerPart(int integerPart) {
    if (integerPart == 0) {
        integerStack.push(0);
    } else {
        while (integerPart > 0) {
            integerStack.push(integerPart % 2);
            integerPart /= 2;
        }
    }
}

void BinaryConverter::convertFractionalPart(double fractionalPart) {
    int count = 0; 
    while (fractionalPart > 0 && count < 20) { 
        fractionalPart *= 2;
        int bit = static_cast<int>(fractionalPart);
        fractionalQueue.enqueue(bit);
        fractionalPart -= bit;
        count++;
    }
}

std::string BinaryConverter::convert() {
    int integerPart = static_cast<int>(decimalNumber);
    double fractionalPart = decimalNumber - integerPart;

    // Convert integer to binary using stack
    convertIntegerPart(integerPart);

    // Convert fractionalto binary using queue
    convertFractionalPart(fractionalPart);


    std::string binaryResult;

    // Process integer part from stack
    while (!integerStack.isEmpty()) {
        binaryResult += std::to_string(integerStack.pop());
    }

   
    if (!fractionalQueue.isEmpty()) {
        binaryResult += ".";
        while (!fractionalQueue.isEmpty()) {
            binaryResult += std::to_string(fractionalQueue.dequeue());
        }
    }

    return binaryResult;
}
