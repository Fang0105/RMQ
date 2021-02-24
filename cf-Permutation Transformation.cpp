#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
#define IL(X) ((X)*2+1)
#define IR(X) ((X)*2+2)
using namespace std;
int MAX = LONG_MAX;
int MIN = LONG_MIN;
map<int,int>mp;
map<int,int>loc;
int n;
int a[10000];
struct node{
	int mx;
}arr[40000];

node pull(node x,node y){
	node tmp;
	tmp.mx = max(x.mx,y.mx);
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
	}else if(l>mid){
		return query(l,r,mid+1,R,IR(id));
	}else{
		return pull(query(l,mid,L,mid,IL(id)),query(mid+1,r,mid+1,R,IR(id)));
	}
}
void init(){
	memset(arr,0,sizeof(arr));
	memset(a,0,sizeof(a));
}

int find(int n){
	return loc[n];
}

struct newtree{
	int k;
	int L,R;
	int dep;
};

void buildnew(newtree root){
	root.k = query(root.L,root.R,0,n-1,0).mx;
	newtree r,l;
	int loc = find(root.k);
	r.L = loc+1;
	r.R = root.R;
	r.dep = root.dep+1;
	
	l.L = root.L;
	l.R = loc-1;
	l.dep = root.dep+1;
	
	mp[root.k] = root.dep;
	
	if(root.R!=loc){
		if(r.L!=r.R){
			buildnew(r);
		}else{
			r.k = query(r.L,r.R,0,n-1,0).mx;
			mp[r.k] = r.dep;
		}
	}
	
	if(root.L!=loc){
		if(l.L!=l.R){
			buildnew(l);
		}else{
			l.k = query(l.L,l.R,0,n-1,0).mx;
			mp[l.k] = l.dep;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int r;
	cin>>r;
	while(r--){
		init();
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			loc[a[i]] = i;
		}
		build(0,n-1,0);
		newtree root;
		root.L = 0;
		root.R = n-1;
		root.dep = 0;
		buildnew(root);
		for(int i=0;i<n;i++){
			cout<<mp[a[i]]<<" ";
		}
		cout<<endl;
	}



	return 0;
}



