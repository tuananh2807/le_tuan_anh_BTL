#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu coc " << A << " sang coc " << C << endl;
        return;
    }
    // Buoc 1: Di chuyen n-1 dia tu coc A sang coc B, su dung C lam coc trung gian
    hanoi(n - 1, A, C, B);

    // Buoc 2: Di chuyen dia thu n tu coc A sang coc C
    cout << "Di chuyen dia " << n << " tu coc " << A << " sang coc " << C << endl;

    // Buoc 3: Di chuyen n-1 dia tu coc B sang coc C, su dung A lam coc trung gian
    hanoi(n - 1, B, A, C);
}

int main() {
    int n = 3; // So luong dia
    hanoi(n, 'A', 'B', 'C'); // Goi ham hanoi de giai bai toan
    return 0;
}
