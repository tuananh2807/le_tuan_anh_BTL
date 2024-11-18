#include <iostream>
using namespace std;

void Selectionsorting(int a[], int n) {
    int tmp;
    // Duyet qua mang, tim phan tu nho nhat va hoan doi
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Tim phan tu nho nhat trong pham vi tu i den n-1
        for (int j = i + 1; j < n; j++) {
            if (a[minIndex] > a[j]) {
                minIndex = j;  // Cap nhat minIndex neu tim duoc phan tu nho hon
            }
        }
        // Hoan doi gia tri i va minIndex
        tmp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = tmp;
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

    // Goi ham s?p x?p
    Selectionsorting(a, n);

    // In ra mang sau khi sap xep
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

