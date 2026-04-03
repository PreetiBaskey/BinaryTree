//Recursive approach

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        
        node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

node* createTree(node* root) {
    int data;
    cout<<"Enter data [Enter -1 for NULL] :- ";
    cin>>data;
    if(data == -1) {
        return NULL;
    }
    root = new node(data);
    cout<<"Enter left data of "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"Enter right data of "<<data<<endl;
    root->right = createTree(root->right);
    
    return root;
}

void preOrder(node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    
    node* root = NULL;
    node* updatedRoot = createTree(root);
    cout<<endl<<"Pre order traversal is :- ";
    preOrder(updatedRoot);
    
    return 0;
}





//Iterative approach

#include<iostream>
#include<stack>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree(Node* root) {
    int data;
    cout<<"Enter data [Enter -1 to end] :- ";
    cin>>data;
    if(data == -1) {
        return NULL;
    }
    root = new Node(data);
    cout<<"Enter left data of "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"Enter right data of "<<data<<endl;
    root->right = createTree(root->right);
    
    return root;
}

void preOrder(Node* root) {
    if(root == NULL) return;
    
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty()) {
        Node* curr = st.top();
        st.pop();
        
        cout << curr->data << " ";
        
        // Push RIGHT first
        if(curr->right) {
            st.push(curr->right);
        }
        
        // Push LEFT second (so it's popped first)
        if(curr->left) {
            st.push(curr->left);
        }
    }
}


int main() {
    
    Node* root = NULL;
    Node* updatedRoot = createTree(root);
    cout<<"Preorder traversal is :- ";
    preOrder(updatedRoot);
    
    return 0;
}
