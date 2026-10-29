
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;

            // Find the insertion position.
            ListNode* prev = &dummy;

            while (prev->next &&
                   prev->next->val <= curr->val) {
                prev = prev->next;
            }

            // Insert curr into the sorted list.
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy.next;
    }
};
