#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pb push_back
#define enl cout<<"\n"

using namespace std;

struct Node{
    int data;
    vector<Node*> children; 
};

Node* constructTree(vector<int> &arr){
    Node* root;
    stack<Node*> st;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==-1) 
            st.pop();
        else{
            Node* node=new Node;
            node->data=arr[i];
            if(st.size())
                st.top()->children.pb(node);
            else
                root=node;
            st.push(node);
        }
    }
    return root;
}

void printTree(Node* root){
    cout<<root->data<<" -> ";
    for(Node* node : root->children)
        cout<<node->data<<", ";
    cout<<".\n";
    for(Node* node : root->children)
        printTree(node);
}

int size(Node* root){
    int ans=0;
    for(Node* node : root->children)
        ans+=size(node);
    return ans+1;
}
int maxx(Node* root){
    int mx=root->data;
    for(Node* node : root->children)
        mx=max(mx,maxx(node));
    return mx;
}

int height(Node* root){
    int ht=-1;
    for(Node* node : root->children)
        ht=max(ht,height(node));
    return ht+1;
}

void traversals(Node* root){
    cout<<"Node Pre "<<root->data<<"\n";
    for(Node* node : root->children){
        cout<<"Edge Pre "<<root->data<<"-"<<node->data<<"\n";
        traversals(node);
        cout<<"Edge post "<<root->data<<"-"<<node->data<<"\n";
    }
    cout<<"Node Post "<<root->data<<"\n";
}

void BFS(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        int c=q.size();
        for(int i=0;i<c;i++){
            Node* node=q.front();
            q.pop();
            cout<<node->data<<" ";
            for(Node* child : node->children)
                q.push(child);
        }
        cout<<"\n";
    }
}

void mirrorTree(Node* root){
    for(int i=0;i<root->children.size()/2;i++){
        Node* tt=root->children[i];
        root->children[i]=root->children[root->children.size()-1-i];
        root->children[root->children.size()-1-i]=tt;
    }
    for(Node* node : root->children)
        mirrorTree(node);
}

void removeLeaves(Node* root){
    for(int i=root->children.size()-1;i>=0;i--){
        if(root->children[i]->children.size()==0)
            root->children.erase(root->children.begin()+i);
    }
    for(Node* node : root->children)
        removeLeaves(node);
}

Node* tail(Node* root){
    if(root->children.size()==0)
        return root;
    while(root->children.size())
        root=tail(root->children[0]);
    return root;
}

void linearize(Node* root){
    for(int i=root->children.size()-1;i>=1;i--){
        linearize(root->children[i]);
        linearize(root->children[i-1]);
        root->children.erase(root->children.begin()+i);
        tail(root->children[i-1])->children.pb(root->children[i]);
    }
    for(Node* node : root->children)
        linearize(node);
}
bool DFS(Node* root,int data){
    if(root->data==data)
        return 1;
    for(Node* child : root->children){
        if(DFS(child,data)) return 1;
    }
    return 0;
}
vector<int> nodeToRootPath(Node* root,int data){
    if(root->data==data){
        vector<int> v;
        v.pb(data);
        return v;
    }
    for(Node* child : root->children){
        vector<int> v=nodeToRootPath(child,data);
        if(v.size()){
            v.pb(root->data);
            return v;
        }
    }
    return vector<int>();
}
int lowestCommonAncestor(Node* root,int data1,int data2){
    vector<int> v1=nodeToRootPath(root,data1);
    vector<int> v2=nodeToRootPath(root,data2);
    reverse(v1.begin(),v1.end()),reverse(v2.begin(),v2.end());
    for(int i=v1.size()-1,j=v2.size()-1;i>=0 && j>=0;i--,j--){
        if(v1[i]==v2[i])
            return v1[i];
    }
    return root->data;
}
int distanceBetTwoNodes(Node* root,int data1,int data2){
    vector<int> v1=nodeToRootPath(root,data1);
    vector<int> v2=nodeToRootPath(root,data2);
    reverse(v1.begin(),v1.end()),reverse(v2.begin(),v2.end());
    int ans=0;
    for(int i=v1.size()-1,j=v2.size()-1;i>=0 && j>=0;i--,j--){
        if(v1[i]==v2[i]){
            ans=i+1;
            break;
        }
    }
    return v1.size()+v2.size()-2*ans;
}

int main(){
    fio;
    int n;
    cin>>n;
    vector<int> tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    int data1,data2;
    cin>>data1>>data2;
    Node *root=constructTree(tree);
    cout<<distanceBetTwoNodes(root,data1,data2);
    
}