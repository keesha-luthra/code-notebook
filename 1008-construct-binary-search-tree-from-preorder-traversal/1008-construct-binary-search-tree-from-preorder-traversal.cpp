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
    int idx = 0;
    TreeNode* build(vector<int>& preorder, long long mini, long long maxi){
        if(idx == preorder.size()) return NULL;
        int val = preorder[idx];
        if(val <= mini || val >= maxi) return NULL;
        idx++;
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, mini, val);
        root->right = build(preorder, val, maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, LLONG_MIN, LLONG_MAX);
    }
};