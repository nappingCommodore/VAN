// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> result;
        vector<int> tmpArr;
        if(root != NULL) {
            Q.push(root);
            tmpArr.push_back(root->val);
            if(tmpArr.size() > 0)
                result.push_back(tmpArr);
        }
        tmpArr.clear();
        Q.push(NULL);
        while(!Q.empty()) {
            TreeNode* tmp = Q.front();
            Q.pop();
            if(tmp == NULL) {
                if(tmpArr.size() > 0)
                    result.push_back(tmpArr);
                tmpArr.clear();
                if(!Q.empty()) {
                    Q.push(NULL);
                }
            } else {
                if(tmp->left) {
                    tmpArr.push_back(tmp->left->val);
                    Q.push(tmp->left);
                }

                if(tmp->right) {
                    tmpArr.push_back(tmp->right->val);
                    Q.push(tmp->right);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};