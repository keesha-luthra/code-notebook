
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* level = root;

        while (level->left != nullptr) {
            Node* curr = level;

            while (curr != nullptr) {
                // Connect siblings
                curr->left->next = curr->right;

                // Connect children of adjacent parents
                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            // Move to the next level
            level = level->left;
        }

        return root;
    }
};
