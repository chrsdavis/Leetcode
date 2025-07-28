// See: https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm
//
// Basically, maintain a set of nodes with no (unprocessed) pre-reqs (no in-degrees).
// Then, pop one off and append to answer. Check all of it's adjacency list and remove all edges from that node.
// If any previouisly adjacent element now has in-degree zero, then add it to the set.
// If any node still has positive in-degree (i.e. any edge still exists), then there's a cycle.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        for (const auto& edge: prerequisites) {
            edges[edge[1]].push_back(edge[0]);
        }
        vector<int> in_degree(numCourses, 0);
        for (int course = 0; course < numCourses; course++) {
            for (int c: edges[course]) {
                in_degree[c]++;
            }
        }
        vector<int> roots;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0)
                roots.push_back(i);
        }
        vector<int> ans;
        while (!roots.empty()) {
            const int course = roots.back();
            roots.pop_back();
            ans.push_back(course);
            for (int c: edges[course]) {
                --in_degree[c];
                if (in_degree[c] == 0) // only add if no more pre-reqs
                    roots.push_back(c);
            }
        }
        // If we're unable to add a course to `roots`, then there is a cycle
        return ans.size() == numCourses ? ans : vector<int>{}; // check for cycle
    }
};