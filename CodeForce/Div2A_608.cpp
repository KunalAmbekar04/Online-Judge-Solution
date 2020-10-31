#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int cost=0;
	if(f>e){
		int mB = min(b,min(c,d));
		b-=mB;
		c-=mB;
		d-=mB;
		cost+=(f*mB);
		
		if(d>0){
			int mA = min(a,d);
			cost+=(e*mA);
		}
	}
	else{
		int mA = min(a,d);
		a-=mA;
		d-=mA;
		cost+=(e*mA);
		
		if(d>0){
			int mB = min(b,min(c,d));
			b-=mB;
			c-=mB;
			d-=mB;
			cost+=(f*mB);
		}
		
	}
	cout<<cost<<endl;
	return 0;
}
