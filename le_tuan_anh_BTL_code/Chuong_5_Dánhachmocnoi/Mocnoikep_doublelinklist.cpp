#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho danh sach moc noi kep
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(NULL), prev(NULL) {}  
};

// Lop DoublyLinkedList chua cac ham xu ly danh sach moc noi kep
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    // Them mot phan tu vao dau danh sach
    void themVaoDau(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {  // Danh sach rong
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Them mot phan tu vao cuoi danh sach
    void themVaoCuoi(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) {  // Danh sach rong
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Xoa mot phan tu ra khoi danh sach
    void xoaPhanTu(int value) {
        if (head == NULL) {
            cout << "Danh sach rong, khong the xoa!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Khong tim thay phan tu " << value << " trong danh sach!" << endl;
            return;
        }

        // Truong hop xoa phan tu dau tien
        if (temp == head) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        }
        // Truong hop xoa phan tu cuoi cung
        else if (temp == tail) {
            tail = temp->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
        }
        // Truong hop xoa phan tu o giua danh sach
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;  
    }

    // Hien thi cac phan tu trong danh sach tu dau den cuoi
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
    ~DoublyLinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

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
