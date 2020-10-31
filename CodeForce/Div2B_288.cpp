#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin>>s;
	int n = s.length();
	int flag=0,idx=-1;
	for(int i=0;i<n;i++){
		if((s[i]-'0')%2==0){
			flag=1;
			if(s[i]<s[n-1]){
				swap(s[i],s[n-1]);
				cout<<s<<endl;
				return 0;
			}
			else{
				idx=i;
			}
		}
	}
	
	if(!flag){
		cout<<"-1"<<endl;
	}
	else{
		swap(s[idx],s[n-1]);
		cout<<s<<endl;
	}
	return 0;
}
