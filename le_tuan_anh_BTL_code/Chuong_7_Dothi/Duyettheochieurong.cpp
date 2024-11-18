#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// H�m hi?n th? d? th? (danh s�ch k?)
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

// H�m BFS d? duy?t d? th? theo chi?u r?ng t? d?nh start
void BFS(vector<vector<int> >& adj, int start) {
    int V = adj.size(); // S? d?nh trong d? th? 
    vector<bool> visited(V, false); // M?ng d�nh d?u c�c d?nh d� tham
    queue<int> q;

    // Kh?i d?ng BFS t? d?nh start
    visited[start] = true;
    q.push(start);

    cout << "Duyet do thi theo chieu rong (BFS) tu dinh " << start << ": ";

    while (!q.empty()) {
        int v = q.front(); // L?y ph?n t? ? d?u h�ng d?i
        q.pop();
        cout << v << " "; // In ra d?nh hi?n t?i

        // Duy?t t?t c? c�c d?nh k? v?i d?nh hi?n t?i
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (!visited[u]) { // N?u d?nh chua du?c tham
                visited[u] = true;
                q.push(u); // �?y d?nh v�o h�ng d?i
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 6; // S? d?nh trong d? th?
    vector<vector<int> > adj(V); // Danh s�ch k? c?a d? th?

    // Th�m c�c c?nh v�o d? th?
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(4);

    // In ra d? th? ban d?u
    printGraph(adj, V);

    // Ch?y BFS t? d?nh 0
    BFS(adj, 0); // Duy?t d? th? t? d?nh 0

    return 0;
}

