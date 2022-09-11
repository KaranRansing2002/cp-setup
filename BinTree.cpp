#include <bits/stdc++.h>
#define enl cout<<"\n"
#define ll long long
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

struct Node{
	int data;
	Node* left=nullptr;
	Node* right=nullptr;
	Node(int data){
		this->data=data;
	}
};
int idx=0;
Node* constructTree(vector<int>& arr){
  if (idx == arr.size() || arr[idx] == INT_MIN){
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void printTree(Node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" -> ";
	if(root->left!=NULL) cout<<root->left->data<<" ";
	if(root->right!=NULL) cout<<root->right->data<<" ";
	enl;
	printTree(root->left);
	printTree(root->right);
}
int size,sum,mx,height;

void multisolver(Node* root,int depth){
	if(root==NULL)
		return;
	size++;
	sum+=root->data;
	mx=max(mx,root->data);
	height=max(height,depth);
	multisolver(root->left,depth+1);
	multisolver(root->right,depth+1);
}

int main(){
	fio;
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int x=INT_MIN;
		if(s!="n")
			x=stoi(s);
		v.pb(x);
	}
	Node* root=constructTree(v);
	multisolver(root,0);
	cout<<size<<"\n"<<sum<<"\n"<<mx<<"\n"<<height;
}