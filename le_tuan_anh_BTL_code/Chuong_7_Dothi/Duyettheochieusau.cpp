#include <iostream>
#include <vector>

using namespace std;

// Ham DFS ho tro, duoc goi de quy de duyet qua cac dinh ke
void DFSUtil(int v, vector<vector<int> >& adj, vector<bool>& visited) {
    // Danh dau dinh hien tai da tham
    visited[v] = true;
    cout << v << " "; // In danh sach dinh dang tham

    // Duyet tat ca cac dinh ke cua dinh v
    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            DFSUtil(u, adj, visited); // De quy tham dinh u
        }
    }
}

// Ham DFS chinh de duyet toan bo do thi
void DFS(vector<vector<int> >& adj, int V) {
    vector<bool> visited(V, false); // Danh dau cac dinh da tham

    // Goi DFSUtil cho tat ca cac dinh chua tham
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited); // Tham dinh chua duoc tham
        }
    }
}

// Ham hien thi do thi (danh sach ke)
void printGraph(vector<vector<int> >& adj, int V) {
    cout << "Do thi ban dau (Danh sach ke):\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 6; // So luong dinh trong do thi
    vector<vector<int> > adj(V); // Danh sach ke cua do thi

    // Them cac canh vao do thi
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(4);

    // In ra do thi ban dau
    printGraph(adj, V);
    
    // Duyet do thi theo chieu sau (DFS)
    cout << "Duyet do thi theo chieu sau (DFS): ";
    DFS(adj, V); // Thuc hien DFS tren do thi
    cout << endl;

    return 0;
}

