#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	while(T--){
		ll a,b,c,r;
		cin>>a>>b>>c>>r;
		ll L = c-r;
		ll R = c+r;
		
		int st = max(L,min(a,b));
		int ed = min(R,max(a,b));
		
		ll res = abs(b-a) - max(0,ed-st);
		cout<<res<<endl;
	}
	return 0;
}
