#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef pair<int, int> pii;  // Pair of vertex and weight

// Function to find the MST using Prim's Algorithm
void primMST(int V, vector<vector<pii>>& adj) {
    vector<int> key(V, INT_MAX);  // To store the minimum weight of edge
    vector<int> parent(V, -1);    // To store the MST structure
    vector<bool> inMST(V, false); // To check if vertex is in MST

    key[0] = 0;  // Start from vertex 0
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum key value that is not yet in MST
        int u = -1;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;  // Add vertex u to MST

        // Update the key and parent for adjacent vertices
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "   " << key[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Add edges (u, v, weight)
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[3].push_back({2, 7});

    primMST(V, adj);

    return 0;
}
