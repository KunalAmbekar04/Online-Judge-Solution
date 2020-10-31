#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(!a){
		return b;
	}
	return gcd(b%a,a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	int a;
	string b;
	int mod,i;
	while(T--){
		cin>>a>>b;
		if(!a){
			cout<<b<<endl;
			continue;
		}
		mod=0;
		i=0;
		while(b[i]!='\0'){
			mod = (mod*10 + b[i]-'0')%a;
			i++;
		}
		cout<<gcd(a,mod)<<endl;
	}
	return 0;
}
