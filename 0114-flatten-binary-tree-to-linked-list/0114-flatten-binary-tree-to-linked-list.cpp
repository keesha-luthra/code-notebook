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
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        // flatten both subtrees
        flatten(root->left);
        flatten(root->right);

        // save original right subtree
        TreeNode* right = root->right;

        // move flattened left subtree to the right
        root->right = root->left;
        root->left = NULL;

         // Find the end of the flattened left subtree
        TreeNode* curr = root;
        while(curr->right != NULL){
            curr = curr->right;
        }
        
        // Attach original right subtree at the end         
        curr->right = right;
    }
};