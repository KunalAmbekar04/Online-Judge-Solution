#include<iostream>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	ll x,y,a,b;
	while(T--){
		cin>>x>>y>>a>>b;
		if(!((y-x) % (a+b))){
			cout<<(y-x)/(a+b)<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
