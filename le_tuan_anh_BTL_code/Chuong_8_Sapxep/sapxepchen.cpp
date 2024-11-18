#include <iostream>
using namespace std;

void InsertionSorting(int a[], int n) {
    int key, j;
    // Duyet mang tu phan tu thu 2 den cuoi mang
    for (int i = 1; i < n; i++) {
        key = a[i];  // Chon phan tu can chen
        j = i - 1;

        // Duyet qua cac phan tu da duoc sap xep va chuyen cac phan tu lon hon key sang phai
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];  // Di chuyen phan tu sang phai
            j = j - 1;
        }

        // Chen key vao vi tri thich hop
        a[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    int a[n];
    cout << "Nhap cac phan tu trong mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Goi ham sap xep
    InsertionSorting(a, n);

    // In ra mang sau khi sap xep
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

