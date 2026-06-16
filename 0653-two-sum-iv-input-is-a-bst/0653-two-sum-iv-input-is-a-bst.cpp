/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// Approach 1: Inorder traversal → sorted vector → two pointers  TC: O(n) + O(n)
// Approach 2: For each node during traversal, search for (target - current value) in the BST (could be another traversal or binary search on the vector)  TC: O(n) +  O(nlogn)

    void inorder(TreeNode *root,vector<int>& temp){
        if (!root) return;
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        inorder(root, nodes);
        int i=0,j=nodes.size()-1;
        while(i<j){
            if (nodes[i]+nodes[j] == k) return true;
            else if (nodes[i]+nodes[j] > k) j--;
            else i++;
        }
        return false;
    }
};