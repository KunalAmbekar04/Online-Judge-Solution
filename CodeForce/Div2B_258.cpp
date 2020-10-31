#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long int


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	ll ar[n+1],temp[n+1];
	
	for(ll i=1;i<=n;i++){
		cin>>ar[i];
		temp[i]=ar[i];
	}
	sort(temp+1,temp+n+1);
	
	ll start=0,end=0;
	int flag=0;
	for(ll i=1;i<=n;i++){
		if(ar[i]!=temp[i]){
			if(!flag){
				start=i;
				flag=1;
			}
			else{
				end=i;
			}
		}
	}
	
	if(!flag){
		cout<<"yes"<<endl;
		cout<<"1 1"<<endl;
	}
	else{
		flag=0;
		for(ll i=end,j=start;i>=start;i--,j++){
			if(ar[i]!=temp[j]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"no"<<endl;
		}
		else{
			cout<<"yes"<<endl;
			cout<<start<<" "<<end<<endl;
		}
	}
	
	return 0;
}
