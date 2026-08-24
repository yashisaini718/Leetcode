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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>mpp;
        ListNode *ptr = head;
        while(ptr != NULL){
            mpp[ptr -> val]++; 
            ptr = ptr->next;
        }
        vector<int>single;
        for (auto &it : mpp){
            if (it.second == 1){
                single.push_back(it.first);
            }
        }
        for(int ele : single){
            mpp.erase(ele);
        }
        ptr = head;
        ListNode *prev = NULL;
        ListNode *dummy = new ListNode(0);
        while(ptr != NULL){
            if (mpp.find(ptr->val) != mpp.end() && prev){
                prev->next = ptr->next;
                ListNode *tmp = ptr;
                delete(tmp);
                ptr = prev->next;
            }
            else if (mpp.find(ptr->val) != mpp.end()){
                dummy->next = ptr->next;
                ListNode *tmp = ptr;
                delete(tmp);
                head = dummy->next;
                ptr = dummy->next;
            }
            else{
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return head;
        delete (dummy);
        
    }
};