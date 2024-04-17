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


    ListNode* add(ListNode* first, ListNode* second){
        ListNode* head = NULL , * tail = NULL;
        int carry =0;
        while(first != NULL || second != NULL || carry!=0){
            int val1 =0;
            if(first !=NULL){
                val1 = first -> val;
            }
            int val2 =0;
            if(second !=NULL){
                val2 = second -> val;
            }
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            insertattail(head ,tail, digit);
            carry = sum/ 10;
            if(first != NULL)
                 first = first ->next;
                 
            if(second != NULL)
                 second = second -> next;
        }
        
        return head;
    }



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        //addd
        ListNode* ans = add(l1,l2);
        
        return ans;
    }
};