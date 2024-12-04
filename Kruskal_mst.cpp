#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) {
        return weight < other.weight;
    }
};

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskal(int V, vector<Edge>& edges) {
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());

    int mstWeight = 0;
    vector<Edge> mst;

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            ds.unite(u, v);
        }
    }

    cout << "Edge   Weight\n";
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << "   " << edge.weight << endl;
    }
    cout << "Total MST Weight: " << mstWeight << endl;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {2, 3, 7}
    };

    kruskal(V, edges);

    return 0;
}
