class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // No left child: follow the right subtree.
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }

        // No right child: follow the left subtree.
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};