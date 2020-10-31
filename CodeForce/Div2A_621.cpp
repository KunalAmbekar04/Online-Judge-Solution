#include<iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		int ar[n+1];
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		
		while(d--){
			for(int i=2;i<=n;i++){
				if(ar[i]>0){
					ar[i]--;
					ar[i-1]++;
					break;
				}	
			}
		}
		
		cout<<ar[1]<<endl;
	}
	return 0;
}

