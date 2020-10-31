#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n = s.length();
		int flag=0;
		string temp = "abc";
		for(int i=0;i<n;i++){
			if(s[i]==s[i+1] && s[i]!='?'){
				flag=1;
				break;
			}
			
			if(s[i]=='?'){
				for(int j=0;j<3;j++){
					if(s[i-1]!=temp[j] && s[i+1]!=temp[j]){
						s[i]=temp[j];
					}
				}
			}
		}
		
		cout<<(flag ? "-1":s)<<endl;
	}
	return 0;
}
