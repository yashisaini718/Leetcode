/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>Nodes;
        ListNode *ptr = headA;
        while(ptr != NULL){
            Nodes[ptr]=1;
            ptr = ptr->next;
        }
        ptr = headB;
        while(ptr != NULL){
            if (Nodes.find(ptr) != Nodes.end()) return ptr;
            ptr = ptr->next;
        }
        return NULL;
    }
};