
class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pq;

        // Add the head of each non-empty list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            // Get the smallest current node
            ListNode* node = pq.top();
            pq.pop();

            // Append it to the result
            tail->next = node;
            tail = node;

            // Add the next node from the same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        tail->next = nullptr;
        return dummy.next;
    }
};