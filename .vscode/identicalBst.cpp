#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
            int data;
            Node*left;
            Node* right;
            Node(int val){
                data= val;
                left=NULL;
                right=NULL;

            }
};
static int idx=-1;
Node* buildTree(vector<int> nodes){
        idx++;
        if(nodes[idx]==-1){
            return NULL;
        }
        Node* root=new Node(nodes[idx]);
        root ->left=buildTree(nodes);
        root->right=buildTree(nodes);
}

bool identicalBst(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    
    return identicalBst(root1->left,root2->left) && identicalBst(root1->right,root2->right)&& (root1->data==root2->data);
}

int main(){
    vector<int> nodes1={10,20,40,-1,-1,50,-1,-1,30,60,-1,-1,70,-1,-1};
    vector<int> nodes2={10,20,40,-1,-1,50,-1,-1,30,60,-1,-1,70,-1,-1};
    Node* root1=buildTree(nodes1);
    //idx=-1;
    Node* root2=buildTree(nodes2);

    if(identicalBst(root1,root2)){
        cout<<"The two BSTs are identical"<<endl;
    }
    else{
        cout<<"The two BSTs are not identical"<<endl;
    }

    return 0;
}