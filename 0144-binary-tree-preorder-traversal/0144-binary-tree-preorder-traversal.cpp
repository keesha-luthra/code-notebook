// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// Recursive
// class Solution {
// private:
// void preOrder(TreeNode* node, vector<int> &ans){
//     if(node == NULL) return;
//     ans.push_back(node->val);
//     preOrder(node->left, ans);
//     preOrder(node->right, ans);
// }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preOrder(root, ans);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // if(root == NULL) return ans;
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     TreeNode* temp = st.top();
        //     ans.push_back(temp->val);
        //     st.pop();
        //     if(temp->right != NULL) st.push(temp->right);
        //     if(temp->left != NULL) st.push(temp->left);
        // }
        // return ans;

        // Morris Preorder
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
                    answer.push_back(curr->val);
                    curr = curr->left;
                }
                // Remove thread
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return answer;
    }
};