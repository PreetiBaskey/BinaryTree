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

void inOrder(node* root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main() {
    
    node* root = NULL;
    node* updatedRoot = createTree(root);
    cout<<"InOrder traversal is :- ";
    inOrder(updatedRoot);
    
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

void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    
    stack<Node*> st;
    Node* curr = root;
    
    while(curr != NULL || !st.empty()) {
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        
        curr = st.top();
        st.pop();
        
        cout<<curr->data<<" ";
        
        curr = curr->right;
    }
}

int main() {
    
    Node* root = NULL;
    Node* updatedRoot = createTree(root);
    cout<<"Inorder traversal is :- ";
    inOrder(updatedRoot);
    
    return 0;
}
