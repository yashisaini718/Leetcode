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

// APPROACH : store all the nodes in a multiset and use custom comaprator to store in sorted order then use dummy pointer to get all the nodes in order

struct CompareNodes{
    bool operator()(const ListNode *a, const ListNode *b) const { 
        return a->val < b->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*, CompareNodes>st;
        if (lists.size() == 0) return NULL;
        for(ListNode *head : lists){
            ListNode *ptr = head;
            while(ptr != NULL){
                st.insert(ptr);
                ptr = ptr -> next;
            }
        }
        ListNode dummy(0);
        ListNode *curr = &dummy;
        for(auto & itr : st){
            curr -> next = itr;
            curr = curr -> next;
        }
        curr -> next = nullptr;
        return dummy.next;
    }

};