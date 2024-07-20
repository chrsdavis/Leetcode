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
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> node_map;
        return node ? deep_copy(node, node_map) : nullptr;
    }

    Node* deep_copy(Node* root, unordered_map<int,Node*>& node_map) {
        if(node_map[root->val] != nullptr)
            return node_map[root->val];

        Node* new_node = new Node(root->val);
        node_map[root->val] = new_node;
        for(Node* node: root->neighbors) {
            new_node->neighbors.push_back(deep_copy(node, node_map));
        }
        return new_node;
    }
};