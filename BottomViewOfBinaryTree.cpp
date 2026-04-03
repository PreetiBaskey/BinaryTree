// BFS + level order traversal

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        
        if(root == NULL) {
            return result;
        }
        
        queue<pair<Node*, int>> q; //node, horizontal value
        map<int, Node*> mp; //horizontal value, node
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto frontData = q.front();
            q.pop();
            
            Node* node = frontData.first;
            int hValue = frontData.second;
            
            mp[hValue] = node;
            
            if(node->left != NULL) {
                q.push({node->left, hValue - 1});
            }
            
            if(node->right != NULL) {
                q.push({node->right, hValue + 1});
            }
        }
        
        for(auto &it: mp) {
            Node* temp = it.second;
            
            result.push_back(temp->data);
        }
        
        return result;
    }
};
