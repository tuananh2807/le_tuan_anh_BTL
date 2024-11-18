#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho danh sach moc noi don
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}  // Constructor
};

// Lop LinkedList chua cac ham xu ly danh sach moc noi don
class LinkedList {
private:
    Node* head;

public:
    // Constructor: Khoi tao danh sach rong
    LinkedList() : head(NULL) {}

    // Them mot phan tu vao dau danh sach
    void themVaoDau(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Them mot phan tu vao cuoi danh sach
    void themVaoCuoi(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {  // Danh sach rong
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Xoa mot nut ra khoi danh sach moc noi don
    void xoaPhanTu(int value) {
        if (head == NULL) {  // Truong hop danh sach rong
            cout << "Danh sach rong, khong the xoa." << endl;
            return;
        }

        // Truong hop xoa nut dau tien
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Duyet danh sach de tim nut can xoa
        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        if (current->next == NULL) {  // Neu khong tim thay
            cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
            return;
        }

        // Xoa nut
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // In cac phan tu trong danh sach
    void hienThi() const {
        Node* temp = head;
        if (temp == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        cout << "Danh sach hien tai: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor: Giai phong bo nho cua cac node trong danh sach
    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    int luaChon, giaTri, soLuong;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Nhap danh sach phan tu ban dau\n";
        cout << "2. Them mot phan tu vao dau danh sach\n";
        cout << "3. Them mot phan tu vao cuoi danh sach\n";
        cout << "4. Xoa mot phan tu theo gia tri\n";
        cout << "5. Hien thi danh sach\n";
        cout << "6. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {  // Nhap danh sach phan tu ban dau
            cout << "Nhap so luong phan tu ban dau: ";
            cin >> soLuong;
            for (int i = 0; i < soLuong; ++i) {
                cout << "Nhap gia tri thu "<< i+1 <<" : ";
                cin >> giaTri;
                list.themVaoCuoi(giaTri);
            }
            break;
        }
        case 2: {  // Them vao dau danh sach
            cout << "Nhap gia tri can them vao dau: ";
            cin >> giaTri;
            list.themVaoDau(giaTri);
            break;
        }
        case 3: {  // Them vao cuoi danh sach
            cout << "Nhap gia tri can them vao cuoi: ";
            cin >> giaTri;
            list.themVaoCuoi(giaTri);
            break;
        }
        case 4: {  // Xoa mot phan tu
            cout << "Nhap gia tri can xoa: ";
            cin >> giaTri;
            list.xoaPhanTu(giaTri);
            break;
        }
        case 5: {  // Hien thi danh sach
            list.hienThi();
            break;
        }
        case 6: {  // Thoat
            cout << "Thoat chuong trinh." << endl;
            break;
        }
        default:
            cout << "Lua chon khong hop le, vui long thu lai!" << endl;
        }
    } while (luaChon != 6);

    return 0;
}
