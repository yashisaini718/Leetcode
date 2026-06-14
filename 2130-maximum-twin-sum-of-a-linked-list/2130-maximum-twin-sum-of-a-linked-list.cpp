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
    int pairSum(ListNode* head) {
        vector<int>nodes;
        ListNode *ptr=head;
        while(ptr != nullptr){
            nodes.push_back(ptr->val);
            ptr=ptr->next;
        }
        int n= nodes.size();
        int maxi=0;
        for(int i=0;i<n/2;i++){
            maxi=max(maxi,(nodes[i]+nodes[n-1-i]));
        }
        return maxi;
    }
};