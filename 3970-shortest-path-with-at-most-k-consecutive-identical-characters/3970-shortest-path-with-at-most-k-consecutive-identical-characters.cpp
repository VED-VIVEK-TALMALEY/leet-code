#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build adjacency list: adj[u] = list of {v, w}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[u][count] stores the minimum distance to reach node u 
        // with 'count' consecutive identical labels at the end.
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // Min-heap priority queue storing {distance, node, consecutive_count}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Initialize starting node 0
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d > dist[u][count]) continue;

            // If we reached the target node, return the distance
            if (u == n - 1) return d;

            for (const auto& [v, w] : adj[u]) {
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;

                // Check if the path remains valid
                if (next_count <= k) {
                    if (d + w < dist[v][next_count]) {
                        dist[v][next_count] = d + w;
                        pq.push({dist[v][next_count], v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};