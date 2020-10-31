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
		ll n;
		cin>>n;
		ll num=0;
		int count=0;
		for(int i=1;i<=9;i++){
			num = num*10 + 1;
			for(int j=1;j<=9;j++){
				if(num*j<=n){
					count++;
				}
			}
		}
		
		cout<<count<<endl;
	}
	return 0;
}
