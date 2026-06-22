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

// Recursive
// class Solution {
// private:
// void inOrder(TreeNode* node, vector<int> &ans){
//     if(node == NULL) return;
//     inOrder(node->left, ans);
//     ans.push_back(node->val);
//     inOrder(node->right, ans);
// }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inOrder(root, ans);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // if(root == NULL) return ans;
        // TreeNode* temp = root;
        // stack<TreeNode*> st;
        // while(true){
        //     if(temp != NULL){
        //         st.push(temp);
        //         temp = temp->left;
        //     }
        //     else{
        //         if(st.empty()) break;
        //         temp = st.top();
        //         ans.push_back(temp->val);
        //         st.pop();
        //         temp = temp->right;
        //     }
        // }
        // return ans;

        // Morris traversal (Threaded Binary Tree)
        vector<int> answer;
        if(root == NULL) return answer;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL) {
                answer.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) prev = prev->right;
                // Create thread
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                // Remove thread
                else{
                    prev->right = NULL;
                    answer.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return answer;
    }
};