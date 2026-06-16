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

    // do an inorder traversal and check if it's sorted

    void inorder(TreeNode *root, vector<int> &result){
        if(!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        for(int i=1;i<nodes.size();i++){
            if(nodes[i-1]>=nodes[i]) return false;
        }
        return true;
    }
};