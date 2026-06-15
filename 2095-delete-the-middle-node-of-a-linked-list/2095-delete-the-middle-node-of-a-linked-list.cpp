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
    ListNode* deleteMiddle(ListNode* head) {
        // first count n
        ListNode *ptr= head;
        int n=0;
        while(ptr != nullptr){
            n++;
            ptr=ptr->next;
        }
        if (n == 1) return nullptr;
        // use prev and curr pointrs to find the n/2 th node
        int pos=0;
        ptr=head;
        ListNode *prev=nullptr;
        while(pos < n/2){
            prev=ptr;
            ptr=ptr->next;
            pos++;
        }
        // ptr points to n/2 th node & prev points to previous node
        prev->next = ptr->next;
        delete (ptr);
        return head;
    }
};