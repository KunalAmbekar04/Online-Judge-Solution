#include<iostream>
using namespace std;

void swap(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	
	while(t--){
		int i=0;
		while(i<n-1){
			if(s[i]=='B' && s[i+1]=='G'){
				swap(s[i],s[i+1]);
				//cout<<s<<endl;
				i+=1;
			}
			i+=1;
		}
	}
	
	cout<<s<<endl;
	return 0;
	
}
