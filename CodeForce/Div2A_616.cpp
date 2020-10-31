#include<iostream>
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
		int odd=0;
		for(int i=0;i<n;i++){
			if((s[i]-'0')%2){
				odd++;
			}
		}
			
		if(odd<=1){
			cout<<"-1"<<endl;
		}
		else{
			int count=0;
			for(int i=0;i<n;i++){
				if((s[i]-'0')%2){
					cout<<s[i];
					count++;
				}
				
				if(count>=2){
					break;
				}
			}
			cout<<endl;
		}	
	}
	return 0;
}
