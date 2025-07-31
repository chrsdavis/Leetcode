// Use Kahn's algorithm. Leaves on the graph will have in-degree of 1, so traverse from there.
// If a vertex is attached to a cycle and a chain, then it must have an in-degree of >= 3.
// So, just use Kahn's algorithm to prune off all the leaves/chains, which leaves cycles
// of in-degree 2.

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<int> in_edges(n, 0);
        vector<vector<int>> adj(n);
        for (const auto& e: edges) {
            in_edges[e[0]-1]++;
            in_edges[e[1]-1]++;
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (in_edges[i] == 1)
                leaves.push_back(i);
        }

        while (!leaves.empty()) {
            const int v = leaves.back();
            leaves.pop_back();
            for (const int u: adj[v]) {
                in_edges[u]--;
                if (in_edges[u] == 1)
                    leaves.push_back(u);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            const auto& e = edges[i];
            if (in_edges[e[0]-1] > 1 && in_edges[e[1]-1] > 1)
                return e;
        }
        return {};
    }
};