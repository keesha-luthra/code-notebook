class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees =
                generate(start, rootVal - 1);

            vector<TreeNode*> rightTrees =
                generate(rootVal + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);

                    root->left = left;
                    root->right = right;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};

        return generate(1, n);
    }
};