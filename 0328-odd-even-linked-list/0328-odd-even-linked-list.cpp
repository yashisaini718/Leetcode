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
    ListNode* oddEvenList(ListNode* head) {
        // dummy nodes defined
        ListNode odddummy; // direct objects
        ListNode evendummy;

        ListNode *odd = &odddummy, *even = &evendummy;
        // hence accessed using & for the pointer method

        int cnt = 1;
        ListNode *ptr = head;

        while(ptr != NULL){
            if (cnt & 1) {
                odd->next = ptr;
                odd = odd->next;
            }
            else{
                even->next = ptr;
                even = even->next;
            }
            ptr = ptr->next;
            cnt++;
        }

        odd->next= evendummy.next; // direct objects do not use pointer method -> hence requires .
        even ->next = NULL; // the last node now points to NULL instead of some other node 

        return odddummy.next; // first odd indiced nodes then even indiced
    }
};