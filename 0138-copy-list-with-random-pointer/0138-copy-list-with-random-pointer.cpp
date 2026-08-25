/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ptr = head;
        map<Node*, Node*>mpp;
        while(ptr != NULL){
            mpp[ptr] = new Node(ptr->val);
            ptr = ptr -> next;
        }
        ptr = head;
        Node* curr = mpp[ptr];
        while( ptr != NULL){
            curr->next = mpp[ptr->next];
            curr->random = mpp[ptr->random];
            ptr = ptr -> next;
            curr = curr -> next;
        }
        return mpp[head];
    }
};