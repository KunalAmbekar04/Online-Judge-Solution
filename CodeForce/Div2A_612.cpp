#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int count=0;
		int finalCount=0;
		for(int i=0;i<n-1;i++){
			if(s[i]=='P'){
				continue;
			}			
			count=0;
			for(int j=i+1;j<n;j++){
				if(s[j]=='A'){
					break;
				}
				count++;
			}
			finalCount = max(count,finalCount);
		}
		cout<<finalCount<<endl;
	}
	return 0;
}
