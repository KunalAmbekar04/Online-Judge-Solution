#include<iostream>
#include<cstring>
using namespace std;

#define ll long long int
#define MAXN 1000009

bool prime[MAXN];

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

void soe(){
	memset(prime,true,sizeof(prime));
	for(int i=2;i*i<MAXN;i++){
		if(prime[i]){
			for(int j=2*i;j<MAXN;j+=i){
				prime[j]=false;
			}
		}
	}
}

int main(){
	soe();
	int T;
	scanf("%d",&T);
	ll a,b;
	while(T--){
		scanf("%lld %lld",&a,&b);
		ll div = gcd(a,b);
		ll total = 1;
		for(ll i=2;i<=div;i++){
			if(prime[i]){
				int count=0;
				if(div%i==0){
					while(div%i==0){
						div/=i;
						count++;
					}
					total *= (count+1);
				}
			}
		}
		printf("%lld\n",total);
	}
	return 0;
}

