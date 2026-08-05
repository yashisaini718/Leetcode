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
    ListNode *reverse(ListNode* head){
        ListNode *ptr, *prev = NULL;
        while(head != NULL){
            ptr = head->next;
            head->next = prev;
            prev = head;
            head = ptr;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return 0;

        // find the middle of the node
        int cnt = 0;
        ListNode *ptr = head;
        while (ptr != NULL){
            cnt++;
            ptr = ptr->next;
        }
        if (cnt == 1) return true;
 
        // get to the middle of the ll 
        int counter = 1;
        ptr = head;

        while (counter != cnt/2) {
            counter++;
            ptr = ptr->next;
        }

        // reverse the second half
        if (cnt & 1) {
            ptr= ptr->next;
        }
        ptr->next = reverse(ptr->next);
        
        // check if first half equal second half
        ptr = ptr->next;
        ListNode *temp = head;
        while( ptr != NULL){
            if (temp->val != ptr->val) return false;
            temp = temp->next;
            ptr = ptr->next;
        }

        return true;
    }
};