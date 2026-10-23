class Solution {
public:
    ListNode* reverseBetween(
        ListNode* head, int left, int right
    ) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Move to the node before position left.
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // Reverse the selected section in-place.
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;

            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
    }
};