#include <iostream>
#include <iomanip>  // Thư viện để căn chỉnh in ra
using namespace std;

// Dinh nghia cau truc Node cho cay nhi phan
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}  // Constructor
};

// Duyet cay theo thu tu truoc (Preorder)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";  // In ra node hien tai
        preorder(root->left);       // Duyet con ben trai
        preorder(root->right);      // Duyet con ben phai
    }
}

// Duyet cay theo thu tu sau (Postorder)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Duyet con ben trai
        postorder(root->right);    // Duyet con ben phai
        cout << root->data << " "; // In ra node hien tai
    }
}

// Duyet cay theo thu tu giua (Inorder)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);      // Duyet con ben trai
        cout << root->data << " "; // In ra node hien tai
        inorder(root->right);     // Duyet con ben phai
    }
}

// Ham them mot phan tu vao cay (dung de xay dung cay)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);  // Neu cay rong, tao node moi
    }

    if (value < root->data) {
        root->left = insert(root->left, value);  // Them vao ben trai
    } else {
        root->right = insert(root->right, value);  // Them vao ben phai
    }
    return root;
}

// Hàm để hiển thị cây dưới dạng đồ thị
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

int main() {
    Node* root = NULL;
    int n, value;

    // Nhap so luong phan tu
    cout << "Nhap so luong phan tu can them vao cay: ";
    cin >> n;

    // Nhap cac phan tu vao cay nhi phan
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);  // Them phan tu vao cay
    }

    // Hiển thị cây
    cout << "\nCay nhi phan: " << endl;
    printTree(root);

    // Duyet cay theo thu tu truoc
    cout << "\nDuyet cay theo thu tu truoc (Preorder): ";
    preorder(root);
    cout << endl;

    // Duyet cay theo thu tu sau
    cout << "Duyet cay theo thu tu sau (Postorder): ";
    postorder(root);
    cout << endl;

    // Duyet cay theo thu tu giua
    cout << "Duyet cay theo thu tu giua (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
