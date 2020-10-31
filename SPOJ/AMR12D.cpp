#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	string s,rev;
	while(T--){
		cin>>s;
		rev = s;
		reverse(rev.begin(),rev.end());
		(rev==s) ? cout<<"YES"<<endl : cout<<"NO"<<endl; 
	}
}

