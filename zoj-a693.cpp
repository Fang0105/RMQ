#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		int arr[n+5];
		arr[0] = 0;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			arr[i] = arr[i-1] + a;
		}
	
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			cout<<arr[b] - arr[a-1]<<endl;;
		}
	}
	





	return 0;
}

