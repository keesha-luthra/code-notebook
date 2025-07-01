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
bool func(TreeNode* left, TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right) return NULL;
    if(left->val != right->val) return false;
    else{
        return func(left->left, right->right) && func(left->right, right->left);
    }
    return true;
}
public:
    bool isSymmetric(TreeNode* root) {
        return func(root->left, root->right);
    }
};