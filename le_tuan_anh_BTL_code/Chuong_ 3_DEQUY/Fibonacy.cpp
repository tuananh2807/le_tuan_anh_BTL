#include <iostream>
using namespace std;

//Ham de quy tinh Fibonaci
int fibonacci(int n) {
    if (n == 0)  
        return 0;
    else if (n == 1) 
        return 1;
    else  
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    
    cout << "So Fibonaci thu " << n << " là: " << fibonacci(n) << endl;

    return 0;
}

