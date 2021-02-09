#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
#define IL(X) ((X)*2+1)
#define IR(X) ((X)*2+2)
using namespace std;
int MAX = LONG_MAX;
int MIN = LONG_MIN;
int a[100000];
struct node{
	int sum;
}arr[400000];

node pull(node n1,node n2){
	node tmp;
	tmp.sum = n1.sum+n2.sum;
	return tmp;
}

void build(int L,int R,int id){
	if(L==R){
		arr[id].sum = a[L];
		return ;
	}
	int mid = (L+R)/2;
	build(L,mid,IL(id));
	build(mid+1,R,IR(id));
	arr[id] = pull(arr[IL(id)],arr[IR(id)]);
}

node query(int l,int r,int L,int R,int id){
	if(L==l&&R==r){
		return arr[id];
	}
	int mid = (L+R)/2;
	if(r<=mid){
		return query(l,r,L,mid,IL(id));
	}
	if(l>mid){
		return query(l,r,mid+1,R,IR(id));
	}
	return pull(query(l,mid,L,mid,IL(id)),query(mid+1,r,mid+1,R,IR(id)));
}

void init(){
	memset(arr,0,sizeof(arr));
	memset(a,0,sizeof(a));
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		init();
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		build(0,n-1,0);
		while(m--){
			int q,w;
			cin>>q>>w;
			q--;
			w--;
			cout<<query(q,w,0,n-1,0).sum<<endl;
		}
	}



	return 0;
}



