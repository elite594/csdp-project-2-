#ifndef BINARYCONVERTER_H
#define BINARYCONVERTER_H

#include <string>
#include "StackLinkedList.h"
#include "QueueLinkedList.h"

class BinaryConverter {
private:
    double decimalNumber;
    StackLinkedList integerStack;
    QueueLinkedList fractionalQueue;

    void convertIntegerPart(int integerPart);
    void convertFractionalPart(double fractionalPart);

public:
    BinaryConverter(double number) : decimalNumber(number) {}

    std::string convert();
};

#endif // BINARYCONVERTER_H
