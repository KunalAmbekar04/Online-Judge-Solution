#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,l;
	cin>>n>>l;
	long double ar[n];
	for(ll i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	
	long double minDis = INT_MIN;
	
	for(ll i=0;i<n-1;i++){
		if(minDis < ar[i+1] - ar[i]){
			minDis = ar[i+1]-ar[i];
		}
	}
	long double res = max(minDis/2.0,max(ar[0]-0,l-ar[n-1]));
	
	cout<<fixed<<res<<endl;
	return 0;
}
