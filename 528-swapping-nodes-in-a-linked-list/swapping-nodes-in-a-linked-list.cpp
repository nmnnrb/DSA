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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0 ;
        ListNode * curr = head;
        while(curr){
            count++;
            curr = curr -> next;
        }
        int n = count - k +1;
        count = 1;
        ListNode* begin = NULL;
        ListNode* end = NULL;
        curr = head;
        while(curr){
            if(count ==k){
                begin= curr;
            }

            if(count == n){
                end = curr;
            }

            count++;
            curr = curr -> next;
        }
    swap(begin -> val, end ->val);
    return head;
    }
};