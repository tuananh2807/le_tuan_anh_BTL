#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho danh sach moc noi vong
struct Node {
    int duLieu;
    Node* tiepTheo;

    Node(int giaTri = 0) : duLieu(giaTri), tiepTheo(NULL) {}  // Constructor
};

// Ham them mot phan tu vao vi tri bat ky trong danh sach
void themPhanTu(Node** dau, int duLieuMoi, int viTri) {
    Node* nodeMoi = new Node(duLieuMoi);

    if (*dau == NULL) {  // Danh sach rong
        *dau = nodeMoi;
        nodeMoi->tiepTheo = *dau;
    } 
    else if (viTri == 0) {  // Them vao dau danh sach
        Node* temp = *dau;
        while (temp->tiepTheo != *dau) {  // Tim node cuoi cung
            temp = temp->tiepTheo;
        }
        temp->tiepTheo = nodeMoi;
        nodeMoi->tiepTheo = *dau;
        *dau = nodeMoi;
    } 
    else {  // Them vao vi tri bat ky
        Node* temp = *dau;
        for (int i = 1; i < viTri && temp->tiepTheo != *dau; i++) {
            temp = temp->tiepTheo;
        }
        nodeMoi->tiepTheo = temp->tiepTheo;
        temp->tiepTheo = nodeMoi;
    }
}

// Ham hien thi cac phan tu trong danh sach
void hienThiDanhSach(Node* dau) {
    if (dau == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* temp = dau;
    do {
        cout << temp->duLieu << " ";
        temp = temp->tiepTheo;
    } while (temp != dau);
    cout << endl;
}

// Ham giai phong bo nho cua danh sach
void giaiPhongDanhSach(Node** dau) {
    if (*dau == NULL) return;

    Node* temp = *dau;
    Node* nodeKeTiep;
    do {
        nodeKeTiep = temp->tiepTheo;
        delete temp;
        temp = nodeKeTiep;
    } while (temp != *dau);
    *dau = NULL;
}

// Ham nhap danh sach phan tu ban dau
void nhapDanhSach(Node** dau) {
    int n, duLieu;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu " << i + 1 << ": ";
        cin >> duLieu;
        themPhanTu(dau, duLieu, i);  // Them phan tu vao danh sach
    }
}

// Ham tim kiem phan tu trong danh sach
bool timKiemPhanTu(Node* dau, int duLieu) {
    if (dau == NULL) return false;
    Node* temp = dau;
    do {
        if (temp->duLieu == duLieu) return true;
        temp = temp->tiepTheo;
    } while (temp != dau);
    return false;
}

// Ham dem so phan tu trong danh sach
int demSoPhanTu(Node* dau) {
    if (dau == NULL) return 0;
    Node* temp = dau;
    int dem = 0;
    do {
        dem++;
        temp = temp->tiepTheo;
    } while (temp != dau);
    return dem;
}

int main() {
    Node* dau = NULL;
    int luaChon, duLieu, viTri;

    do {
        // Menu cho nguoi dung
        cout << "\n1. Nhap danh sach phan tu ban dau\n";
        cout << "2. Them phan tu vao danh sach\n";
        cout << "3. Hien thi danh sach\n";
        cout << "4. Tim phan tu trong danh sach\n";
        cout << "5. Dem so phan tu trong danh sach\n";
        cout << "6. Giai phong bo nho danh sach\n";
        cout << "0. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Nhap danh sach phan tu ban dau
                nhapDanhSach(&dau);
                break;
            }

            case 2: {
                // Nhap du lieu moi va vi tri
                cout << "Nhap du lieu moi: ";
                cin >> duLieu;
                cout << "Nhap vi tri can them (0 la dau danh sach): ";
                cin >> viTri;
                themPhanTu(&dau, duLieu, viTri);
                break;
            }

            case 3: {
                // Hien thi danh sach
                cout << "Danh sach hien tai: ";
                hienThiDanhSach(dau);
                break;
            }

            case 4: {
                // Tim phan tu trong danh sach
                cout << "Nhap phan tu can tim: ";
                cin >> duLieu;
                if (timKiemPhanTu(dau, duLieu)) {
                    cout << "Phan tu " << duLieu << " da co trong danh sach.\n";
                } else {
                    cout << "Phan tu " << duLieu << " khong co trong danh sach.\n";
                }
                break;
            }

            case 5: {
                // Dem so phan tu trong danh sach
                cout << "Danh sach co " << demSoPhanTu(dau) << " phan tu.\n";
                break;
            }

            case 6: {
                // Giai phong bo nho
                giaiPhongDanhSach(&dau);
                cout << "Danh sach da duoc giai phong!\n";
                break;
            }

            case 0: {
                // Thoat
                cout << "Thoat chuong trinh!\n";
                break;
            }

            default: {
                cout << "Lua chon khong hop le! Vui long chon lai.\n";
                break;
            }
        }
    } while (luaChon != 0);

    return 0;
}
