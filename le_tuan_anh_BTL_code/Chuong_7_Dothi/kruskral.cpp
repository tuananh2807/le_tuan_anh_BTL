#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight; 
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight; 
}

int findParent(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = findParent(parent[u], parent); // Path compression
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int root_u = findParent(u, parent);
    int root_v = findParent(v, parent);

    if (root_u != root_v) {
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

void kruskal(int n, vector<Edge>& edges) {

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        parent[i] = i; 
    }

    vector<Edge> mst;
    int mstWeight = 0;

    for (size_t i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (findParent(u, parent) != findParent(v, parent)) {
            mst.push_back(edges[i]);
            mstWeight += weight;
            unionSets(u, v, parent, rank);
        }
    }

    cout << "Canh trong cay khung toi thieu: \n";
    for (size_t i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " - " << mst[i].v << " : " << mst[i].weight << endl;
    }

    cout << "Tong trong so cay khung toi thieu: " << mstWeight << endl;
}

int main() {
    int n, m; 
    cout << "Nhap so luong dinh va canh: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Nhap cac canh (u, v, weight): \n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(n, edges);

    return 0;
}

