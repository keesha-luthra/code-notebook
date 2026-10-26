
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(TreeNode* root, int remaining) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);
        remaining -= root->val;

        // Check only at a leaf
        if (root->left == nullptr &&
            root->right == nullptr) {
            if (remaining == 0) {
                result.push_back(path);
            }
        } else {
            dfs(root->left, remaining);
            dfs(root->right, remaining);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        path.clear();

        dfs(root, targetSum);

        return result;
    }
};
