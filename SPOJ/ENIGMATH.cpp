#include<iostream>
using namespace std;

#define ll long long int

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	ll a,b;
	while(T--){
		cin>>a>>b;
		ll com = gcd(a,b);
		cout<<b/com<<" "<<a/com<<endl;
	}
	return 0;
}

