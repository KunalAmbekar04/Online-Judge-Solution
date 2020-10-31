#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	int count=1;
	while(n!=0){
		int ar[n][3];
		for(int i=0;i<n;i++){
			cin>>ar[i][0];
			cin>>ar[i][1];
			cin>>ar[i][2];
		}
		
		ar[0][2]+=ar[0][1];
		ar[1][0]+=ar[0][1];
		ar[1][1]+=min(ar[1][0],min(ar[0][1],ar[0][2]));
		ar[1][2]+=min(ar[1][1],min(ar[0][1],ar[0][2]));
		
		for(int i=2;i<n;i++){
			ar[i][0]+=min(ar[i-1][0],ar[i-1][1]);
			ar[i][1]+=min(min(ar[i][0],ar[i-1][0]),min(ar[i-1][1],ar[i-1][2]));
			ar[i][2]+=min(ar[i][1],min(ar[i-1][1],ar[i-1][2]));
		}
		
		cout<<count++<<". "<<ar[n-1][1]<<endl;
		cin>>n;
	}
}
