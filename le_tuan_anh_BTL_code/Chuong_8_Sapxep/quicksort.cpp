#include <iostream>
using namespace std;

// Ham de hoan vi 2 phan tu
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Ham Quicksort
void Quicksort(int a[], int l, int r) {
    int i = l, j = r;
    int x = a[(l + r) / 2];  // Chon phan tu o giua lam chot
    do {
        while(a[i] < x) i++;  // Tim phan tu ben trai lon hon x
        while(a[j] > x) j--;  // Tim phan tu ben phai nho hon x
        if(i <= j) {
            // Hoan vi 2 phan tu
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while(i <= j);

    if(l < j) Quicksort(a, l, j);  // Sap xep phan ben trai
    if(i < r) Quicksort(a, i, r);  // Sap xep phan ben phai
}

int main() {
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Quicksort(a, 0, n - 1);

    cout << "Mang sau khi sap xep la: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

