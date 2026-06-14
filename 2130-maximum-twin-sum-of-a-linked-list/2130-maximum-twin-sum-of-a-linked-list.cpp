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
    // one way is to create a vector from the given list and then check for maximum sum pair 
    // the other is to make second list that would be the reverse of this list and then use two pointers to keep track of maximum sum pair
public:
    int pairSum(ListNode* head) {
        //clone original list
        ListNode* dummy = new ListNode(0);
        ListNode* newNode = dummy;
        ListNode* oldNode = head;
        while( oldNode != nullptr){
            newNode->next = new ListNode(oldNode->val);
            newNode = newNode->next;
            oldNode = oldNode->next;
        }
        // reverse the cloned list
        ListNode *clonedHead=dummy->next;
        delete dummy;
        ListNode *prev=nullptr;
        ListNode *ptr=clonedHead;
        while( ptr != nullptr){
            ptr=clonedHead->next;
            clonedHead->next=prev;
            prev=clonedHead;
            clonedHead=ptr;
        }
        ListNode *reverse=prev;
        int maxi=0;
        while(head != nullptr){
            maxi=max(maxi, head->val+reverse->val);
            head=head->next;
            reverse=reverse->next;
        }
        return maxi;
    }
};