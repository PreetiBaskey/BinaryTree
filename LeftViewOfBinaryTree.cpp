//DFS + pre order traversal

class Solution {
  public:
    void solve(Node* root, vector<int> &result, int level) {
        if(root == NULL) {
            return;
        }
        
        if(result.size() == level) {
            result.push_back(root->data);
        }
        
        solve(root->left, result, level + 1);
        solve(root->right, result, level + 1);
    }
    vector<int> leftView(Node *root) {
        vector<int> result;
        
        if(root == NULL) {
            return result;
        }
        
        solve(root, result, 0);
        
        return result;
    }
};






//BFS + level order traversal

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> result;
        
        if(root == NULL) {
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                Node* frontNode = q.front();
                q.pop();
                
                if(i == 0) {
                    result.push_back(frontNode->data);
                }
                
                if(frontNode->left != NULL) {
                    q.push(frontNode->left);
                }
                
                if(frontNode->right != NULL) {
                    q.push(frontNode->right);
                }
            }
        }
    }
};
