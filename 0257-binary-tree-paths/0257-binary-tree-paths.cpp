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
void helper(TreeNode* root,vector<string>& result,string curr){
    if(root == NULL) return;
    if(curr.empty()) curr+=to_string(root->val);
    else curr+="->"+to_string(root->val);
    if(root->left == NULL && root->right==NULL){
        result.push_back(curr);
        return;
    }
    helper(root->left,result,curr);
    helper(root->right,result,curr);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(root == NULL) return result;
        helper(root,result,"");
        return result;
        
    }
};