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
    void inorder(TreeNode* root,vector<int>& ino){
        if(root == NULL) return;
        inorder(root->left,ino);
        ino.push_back(root->val);
        inorder(root->right,ino);
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int> ino;
       inorder(root,ino);
       return ino[k-1];
        
    }
};