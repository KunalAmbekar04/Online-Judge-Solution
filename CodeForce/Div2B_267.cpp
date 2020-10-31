#include<iostream>
using namespace std;

int countBit(int n){
	int count=0;
	while(n){
		if(n&1){
			count++;
		}
		n>>=1;
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m,k;
	cin>>n>>m>>k;
	int ar[m+1];
	for(int i=0;i<=m;i++){
		cin>>ar[i];
	}
	
	int count=0;
	for(int i=0;i<m;i++){
		if(countBit(ar[i]^ar[m])<=k){
			count++;
		}
	}
	cout<<count<<endl;
	
	return 0;
}
