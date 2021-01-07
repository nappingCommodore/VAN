// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* searchNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val == key) {
            return root;
        }
        if(root->val > key) {
            return searchNode(root->left, key);
        } else {
            return searchNode(root->right, key);
        }
        
    }
    
    struct TreeNode * minValueNode(struct TreeNode* node) { 
        struct TreeNode* current = node; 

        while (current && current->left != NULL) 
            current = current->left; 

        return current; 
    } 
  
    
    TreeNode* deleteNodeUtil(TreeNode* root, int key) {
        
        if (root == NULL) return root; 
  
        if (key < root->val) 
            root->left = deleteNodeUtil(root->left, key); 
  
  
        else if (key > root->val) 
            root->right = deleteNodeUtil(root->right, key); 
        else {
            if (root->left == NULL)
            { 
                struct TreeNode *temp = root->right;
                return temp; 
            } 
            else if (root->right == NULL) 
            { 
                struct TreeNode *temp = root->left;
                return temp; 
            }

             struct TreeNode* temp = minValueNode(root->right); 


            root->val = temp->val; 


            root->right = deleteNode(root->right, temp->val); 
        }
        return root;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) {
            return root;
        }
        return deleteNodeUtil(root, key);
    }
};