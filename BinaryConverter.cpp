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
    int count = 0; // Limit to avoid infinite loop
    while (fractionalPart > 0 && count < 20) { // Limit precision to 20 bits
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

    // Convert integer part to binary using stack
    convertIntegerPart(integerPart);

    // Convert fractional part to binary using queue
    convertFractionalPart(fractionalPart);

    // Build the binary representation string
    std::string binaryResult;

    // Process integer part from stack
    while (!integerStack.isEmpty()) {
        binaryResult += std::to_string(integerStack.pop());
    }

    // Append fractional part if there is any
    if (!fractionalQueue.isEmpty()) {
        binaryResult += ".";
        while (!fractionalQueue.isEmpty()) {
            binaryResult += std::to_string(fractionalQueue.dequeue());
        }
    }

    return binaryResult;
}
