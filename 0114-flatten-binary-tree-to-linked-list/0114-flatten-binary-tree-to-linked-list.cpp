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
    // TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        // if(root == NULL) return;
        // flatten(root->right);
        // flatten(root->left);
        // root->right = prev;
        // root->left = NULL;
        // prev = root;

        // stack<TreeNode*> st;
        // if(root) st.push(root);
        // TreeNode* curr = NULL;
        // while(!st.empty()){
        //     curr = st.top();
        //     st.pop();
        //     if(curr->right) st.push(curr->right);
        //     if(curr->left) st.push(curr->left);
        //     if(!st.empty()){
        //         curr->right = st.top();
        //         curr->left = NULL;
        //     }
        // }

        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while(curr != NULL){
            if(curr->left){
                prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};