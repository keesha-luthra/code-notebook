class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Comparator for a min-heap:
        // The node with the smallest value has highest priority
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Create a min-heap of ListNode pointers
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype(cmp)
        > minHeap(cmp);

        // Add the first node of every non-empty linked list
        for (ListNode* node : lists) {
            if (node != nullptr) {
                minHeap.push(node);
            }
        }

        // Dummy node simplifies construction of the result list
        ListNode dummy(0);

        // Tail always points to the last node in the merged list
        ListNode* tail = &dummy;

        // Continue until all nodes have been processed
        while (!minHeap.empty()) {

            // Get the smallest available node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Attach this node to the result list
            tail->next = smallest;

            // Move the tail forward
            tail = tail->next;

            // Add the next node from the same list, if it exists
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        // Return the merged list, skipping the dummy node
        return dummy.next;
    }
};