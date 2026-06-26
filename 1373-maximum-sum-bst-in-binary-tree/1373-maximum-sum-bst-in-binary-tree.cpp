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
    struct Info{
    bool isBST;
    int min_val;
    int max_val;
    int sum;

    Info(bool BST, int mn, int mx, int s){
        isBST = BST;
        min_val = mn;
        max_val = mx;
        sum = s;
    }
};
public:
    int ans = 0;
    int currSum = 0;
    Info dfs(TreeNode* root){
        if(root == NULL) return Info(true, INT_MAX, INT_MIN, 0);
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        if(left.isBST && right.isBST && left.max_val < root->val && right.min_val > root->val){
            currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);
            return Info(true, min(root->val, left.min_val), max(root->val, right.max_val), currSum);
        }
        return Info(false, INT_MAX, INT_MIN, 0);
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};