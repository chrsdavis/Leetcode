/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    std::map<Node*, Node*> visited{};
    
    Node* _cloneGraph(Node* node) {
        if (visited.find(node) != visited.end())
            return visited[node];
            
        Node* node_copy = new Node(node->val);  
        visited.insert({node, node_copy});

        for (Node* nbr: node->neighbors) {
            (node_copy->neighbors).push_back(_cloneGraph(nbr));
        }

        return node_copy;
    }
    
    Node* cloneGraph(Node* node) {
        return (node ? _cloneGraph(node) : nullptr);
    }
};