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
    int ans = INT_MIN;
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int leftGain = max(helper(root->left), 0);
        int rightGain = max(helper(root->right), 0);

        ans = max(ans, root->val + leftGain + rightGain);

        return root->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
       helper(root);
       return ans;
    }
};