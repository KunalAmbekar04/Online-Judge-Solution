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
		int ar[n+1];
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		
		int flag=0;
		
		for(int i=1;i<=n;i++){
			if(ar[i]%2==0){
				cout<<"1"<<endl;
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		
		if(!flag){
			for(int i=1;i<n;i++){
				if((!ar[i]%2 && !ar[i+1]%2) || (ar[i]%2 && ar[i+1]%2)){
					cout<<"2"<<endl;
					cout<<i<<" "<<i+1<<endl;
					flag=1;
					break;
				}
			}
		}
		
		if(!flag){
			cout<<"-1"<<endl;
		}
	}
}
