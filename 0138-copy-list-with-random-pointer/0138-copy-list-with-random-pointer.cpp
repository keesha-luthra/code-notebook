/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step 1 - insert copies in between the nodes
        Node* temp = head;
        while(temp){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        // step 2 - connect random pointers
        temp = head;
        Node* temp1 = NULL;
        while(temp){
            temp1 = temp->next;
            if(temp->random != NULL) temp1->random = temp->random->next;
            else temp->random = NULL;
            temp = temp->next->next;
        }
        
        // step 3 - extract the copy
        temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dummyNode->next;
    }
};