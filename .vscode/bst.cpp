#include <bits/stdc++.h>
using namespace std;




class Node{
    public:
            int data;
            Node* left;
            Node* right;
            Node(int val){
                data = val;
                left = NULL;
                right = NULL;
            }

    };

static int idx=-1;
Node* buildTree(vector<int> nodes){
        idx++;
        if(nodes[idx]==-1){
            return NULL;
         }
        Node* root= new Node(nodes[idx]);
        root->left=buildTree(nodes);
        root->right=buildTree(nodes);
        return root;

    }
    int height(Node* root){
        if(root==NULL){
            return 0;

        }
        int leftHt= height(root->left);
        int rightHt= height(root->right);
        return max(leftHt,rightHt)+1;
    }
    int count(Node* root){
        if(root==NULL){
            return 0;
        }
        return count(root->left)+count(root->right)+1;
    }

    int sum(Node* root){
        if(root==NULL){
            return 0;
        }
        return sum(root->left)+sum(root->right)+root->data;
    }
    /* void levelOrder(Node* root){
        
        if(root==NULL){
            return;
        
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            
        Node* curr=q.front();
        q.pop();
       
        
        if(curr==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
                continue;
                
            }
            else{
                break;
            }
        }
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
         if(curr->right!=NULL){
            q.push(curr->right);
        }
        
        
        
    }
   
    } */
   /* void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
   } */
/* void preOrder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

} */

int main(){
    vector<int> nodes={10,20,40,-1,-1,50,-1,-1,30,60,-1,-1,70,-1,-1};
    Node* root=buildTree(nodes);
    //preOrder(root);
    //inOrder(root);
    //postOrder(root); 
    //levelOrder(root);
    cout<<height(root);
    cout<<endl;
    cout<<count(root);
    cout<<endl;
    cout<<sum(root);
    return 0;

}


