// brute force - O(n^2)
// Sorting - O(nlog(n) + mlog(m))

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	ll n,m;
	while(T--){
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		
		cin>>m;
		ll b[m];
		for(ll i=0;i<m;i++){
			cin>>b[i];
		}
		
		sort(a,a+n);
		sort(b,b+m);
		
		int min = INT_MAX;
		ll i = 0;
		ll j = 0;
		while(i<n && j<m){
			ll diff = abs(a[i]-b[j]);
			if(min>diff){
				min=diff;
			}
			(a[i]<b[j]) ? i++ : j++;	
		}
		cout<<min<<endl;
	}
	return 0;
}

