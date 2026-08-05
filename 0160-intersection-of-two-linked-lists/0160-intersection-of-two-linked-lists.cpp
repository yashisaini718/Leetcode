/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int listLen(ListNode* head){
        int cnt = 1;
        while(head != NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = listLen(headA);
        int lenB = listLen(headB);

        int diff = abs(lenA - lenB);

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        int counter =0;
        if (lenA > lenB){
            while (counter < diff){
                counter++;
                ptrA = ptrA->next;
            }
        }
        else {
            while (counter < diff){
                counter++;
                ptrB = ptrB->next;
            }

        }
       
        while(ptrA != NULL && ptrB != NULL){
            if (ptrA == ptrB) return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        
        return NULL;
    }
};