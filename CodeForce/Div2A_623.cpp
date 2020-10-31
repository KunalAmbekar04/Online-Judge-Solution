#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll T;
	cin>>T;
	while(T--){
		ll a,b,x,y;
		cin>>a>>b>>x>>y;
		ll res = max(max(a*y,a*(b-y-1)),max(b*x,b*(a-x-1)));
		cout<<res<<endl;
	}
	return 0;
}
