class Solution {
public:
    Node* copyRandomList(Node* head) {

        // If the original list is empty, return an empty list
        if (head == nullptr) {
            return nullptr;
        }

        // STEP 1: Interweave original nodes and their clones
        Node* curr = head;

        while (curr != nullptr) {

            // Create a clone with the same value as current node
            Node* clone = new Node(curr->val);

            // Save the next original node after the current one
            clone->next = curr->next;

            // Insert the clone directly after the original node
            curr->next = clone;

            // Move to the next original node
            // Skip the clone we just inserted
            curr = clone->next;
        }

        // STEP 2: Assign random pointers to the cloned nodes
        curr = head;

        while (curr != nullptr) {

            // The clone of the current node is right after it
            Node* clone = curr->next;

            // If the original node has a random pointer
            if (curr->random != nullptr) {

                // The clone of the random target is
                // immediately after that original target
                clone->random = curr->random->next;
            }

            // Move to the next original node
            curr = clone->next;
        }

        // STEP 3: Separate the original and cloned lists

        // Dummy node makes it easier to build the copied list
        Node* dummy = new Node(0);

        // Tail points to the last node in the copied list
        Node* copyTail = dummy;

        curr = head;

        while (curr != nullptr) {

            // Get the clone following the current original node
            Node* clone = curr->next;

            // Restore the original list by skipping the clone
            curr->next = clone->next;

            // Attach the clone to the copied list
            copyTail->next = clone;

            // Move the copied list's tail forward
            copyTail = clone;

            // Advance to the next original node
            curr = curr->next;
        }

        // Save the copied list's head
        Node* copiedHead = dummy->next;

        // Delete the temporary dummy node
        delete dummy;

        // Return the head of the deep-copied list
        return copiedHead;
    }
};