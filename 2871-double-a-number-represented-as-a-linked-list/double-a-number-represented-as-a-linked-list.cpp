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
ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL, *next = NULL;
        while(curr!= NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
}
ListNode* insertattail(ListNode* &head ,ListNode* &tail,int digit){
       ListNode* newnode = new ListNode(digit);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        ListNode* same = head;
        ListNode* ans = NULL, *tail = NULL;
        ListNode* first = reverse(head);
        ListNode* second = reverse(same);
        while(first != NULL || second!= NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                    val1 = first -> val;
            }
            int val2 = 0;
            if(first != NULL){
                    val2 = first -> val;
            }
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum/10;
            insertattail(ans,tail,digit);
            if(first != NULL)
                 first = first ->next;
                 
            if(second != NULL)
                 second = second -> next;
        }
      return reverse(ans);
    }
};