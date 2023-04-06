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
    unordered_map<int, int> hm;

    TreeNode* bulid(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd) {

        if(preStart > preEnd) return NULL;

        int rootVal = preorder[preStart];
        
        int index = hm[rootVal];

        int leftSize = index - inStart;

        TreeNode* root = new TreeNode(rootVal);
        root->left = bulid(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = bulid(preorder, preStart + leftSize + 1, preEnd,inorder, index+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            hm.insert({inorder[i], i});
        }

        return bulid(preorder, 0, preorder.size() - 1, inorder, 0, preorder.size() - 1);
    }
};
