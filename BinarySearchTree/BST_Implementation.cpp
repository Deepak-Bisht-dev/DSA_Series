#include<bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};

Node* insertIntoBST(Node* &root, int d){
    // Base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root -> data){
        root -> right = insertIntoBST(root -> right, d);
    }
    else root -> left = insertIntoBST(root -> left, d);
    return root;
}

Node* minValue(Node* root){
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* maxValue(Node* root){
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    // base case
    if(root == NULL) return root;
    if(root -> data == val){
        // 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> right != NULL && root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child
        if(root -> left != NULL && root -> right != NULL){
            int mini = minValue(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }

    }
    else if(root -> data > val){
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else{
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // purana level complete traversed ho gya
            cout << endl;
            if(!q.empty()) // queue still has some child 
                q.push(NULL);
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}

void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}


void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

void takeInput(Node* &root){

    int data; cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }   
}

int main(){
    
    Node* root = NULL;
    cout << "Enter data to create BST " << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    cout << "Printing inOrder Traversal" << endl;
    inOrder(root);
    cout << endl << "Printing preOrder Traversal" << endl;
    preOrder(root);
    cout << endl << "Printing postOrder Traversal" << endl;
    postOrder(root);

    cout << endl << "Min Value is : " << minValue(root) -> data << endl;
    cout << "Max Value is : " << maxValue(root) -> data << endl;

    return 0;
}