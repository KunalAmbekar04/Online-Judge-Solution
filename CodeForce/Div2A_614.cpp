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
		ll n,s,k;
		cin>>n>>s>>k;
		ll ar[k];
		for(ll i=0;i<k;i++){
			cin>>ar[i];
		}
		sort(ar,ar+k);
		ll diff = INT_MAX;
		for(ll i=0;i<=k;i++){
			if(s-i>=1 && !binary_search(ar,ar+k,s-i)){
				diff=min(i,diff);
			}
			if(s+i<=n && !binary_search(ar,ar+k,s+i)){
				diff=min(i,diff);
			}
		}
		
		cout<<diff<<endl;
	}
	return 0;
}
