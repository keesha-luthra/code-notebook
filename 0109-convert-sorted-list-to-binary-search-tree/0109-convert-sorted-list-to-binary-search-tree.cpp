class Solution {
private:
    ListNode* current;

    int getLength(ListNode* head) {
        int len = 0;

        while (head != nullptr) {
            len++;
            head = head->next;
        }

        return len;
    }

    TreeNode* buildTree(int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* leftSubtree = buildTree(left, mid - 1);

        TreeNode* root = new TreeNode(current->val);
        root->left = leftSubtree;

        current = current->next;

        root->right = buildTree(mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        current = head;

        int len = getLength(head);

        return buildTree(0, len - 1);
    }
};