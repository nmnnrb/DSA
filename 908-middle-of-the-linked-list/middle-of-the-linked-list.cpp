
class Solution {
public:
    int getand(ListNode* &head){
        ListNode* first = head;
        int leg = 0;
        while(first != NULL){
            leg++;
            first = first-> next;  
        }
        int ans = leg/2 + 1;
        return ans ;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int mid = getand(head);
        int i = 1;
        while(i < mid){
            temp = temp -> next;
            i++;
        }
        return temp;
    }
};