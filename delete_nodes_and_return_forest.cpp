// https://leetcode.com/problems/delete-nodes-and-return-forest/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* delNodesHelper(TreeNode* root, vector<int>& to_delete, vector<TreeNode*> &rootNodes) {
        if(root == NULL) {
            return NULL;
        }
        
        root->left = delNodesHelper(root->left, to_delete, rootNodes);
        root->right = delNodesHelper(root->right, to_delete, rootNodes);
        
        if(find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if(root->left != NULL) {
                rootNodes.push_back(root->left);
            }
            if(root->right != NULL) {
                rootNodes.push_back(root->right);
            }
            to_delete.erase(remove(to_delete.begin(), to_delete.end(), root->val), to_delete.end());
            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> rootNodes;
        if(find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) {
            rootNodes.push_back(root);
        }
        delNodesHelper(root, to_delete, rootNodes);
        return rootNodes;
    }
};