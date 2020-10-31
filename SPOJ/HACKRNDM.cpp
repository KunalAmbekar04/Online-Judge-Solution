#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k;
	cin>>n>>k;
	int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	int count=0;
	int lb,ub,mid;
	for(int i=0;i<n;i++){
		lb=0;
		ub=n-1;
		while(lb<=ub){
			mid=(lb+ub)/2;
			if(ar[mid]==ar[i]+k){
				count++;
				break;
			}
			else if(ar[mid] > ar[i]+k){
				ub=mid-1;
			}
			else{
				lb=mid+1;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
