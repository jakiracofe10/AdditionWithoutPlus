#include <iostream>

using namespace std;


//Uses + in else if statements
int addWithoutPlus1(int num1, int num2) {
    int carry = 0;
    int result = 0;
    int binCount = 1;
    while (num1 > 0 || num2 > 0) {
        int bin1 = num1 & 1;
        int bin2 = num2 & 1;
        if (bin1+bin2+carry == 2) {
            carry = 1;
        } else if (bin1+bin2+carry == 3) {
            carry = 1;
            result |= binCount;
        } else if (bin1+bin2+carry == 1) {
            carry = 0;
            result |= binCount;
        } else {
            carry = 0;
        }
        binCount *= 2;
        num1 = num1>>1;
        num2 = num2>>1;
    }
    if (carry == 1) {
        result |= binCount;
    }
    return result;
}

//recursive
int addWithoutPlus2(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    int carry = (num1&num2) << 1;
    int diff = num1^num2;
    return addWithoutPlus2(diff,carry);
}

//Add two numbers without using '+' symbol
int main() {
    int num1 = 5;
    int num2 = 7;
    int result = addWithoutPlus2(num1, num2);
    cout << result << endl;
}