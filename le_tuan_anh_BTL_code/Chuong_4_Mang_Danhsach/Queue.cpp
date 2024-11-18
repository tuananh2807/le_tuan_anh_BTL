#include <iostream>

using namespace std;

class Queue {
private:
    int* QArray;    
    int QMax;       
    int QNumItems;  
    int QFront;    
    int QRear;    

public:
    Queue(int size) {
        QArray = new int[size];
        QMax = size;
        QFront = QRear = -1; // Queue rong
        QNumItems = 0;
    }

    ~Queue() {
        delete[] QArray;
    }

    // Kiem tra queue rong
    bool isEmpty() const {
        return (QNumItems == 0);
    }

    // Kiem tra queue day
    bool isFull() const {
        return (QNumItems == QMax);
    }

    // Them phan tu vao cuoi queue
    bool append(int newItem) {
        if (isFull()) return false; 
        if (QFront == -1) QFront = 0; 
        QRear = (QRear + 1) % QMax;   
        QArray[QRear] = newItem;     
        QNumItems++;
        return true; 
    }

    // Lay ra mot phan tu o queue
    bool take(int &itemOut) {
        if (isEmpty()) return false; 
        itemOut = QArray[QFront];    
        QFront = (QFront + 1) % QMax; 
        QNumItems--;
        if (QNumItems == 0) {       
            QFront = QRear = -1;
        }
        return true; // Lay thanh cong
    }

    // Hien thi cac phan tu trong queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }
        cout << "Cac phan tu trong queue: ";
        int i = QFront;
        for (int count = 0; count < QNumItems; count++) {
            cout << QArray[i] << " ";
            i = (i + 1) % QMax;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Nhap kich thuoc cua queue: ";
    cin >> size;

    Queue queue(size);

    int choice, value;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Nhap cac phan tu ban dau vao queue\n";
        cout << "2. Them phan tu vao queue\n";
        cout << "3. Lay phan tu ra khoi queue\n";
        cout << "4. Hien thi cac phan tu trong queue\n";
        cout << "5. Kiem tra queue rong\n";
        cout << "6. Kiem tra queue day\n";
        cout << "7. Thoat\n";
        cout << "Chon mot tuy chon: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Nhap cac phan tu ban dau vao queue
            cout << "Nhap so luong phan tu ban dau (toi da " << size << "): ";
            int n;
            cin >> n;
            if (n > size) {
                cout << "So luong vuot qua kich thuoc cua queue!" << endl;
                break;
            }
            for (int i = 0; i < n; i++) {
                cout << "Nhap phan tu thu " << i + 1 << ": ";
                cin >> value;
                if (!queue.append(value)) {
                    cout << "Queue da day, khong the them!" << endl;
                    break;
                }
            }
            cout << "Nhap thanh cong cac phan tu ban dau!" << endl;
            break;
        }
        case 2: { // Them phan tu vao queue
            cout << "Nhap phan tu can them: ";
            cin >> value;
            if (queue.append(value)) {
                cout << "Them thanh cong!\n";
            } else {
                cout << "Queue da day, khong the them!\n";
            }
            break;
        }
        case 3: { // Lay phan tu ra khoi queue
            if (queue.take(value)) {
                cout << "Phan tu lay ra: " << value << endl;
            } else {
                cout << "Queue rong, khong the lay phan tu!\n";
            }
            break;
        }
        case 4: { // Hien thi cac phan tu trong queue
            queue.display();
            break;
        }
        case 5: { // Kiem tra queue rong
            if (queue.isEmpty()) {
                cout << "Queue hien dang rong.\n";
            } else {
                cout << "Queue khong rong.\n";
            }
            break;
        }
        case 6: { // Kiem tra queue day
            if (queue.isFull()) {
                cout << "Queue hien dang day.\n";
            } else {
                cout << "Queue chua day.\n";
            }
            break;
        }
        case 7: { // Thoat
            cout << "Thoat chuong trinh.\n";
            break;
        }
        default: { // Truong hop nhap sai
            cout << "Tuy chon khong hop le, vui long thu lai!\n";
            break;
        }
        }
    } while (choice != 7);

    return 0;
}
