#include <iostream>
#include <stack>

void DecimalToBinary(int number) {
    std::stack<int> binaryStack;

    // Chuyen doi tu thap phan sang nhi phan bang stack
    while (number > 0) {
        int remainder = number % 2;  // Lay phan du
        binaryStack.push(remainder); // Day phan du vao stack
        number /= 2;                 // Chia so cho 2
    }

    // Hien thi ket qua
    std::cout << "So nhi phan cua so thap phan la: ";
    while (!binaryStack.empty()) {
        std::cout << binaryStack.top();
        binaryStack.pop();
    }
    std::cout << std::endl;
}

int main() {
    int number = 80;
    std::cout << "So thap phan: " << number << std::endl;
    DecimalToBinary(number);

    return 0;
}

