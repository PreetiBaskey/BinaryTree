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
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode->left != NULL) {
                    q.push(frontNode->left);
                }
                if(frontNode->right != NULL) {
                    q.push(frontNode->right);
                }
            }
            result++;
        }

        return result; 
    }
};
