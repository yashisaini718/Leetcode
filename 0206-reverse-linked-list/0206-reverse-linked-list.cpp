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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        stack<ListNode*>st;
        ListNode* ptr = head;
        
        while (ptr != NULL){
            st.push(ptr);
            ptr = ptr->next;
        }

        head = st.top();
        st.pop();
        ListNode* dummy = head;

        while(st.size()>0){
            dummy->next = st.top();
            st.pop();
            dummy = dummy->next;
        }

        dummy->next = NULL;
        return head;
    }
};