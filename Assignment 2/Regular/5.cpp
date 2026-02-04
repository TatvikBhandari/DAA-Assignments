//huffman coding
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node{
    public:
    char c;
    int f;
    node *left,*right;
    node(char c1,int f1){
       c=c1;
       f=f1;
       left=right=nullptr;
    }
};
class compare{
    public:
    bool operator()(node *a,node *b){
        return a->f > b->f;
    }
};
class huffmantree{
    public:
    priority_queue<node *,vector<node *>,compare> pq;

    huffmantree(int n, char characters[], int frequencies[]){
    for(int i=0;i<n;i++){
        pq.push(new node(characters[i],frequencies[i]));
    }
    while(pq.size()>1){
        node* left=pq.top();pq.pop();
        node* right=pq.top();pq.pop();

        node* root=new node('\0',left->f+right->f);
        root->left=left;
        root->right=right;

        pq.push(root);
    }
    }
    
   void printCodes(node* root,string code){
    if (!root) return;

    if (!root->left && !root->right){
        cout<<root->c<<" "<<code<<endl;
    }
    printCodes(root->left,code+"0");
    printCodes(root->right,code+"1");
}
};

int main() {
    int n=6;
    char characters[]={'a','b','c','d','e','f'};
    int frequencies[]={5,9,12,13,16,45};
    
    huffmantree h(n,characters,frequencies);
    h.printCodes(h.pq.top(),"");
    return 0;
}