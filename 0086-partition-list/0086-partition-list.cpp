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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy, *ptr = head, *prev = NULL;
        if ( head == NULL) return NULL;
        while(ptr != NULL){
            if( ptr -> val >= x && prev){
                prev -> next = ptr -> next;
                curr -> next = ptr;
                curr = curr -> next;
                ptr = prev -> next; 
            }
            else if( ptr -> val >= x){
                head = head -> next;
                curr -> next = ptr;
                curr = curr -> next;
                ptr = head;
            }
            else{
                prev = ptr;
                ptr = ptr->next;
            }
        }
        curr->next = NULL;
        if (prev) prev->next = dummy -> next;
        else return dummy -> next;
        return head;
    }
};