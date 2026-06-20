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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        // (node, index)
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int levelSize = q.size();
            long long leftMost = q.front().second;
            long long rightMost = q.back().second;
            ans = max(ans, (int)(rightMost - leftMost + 1));
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front().first;
                long long currIndex = q.front().second;
                q.pop();
                long long normalizedIndex = currIndex - leftMost;
                if(node->left) q.push({node->left, 2 * normalizedIndex + 1});
                if(node->right) q.push({node->right, 2 * normalizedIndex + 2});
            }
        }
        return ans;
    }
};