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

//approach - 1 - using BFS + level order traversal
//time complexity - O(n) - number of nodes in binary tree
//space complexity - O(w) - maximum width of binary tree
//                        - if binary tree is skewed, then O(1)
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> result;

//         if(root == NULL) {
//             return result;
//         }

//         TreeNode* curr = root;

//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()) {
//             int len = q.size();

//             TreeNode* temp = NULL;
//             while(len--) {
//                 temp = q.front();
//                 q.pop();

//                 if(temp->left != NULL) {
//                     q.push(temp->left);
//                 }

//                 if(temp->right != NULL) {
//                     q.push(temp->right);
//                 }
//             }

//             result.push_back(temp->val);
//         }

//         return result;
//     }
// };




//approach - 2 - DFS + pre order traversal
//time complexity - O(n) - number of nodes of binary tree
//space complexity - O(h) - height of binary tree
//                 - O(logn) - if balanced tree
//                 - O(N) - if skewed tree
class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &result, int level) {
        if(root == NULL) {
            return;
        }

        if(result.size() < level) {
            result.push_back(root->val);
        }

        preOrder(root->right, result, level + 1);
        preOrder(root->left, result, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if(root == NULL) {
            return result;
        }

        preOrder(root, result, 1);

        return result;
    }
};
