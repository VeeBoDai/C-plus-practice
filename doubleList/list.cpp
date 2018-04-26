#include <stdlib.h>
#include <iostream>

using namespace std;
typedef struct node_t
{
	int data;
	node_t *pre;
	node_t *next;
	node_t(int k):data(k),pre(NULL),next(NULL){}
}*pnode;

bool InsertPre(pnode pare, pnode r, int k){
	if(r == NULL){
		pnode temp = new node_t(k);
		temp->next = pare;
		pare->pre = temp;
		return true;
	}

	if(k >= r->data){
		pnode temp = new node_t(k);
		pare->pre = temp;
		temp->next = pare;
		temp->pre = r;
		r->next = temp;
	}else{
		return InsertPre(r, r->pre, k);
	}
	return true;
}


bool InsertNext(pnode pare, pnode r, int k){
	if(r == NULL){
		pnode temp = new node_t(k);
		temp->pre = pare;
		pare->next = temp;
		return true;
	}

	if(k <= r->data){
		pnode temp = new node_t(k);
		pare->next = temp;
		temp->pre = pare;
		temp->next = r;
		r->pre = temp;
	}else{
		return InsertNext(r, r->next, k);
	}
	return true;
}



bool Insert(pnode r, int k)
{
	if(NULL == r){
		return false;
	}
	if(k < r->data){
		return InsertPre(r, r->pre, k);
	}else{
		return InsertNext(r, r->next, k);
	} 
}

bool Creat(pnode &r)
{
	int ar[] = {1,4,3,7};
	r = new node_t(ar[0]);
	cout<<"arr size:"<<sizeof(ar)<<endl;
	for(int i=1; i< sizeof(ar)/sizeof(int); i++){
		Insert(r,ar[i]);
	}
}

void Pprelist(pnode r)
{	
	if(NULL == r){
		return;
	}
	
	cout<<r->data<<",addr:"<<r<<endl;
	Pprelist(r->pre);
}

void Pnextlist(pnode r)
{	
	if(NULL == r){
		return;
	}
	
	cout<<r->data<<",addr:"<<r<<endl;
	Pnextlist(r->next);
}

void Plist(pnode r)
{
	if(NULL == r){
		return;
	}

	Pprelist(r);
	Pnextlist(r->next);
	
}

bool Delet(pnode r, int k)
{
	if(NULL == r){
		return false;
	}

	if(k < r->data){
		return Delet(r->pre, k);
	}else if(k > r->data){
		return Delet(r->next, k);
	}else{
		cout<<"r:"<<r<<",data:"<<r->data<<",k:"<<k<<endl;
		pnode pre = r->pre;
		pnode next = r->next;
		if(NULL != pre){
			pre->next = next;
		}
		if(NULL != next){
			next->pre = pre;
		}
		cout<<"pre:"<<pre<<",next:"<<next<<",r:"<<r<<",data:"<<r->data<<endl;
		delete r;
		r = NULL;
		return true;
	}
}

int main()
{
	pnode r = NULL;
	Creat(r);
	Plist(r);
	
	Delet(r, 4);
	Plist(r);

	return 0;
}
