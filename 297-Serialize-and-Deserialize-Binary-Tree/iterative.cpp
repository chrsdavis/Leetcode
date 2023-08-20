#include "util/common.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial = "";
        if(!root) return serial;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(!node) {
                serial += "null,";
                continue;
            }
            serial += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        // split string by comma
        istringstream ss(data);
        string buffer;
        // get root val
        getline(ss, buffer, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(buffer));
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // left child
            getline(ss, buffer, ',');
            if(buffer != "null")
            {
                node->left = new TreeNode(stoi(buffer));
                q.push(node->left);
            }

            // right child
            getline(ss, buffer, ',');
            if(buffer != "null")
            {
                node->right = new TreeNode(stoi(buffer));
                q.push(node->right);
            }
        }
        return root;
    }
};

// 0 -> 1,2
// 1 -> 3,4
// 2 -> 5,6 = x * 2 + 1, x * 2 + 2
