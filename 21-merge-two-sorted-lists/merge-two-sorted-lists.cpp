class Solution {
public:
    ListNode* solve(ListNode* &list1,ListNode* &list2){
        ListNode* curr1 = list1;
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = list2;
        ListNode* next2 = list2 -> next;
        while(next1 != NULL && curr2!= NULL){
            if(curr2->val >= curr1 -> val && curr2->val <= next1 -> val){
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1;
                curr1 = curr2;
                curr2 = next2;

            }else{
                curr1 = next1;
                next1 = next1 -> next;
            }
        }
        if(next1 == NULL){
            curr1 -> next = curr2;
        }
    return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;

     if(l1 == NULL)
            return list2;
     if(l2 == NULL)
            return list1;
        
    while(l1 != NULL && l2!=NULL){
     if(l1 -> val < l2 -> val){
       return solve(list1, list2);
     }else if(l1 -> val > l2 -> val){
       return solve(list2, list1);
     }else if(l1 -> val == l2 -> val){
        l1 = l1 -> next;
        l2 = l2 -> next;
         return solve(list2, list1);
     }
        }
        return list1;
    }
};