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
	int mx;
}arr[4*500000];

node pull(node n1,node n2){
	node tmp;
	tmp.mx = max(n1.mx,n2.mx);
	return tmp;
}

void build(int L,int R,int id){
	if(L==R){
		arr[id].mx = a[L];
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

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	build(0,k-1,0);
	int w;
	cin>>w;
	while(w--){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		if(a>b){
			swap(a,b);
		}
		cout<<query(a,b,0,k-1,0).mx<<endl;;
	}



	return 0;
}



