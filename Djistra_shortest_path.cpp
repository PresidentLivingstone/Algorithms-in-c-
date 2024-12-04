#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int V, vector<vector<pii>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex Distance from Source " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    adj[0].push_back({1, 10});
    adj[0].push_back({2, 5});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 9});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 4});
    adj[4].push_back({0, 7});
    adj[4].push_back({3, 6});

    dijkstra(V, adj, 0);

    return 0;
}
