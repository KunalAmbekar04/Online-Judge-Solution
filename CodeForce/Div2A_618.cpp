#include<iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ar[n];
		int sum=0,pdt=1;
		
		int zeros=0;
		int count=0;
		for(int i=0;i<n;i++){
			cin>>ar[i];
			sum+=ar[i];
			pdt*=ar[i];
			if(ar[i]==0){
				zeros++;
			}
		}
		
		if(pdt==0){
			count+=zeros;
			sum+=zeros;
		}
		
		if(sum==0){
			count++;
		}
		
		cout<<count<<endl;
	}
	return 0;
}
