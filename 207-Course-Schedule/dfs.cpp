// Can also do topological sort for same complexity
// Big issue is the convergent case of a->b and a->c->b, which is still a valid DAG
// This is why we have to do dfs with stack mechanics, and not just a dfs for this approach

class Solution {
bool dfs(vector<vector<int>>& edges, vector<bool>& visited, int course) {
    if (edges[course].empty()) return true; // base case
    while (!edges[course].empty()) {
        const int pre = edges[course].back();
        edges[course].pop_back(); // remove visited edges
        if (visited[pre]) return false; // cycle
        visited[pre] = true;
        if (!dfs(edges, visited, pre)) return false;
        visited[pre] = false; // avoid the (valid) convergence case, i.e. a->b and a->c->b
    }
    return true; // all edges were checked
}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<vector<int>> edges(numCourses);
        for (const auto& edge: prerequisites) {
            edges[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            visited[i] = true;
            if (!dfs(edges, visited, i)) return false;
            visited[i] = false;
        }
        return true;
    }
};
