class Solution {
public:

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        // Put head of every non-empty list
        // into the min heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Add it to answer
            tail->next = node;
            tail = tail->next;

            // Add next node from same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};