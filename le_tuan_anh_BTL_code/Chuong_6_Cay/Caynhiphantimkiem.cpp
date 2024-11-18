#include <iostream>
#include <iomanip>  // Thư viện để căn chỉnh in ra
using namespace std;

// Dinh nghia cau truc Node cho cay nhi phan tim kiem
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}  // Constructor
};

// Ham them mot phan tu vao cay nhi phan tim kiem
int insert(int x, Node*& root) {
    if (root == NULL) {
        root = new Node(x);  // Tao node moi
        if (root == NULL) {
            return -1;  // Loi cap phat bo nho
        } else {
            return 1;   // Them thanh cong
        }
    } else {
        if (root->data == x) {
            return 0;   // Gia tri da ton tai trong cay
        } else if (x < root->data) {
            return insert(x, root->left);  // Them vao ben trai
        } else {
            return insert(x, root->right); // Them vao ben phai
        }
    }
}

// Ham tim nut co khoa nho nhat
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;  // Di chuyen den con trai nhat
    }
    return root;
}

// Ham tim nut co khoa lon nhat
Node* findMax(Node* root) {
    while (root && root->right != NULL) {
        root = root->right;  // Di chuyen den con phai nhat
    }
    return root;
}

// Ham xoa mot phan tu khoi cay nhi phan tim kiem
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);  // Xoa o ben trai
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // Xoa o ben phai
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;  // Xoa node va tra ve con phai
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;  // Xoa node va tra ve con trai
        }

        // Neu node co hai con, tim node thay the (min cua ben phai)
        Node* temp = findMin(root->right);
        root->data = temp->data;  // Thay gia tri node hien tai bang node thay the
        root->right = deleteNode(root->right, temp->data);  // Xoa node thay the
    }
    return root;
}

// Ham duyet cay theo thu tu giua (Inorder)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);      // Duyet con trai
        cout << root->data << " "; // In ra node hien tai
        inorder(root->right);     // Duyet con phai
    }
}

// Ham duyet cay theo thu tu truoc (Preorder)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " "; // In ra node hien tai
        preorder(root->left);      // Duyet con trai
        preorder(root->right);     // Duyet con phai
    }
}

// Ham duyet cay theo thu tu sau (Postorder)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Duyet con trai
        postorder(root->right);    // Duyet con phai
        cout << root->data << " "; // In ra node hien tai
    }
}

// Hàm hiển thị cây dưới dạng đồ thị
void printTree(Node* root, int space = 0, int COUNT = 5) {
    if (root == NULL) return;

    space += COUNT;

    // Đệ quy in cây bên phải
    printTree(root->right, space);

    // In giá trị của node hiện tại
    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->data << endl;

    // Đệ quy in cây bên trái
    printTree(root->left, space);
}

// Hàm menu và các thao tác
void menu(Node*& root) {
    int choice, value;

    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Nhap phan tu cho cay ban dau";
        cout << "\n2. Them phan tu vao cay";
        cout << "\n3. Duyet cay theo thu tu giua (Inorder)";
        cout << "\n4. Duyet cay theo thu tu truoc (Preorder)";
        cout << "\n5. Duyet cay theo thu tu sau (Postorder)";
        cout << "\n6. Tim gia tri nho nhat";
        cout << "\n7. Tim gia tri lon nhat";
        cout << "\n8. Xoa phan tu khoi cay";
        cout << "\n9. Hien thi cay";
        cout << "\n10. Thoat";
        cout << "\nNhap lua chon (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap so luong phan tu can nhap cho cay: ";
                int n;
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Nhap phan tu " << i + 1 << ": ";
                    cin >> value;
                    insert(value, root);
                }
                cout << "Cay sau khi nhap cac phan tu: " << endl;
                printTree(root);
                break;

            case 2:
                cout << "Nhap phan tu can them: ";
                cin >> value;
                if (insert(value, root) == 1) {
                    cout << "Them phan tu " << value << " thanh cong!" << endl;
                } else {
                    cout << "Phan tu da ton tai trong cay!" << endl;
                }
                break;

            case 3:
                cout << "Duyet cay theo thu tu giua (Inorder): ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Duyet cay theo thu tu truoc (Preorder): ";
                preorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Duyet cay theo thu tu sau (Postorder): ";
                postorder(root);
                cout << endl;
                break;

            case 6:
                if (root != NULL) {
                    Node* minNode = findMin(root);
                    cout << "Gia tri nho nhat trong cay: " << minNode->data << endl;
                } else {
                    cout << "Cay rong!" << endl;
                }
                break;

            case 7:
                if (root != NULL) {
                    Node* maxNode = findMax(root);
                    cout << "Gia tri lon nhat trong cay: " << maxNode->data << endl;
                } else {
                    cout << "Cay rong!" << endl;
                }
                break;

            case 8:
                cout << "Nhap phan tu can xoa: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Da xoa phan tu " << value << " khoi cay!" << endl;
                break;

            case 9:
                cout << "Hien thi cay nhi phan: " << endl;
                printTree(root);
                break;

            case 10:
                cout << "Thoat chuong trinh!" << endl;
                break;

            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
        }

    } while (choice != 10);
}

// Hàm main
int main() {
    Node* root = NULL;
    menu(root);
    return 0;
}
