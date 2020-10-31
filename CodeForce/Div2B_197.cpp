#include<iostream>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n>>m;
	ll ar[m+1];
	for(int i=1;i<=m;i++){
		cin>>ar[i];
	}
	ll a=1;
	ll b=-1;
	ll count=0;
	for(ll i=1;i<=m;i++){
		b = ar[i];
		if(a<=b){
			count += (b-a);
		}
		else{
			count += (n-a+b);
		}
		a = ar[i];
	}
	cout<<count<<endl;
	return 0;
}
