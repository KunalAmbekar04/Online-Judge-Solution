#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAXN 1000005

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool prime[MAXN];
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	
	for(ll i=2;i*i<=MAXN;i++){
		if(prime[i]){
			for(ll j=i*i;j<=MAXN;j+=i){
				prime[j]=false;
			}
		}
	}
	
	ll n,x;
	cin>>n;
	while(n--){
		cin>>x;
		ll y = sqrt(x);
		if(y*y==x && prime[y]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
