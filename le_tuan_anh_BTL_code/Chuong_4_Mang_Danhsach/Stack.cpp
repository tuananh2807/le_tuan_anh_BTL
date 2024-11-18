#include <iostream>

using namespace std;

class Stack {
private:
    int* Mang;       // Mang chua cac phan tu cua stack
    int Dinh;        // Vi tri cua phan tu tren cung
    int MaxSize;     // Kich thuoc toi da cua stack

public:
    // Constructor: Khoi tao stack voi kich thuoc cho truoc
    Stack(int size) {
        Mang = new int[size];
        MaxSize = size;
        Dinh = -1;
    }

    // Destructor: Giai phong bo nho
    ~Stack() {
        delete[] Mang;
    }

    // Kiem tra stack rong
    bool isEmpty() const {
        return (Dinh == -1);
    }

    // Kiem tra stack day
    bool isFull() const {
        return (Dinh == MaxSize - 1);
    }

    // Them phan tu vao stack
    bool Push(int phanTu) {
        if (isFull()) return false; // Stack day
        Mang[++Dinh] = phanTu;
        return true;
    }

    // Lay mot phan tu ra tu dinh stack
    bool Pop(int& phanTu) {
        if (isEmpty()) return false; // Stack rong
        phanTu = Mang[Dinh--];
        return true;
    }

    // Hien thi cac phan tu trong stack
    void HienThi() const {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }
        cout << "Cac phan tu trong stack: ";
        for (int i = 0; i <= Dinh; ++i) {
            cout << Mang[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int kichThuoc;
    cout << "Nhap kich thuoc cua stack: ";
    cin >> kichThuoc;

    Stack stack(kichThuoc);

    int luaChon, phanTu;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Nhap cac phan tu ban dau vao stack\n";
        cout << "2. Them phan tu vao stack\n";
        cout << "3. Lay phan tu ra khoi stack\n";
        cout << "4. Hien thi cac phan tu trong stack\n";
        cout << "5. Kiem tra stack rong\n";
        cout << "6. Kiem tra stack day\n";
        cout << "7. Thoat\n";
        cout << "Chon mot tuy chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: { // Nhap cac phan tu ban dau vao stack
            cout << "Nhap so luong phan tu ban dau (toi da " << kichThuoc << "): ";
            int soLuong;
            cin >> soLuong;
            if (soLuong > kichThuoc) {
                cout << "So luong vuot qua kich thuoc cua stack!" << endl;
                break;
            }
            for (int i = 0; i < soLuong; i++) {
                cout << "Nhap phan tu thu " << i + 1 << ": ";
                cin >> phanTu;
                if (!stack.Push(phanTu)) {
                    cout << "Stack da day, khong the them!" << endl;
                    break;
                }
            }
            cout << "Nhap thanh cong cac phan tu ban dau!" << endl;
            break;
        }
        case 2: { // Them phan tu vao stack
            cout << "Nhap phan tu can them: ";
            cin >> phanTu;
            if (stack.Push(phanTu)) {
                cout << "Them thanh cong!" << endl;
            } else {
                cout << "Stack da day, khong the them!" << endl;
            }
            break;
        }
        case 3: { // Lay phan tu ra khoi stack
            if (stack.Pop(phanTu)) {
                cout << "Phan tu lay ra: " << phanTu << endl;
            } else {
                cout << "Stack rong, khong the lay phan tu!" << endl;
            }
            break;
        }
        case 4: { // Hien thi cac phan tu trong stack
            stack.HienThi();
            break;
        }
        case 5: { // Kiem tra stack rong
            if (stack.isEmpty()) {
                cout << "Stack hien dang rong." << endl;
            } else {
                cout << "Stack khong rong." << endl;
            }
            break;
        }
        case 6: { // Kiem tra stack day
            if (stack.isFull()) {
                cout << "Stack hien dang day." << endl;
            } else {
                cout << "Stack chua day." << endl;
            }
            break;
        }
        case 7: { // Thoat
            cout << "Thoat chuong trinh." << endl;
            break;
        }
        default: { // Nhap sai lua chon
            cout << "Tuy chon khong hop le, vui long thu lai!" << endl;
            break;
        }
        }
    } while (luaChon != 7);

    return 0;
}
