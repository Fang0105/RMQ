#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
#define IL(X) ((X)*2+1)
#define IR(X) ((X)*2+2)
using namespace std;
int MAX = LONG_MAX;
int MIN = LONG_MIN;
int a[100005];
struct node{
	int sum;
}arr[400020];

node pull(node n1,node n2){
	node tem;
	tem.sum = n1.sum*n2.sum;
	return tem;
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

void modify(int i,int v,int L,int R,int id){
	if(L==R){
		arr[id].sum = v;
		return ;
	}
	int mid = (L+R)/2;
	if(i<=mid){
		modify(i,v,L,mid,IL(id));
	}else{
		modify(i,v,mid+1,R,IR(id));
	}
	arr[id] = pull(arr[IL(id)],arr[IR(id)]);
}

void init(){
	memset(arr,0,sizeof(arr));
	memset(a,0,sizeof(a));
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int r,t;
	while(cin>>r>>t){
		init();
		for(int i=0;i<r;i++){
			int h;
			cin>>h;
			if(h>0){
				a[i] = 1;
			}else if(h==0){
				a[i] = 0;
			}else{
				a[i] = -1;
			}
		} 
		build(0,r-1,0);
		for(int i=0;i<t;i++){
			char c;
			int q,w;
			cin>>c>>q>>w;
			if(c=='C'){
				q--;
				if(w>0){
					w = 1;
				}else if(w==0){
					w = 0;
				}else{
					w = -1;
				}
				modify(q,w,0,r-1,0);
			}else{
				q--;
				w--;
				if(q>w){
					swap(q,w);
				}
				node ans = query(q,w,0,r-1,0);
				if(ans.sum==1){
					cout<<'+';
				}else if(ans.sum==0){
					cout<<0;
				}else{
					cout<<'-';
				}
			}
		}
		cout<<endl;
	}



	return 0;
}



