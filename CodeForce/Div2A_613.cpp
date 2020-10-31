#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cL=0,cR=0;
	for(int i=0;i<n;i++){
		if(s[i]=='L'){
			cL++;
		}
		
		if(s[i]=='R'){
			cR++;
		}
	}
	
	cout<<cL+cR+1<<endl;
	return 0;
}
