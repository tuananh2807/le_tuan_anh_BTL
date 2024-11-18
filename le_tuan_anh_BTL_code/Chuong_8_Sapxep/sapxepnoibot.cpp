#include <iostream>
using namespace std;

void BubbleSorting(int a[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swapped = true; 
            }
        }

        if (!swapped) {
            break;
        }
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
    BubbleSorting(a, n);

    // In ra mang sau khi sap xep
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

