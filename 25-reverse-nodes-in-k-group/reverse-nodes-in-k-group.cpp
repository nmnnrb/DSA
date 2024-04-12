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
    int getLength(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = getLength(head);
        if(head == NULL || head -> next == NULL){
            return head;
        }
         int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while(curr != NULL && count < k){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
            length--;
        }
         if(length < k){
            head -> next = curr;
            return prev;
        }

        if(forward != NULL && length >=k){
            head -> next = reverseKGroup(forward, k);
        }
       
        return prev;
    }
};