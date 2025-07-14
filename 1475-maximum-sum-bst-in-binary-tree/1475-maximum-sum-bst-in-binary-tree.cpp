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
 class Node{
    public:
    int maxsum;
    int maxval;
    int minval;
    Node(int ms,int mx,int mi){
        maxsum=ms;
        maxval=mx;
        minval=mi;
    }
 };
class Solution {
    public:
    int res=0;
    Node helper(TreeNode* root){
        if(!root)
        return Node(0,INT_MIN,INT_MAX);
        auto left = helper(root->left);
        auto right = helper(root->right);
        if((root->val>left.maxval) && (root->val<right.minval)){
            int s = root->val+left.maxsum+right.maxsum;
            res=max(s,res);
            return Node(s,max(root->val,right.maxval),min(root->val,left.minval));
        }
        return Node(max(left.maxsum,right.maxsum),INT_MAX,INT_MIN);
    }
    int maxSumBST(TreeNode* root) {
        helper(root).maxsum;
        return res;
    }
};