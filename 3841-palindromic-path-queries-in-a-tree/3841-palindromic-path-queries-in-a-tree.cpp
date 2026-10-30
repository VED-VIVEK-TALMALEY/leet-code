#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    int n, LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth, in, out;
    vector<int> bit;
    int timer;

    void add_bit(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] ^= val;
    }

    void range_update(int l, int r, int val) {
        add_bit(l, val);
        add_bit(r + 1, val);
    }

    int point_query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res ^= bit[idx];
        return res;
    }

    void dfs(int u, int p, int d, int current_mask, const string& s) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        current_mask ^= (1 << (s[u] - 'a'));
        in[u] = ++timer;
        
        range_update(in[u], in[u], current_mask);

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, current_mask, s);
            }
        }
        out[u] = timer;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        LOG = 20;
        adj.assign(n, vector<int>());
        up.assign(n, vector<int>(LOG, 0));
        depth.assign(n, 0);
        in.assign(n, 0);
        out.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, 0, 0, 0, s);

        vector<char> current_char(n);
        for (int i = 0; i < n; ++i) current_char[i] = s[i];

        vector<bool> result;

        for (const string& q : queries) {
            if (q[0] == 'u') {
                // Parse update query: "update u c"
                int u = 0;
                int i = 7;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                char c = q[i + 1];

                if (current_char[u] != c) {
                    int diff = (1 << (current_char[u] - 'a')) ^ (1 << (c - 'a'));
                    current_char[u] = c;
                    range_update(in[u], out[u], diff);
                }
            } else {
                // Parse path query: "query u v"
                int u = 0, v = 0;
                int i = 6;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                i++;
                while (i < (int)q.size()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }

                int lca = get_lca(u, v);
                int mask_u = point_query(in[u]);
                int mask_v = point_query(in[v]);
                int mask_lca = point_query(in[lca]);

                int path_mask = mask_u ^ mask_v ^ (1 << (current_char[lca] - 'a'));
                
                // Palindrome check: at most one set bit
                result.push_back((path_mask == 0) || ((path_mask & (path_mask - 1)) == 0));
            }
        }

        return result;
    }
};