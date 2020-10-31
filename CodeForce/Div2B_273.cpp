#include<iostream>
using namespace std;

#define ll long long int

ll npair(ll n){
	return n*(n-1)/2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	ll maxPair = npair(n-m+1);
	ll minPair = (n%m==0) ? npair(n/m)*m : npair(n/m)*(m - n%m) + npair(n/m+1)*(n%m);
	cout<<minPair<<" "<<maxPair<<endl;
	
	return 0;
}
