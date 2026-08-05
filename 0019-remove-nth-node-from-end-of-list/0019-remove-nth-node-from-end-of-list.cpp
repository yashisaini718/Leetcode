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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // using fast two step for each single step of slow gives the slow in the middle of the ll so for each single step of slow if fast goes n steps then slow will automatically point to desired location
        // the above is wrong instead initially only , fast is placed n places ahead of slow and both moves one step at a time hence when fast reaches end slow automatically goes to L-N position
        if (!head || !head->next) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        int cnt = 0;
        while(fast != NULL && cnt != n){
            fast= fast->next;
            cnt++;
        }
        if (fast == NULL){
            ListNode *temp = slow;
            slow = slow->next;
            delete temp;
            return slow;
        }
        while (fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};