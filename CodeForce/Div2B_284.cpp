#include<iostream>
#include<map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	map<string,string> hash;
	string a,b;
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		hash[a]=b;
	}
	
	string s1,s2;
	for(int i=0;i<n;i++){
		cin>>s1;
		s2 = hash[s1];
		if(s1.length()<=s2.length()){
			cout<<s1<<" ";
		}
		else{
			cout<<s2<<" ";
		}
	}
	cout<<endl;
	return 0;
}
