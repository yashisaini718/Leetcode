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
    ListNode* reverseHelper(ListNode* head, ListNode* ptr, ListNode* prev){
        if (head == NULL) return prev;
        ptr = head->next;
        head->next = prev;
        prev = head;
        head = ptr;
        return reverseHelper(head, ptr, prev);
    }
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* ptr = NULL;
       ListNode* prev = NULL;
       return reverseHelper(head, ptr, prev);
    }
};