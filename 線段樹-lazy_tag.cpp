#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
#define IL(X) ((X)*2+1)
#define IR(X) ((X)*2+2)
using namespace std;
int MAX = LONG_MAX;
int MIN = LONG_MIN;
int a[500000];
struct node{
	int size;
	int sum;
	int lazy = 0;
	int cnt(){
		return sum+size*lazy;
	}
}arr[500000*4];

node pull(node x,node y){
	node tmp;
	tmp.lazy = 0;
	tmp.size = x.size+y.size;
	tmp.sum = x.cnt()+y.cnt();
	return tmp;
}

void build(int L,int R,int id){
	if(L==R){
		arr[id].size = 1;
		arr[id].sum = a[L];
		return ;
	}
	int mid = (L+R)/2;
	build(L,mid,IL(id));
	build(mid+1,R,IR(id));
	arr[id] = pull(arr[IL(id)],arr[IR(id)]);
}

void push(int id){
	arr[IL(id)].lazy += arr[id].lazy;
	arr[IR(id)].lazy += arr[id].lazy;
	arr[id].lazy = 0;
}

void modify(int i,int l,int r,int L,int R,int id){
	if(L==l&&R==r){
		arr[id].lazy += i;
		return ;
	}
	push(id);
	int mid = (L+R)/2;
	if(r<=mid){
		modify(i,l,r,L,mid,IL(id));
	}else if(l>mid){
		modify(i,l,r,mid+1,R,IR(id));
	}else{
		modify(i,l,mid,L,mid,IL(id));
		modify(i,mid+1,r,mid+1,R,IR(id));
	}
	arr[id] = pull(arr[IL(id)],arr[IR(id)]);
}

node query(int l,int r,int L,int R,int id){
	if(L==l&&R==r){
		return arr[id];
	}
	push(id);
	arr[id] = pull(arr[IL(id)],arr[IR(id)]);
	int mid = (L+R)/2;
	if(r<=mid){
		return query(l,r,L,mid,IL(id));
	}else if(l>mid){
		return query(l,r,mid+1,R,IR(id));
	}else{
		return pull(query(l,mid,L,mid,IL(id)),query(mid+1,r,mid+1,R,IR(id)));
	}
}


signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	build(0,n-1,0);
	int m;
	cin>>m;
	while(m--){
		char c;
		cin>>c;
		if(c=='C'){
			int l,r,k;
			cin>>l>>r>>k;
			l--;
			r--;
			modify(k,l,r,0,n-1,0);
		}else{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<query(l,r,0,n-1,0).sum<<endl;
		}
	}



	return 0;
}



