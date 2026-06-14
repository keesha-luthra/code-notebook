/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }
    ListNode* find_Kth_Node(ListNode* node, int k){
        k--;
        ListNode* temp = node;
        while(temp && k){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        ListNode* nextNode = NULL;
        ListNode* K = NULL;
        while(temp){
            K = find_Kth_Node(temp, k);
            if(K == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            nextNode = K->next;
            K->next = NULL;
            reverse(temp);
            if(temp == head) head = K;
            else prevLast->next= K;
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};