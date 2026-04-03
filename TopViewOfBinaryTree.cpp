// BFS + level order traversal

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> result;
        
        if(root == NULL) {
            return result;
        }
        
        queue<pair<Node*, int>> q; //node, vertical value
        map<int, Node*> mp;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto frontData = q.front();
            q.pop();
            
            Node* node = frontData.first;
            int vValue = frontData.second;
            
            if(!mp.count(vValue)) {
                mp[vValue] = node;
            }
            
            if(node->left != NULL) {
                q.push({node->left, vValue - 1});
            }
            
            if(node->right != NULL) {
                q.push({node->right, vValue + 1});
            }
        }
        
        for(auto &it: mp) {
            Node* temp = it.second;
            result.push_back(temp->data);
        }
    }
};
