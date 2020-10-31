#include<iostream>
#include<climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	int ar1[n];
	int ar2[n];
	int c1=0,c2=0;

	for(int i=0;i<n;i++){
		cin>>ar1[i];
	}

	for(int i=0;i<n;i++){
		cin>>ar2[i];
	}

	for(int i=0;i<n;i++){
		if(ar1[i]==ar2[i]){
			continue;
		}
		else{
			if(ar1[i]>ar2[i]){
				c1++;
			}
			else{
				c2++;
			}
		}
	}
	
	if(!c1){
		cout<<"-1"<<endl;
	}
	else{
		cout<<c2/c1+1<<endl;
	}
	return 0;
	
}
