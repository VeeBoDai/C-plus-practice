#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


typedef struct BstNode{
	int key;
	BstNode *left,*right;
	BstNode(int k){
		key = k;
		left=right=NULL;
	}
}*pNode,sNode;

int a[]={34,22,98,36,8,12,9,40,23,93,9,6};

void InsertToBstTree(pNode &p, int k)
{
	if(NULL == p){
		p = new BstNode(k);
		return;
	}else if(k == p->key){
		return;
	}else if(k < p->key){
		InsertToBstTree(p->left,k);
	}else{
		InsertToBstTree(p->right,k);
	}
}


void InOrderTree(pNode p)
{
	if(p){
		InOrderTree(p->left);
		cout<<p->key<<endl;
		InOrderTree(p->right);
	}
}

int findn = 0;
pNode FindNode(pNode r,int k, pNode &pare)
{
	findn++;
	if(NULL==r){
		return NULL;
	}
	if(r->key == k){
		cout<<"exists,find times:"<<findn<<",key:"<<r->key<<endl;
		return r;
	}else if(r->key > k){
		return FindNode(r->left,k,r);
	}else{
		return FindNode(r->right,k,r);
	}
}

void DelNode(pNode &r,int k)
{
	if(NULL == r){
		return;
	}
	if(k < r->key){
		DelNode(r->left,k);
	}else if(k > r->key){
		DelNode(r->right,k);
	}else{
		if(NULL == r->left && NULL == r->right){
			delete r;
			r = NULL;
		}else if(NULL == r->left){
			pNode temp = r;
			r = r->right;
			delete temp;
			temp = NULL;
		}else if(NULL == r->right){
			pNode temp = r;
			r = r->left;
			delete temp;
			temp = NULL;
		}else{
			pNode pare = r;
			pNode p = r->left;
			while(p->right){
				pare = p;
				p=p->right;
			}
			r->key = p->key;
			if(p == r->left){
				r->left = p->left;
			}else{
				pare->right=p->left;
			}

			delete p;
			p = NULL;
		}
	}
}


int main()
{
	pNode root = NULL;
	for(int i = 0; i < 12; i++){
		InsertToBstTree(root,a[i]);
	}

	InOrderTree(root);
	pNode pare=NULL;
	pNode pf = FindNode(root,93,pare);
	DelNode(root,36);
	cout<<"after del 9"<<endl;
	InOrderTree(root);
	cout<<"test"<<endl;
	return 0;
}
