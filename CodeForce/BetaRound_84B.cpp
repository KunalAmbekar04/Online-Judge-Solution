/**************
* AUTHOR : Kunal 
***************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		if(i%4==1){
			cout<<"p";
		}
		else if(i%4==2){
			cout<<"q";
		}
		else if(i%4==3){
			cout<<"r";
		}
		else if(i%4==0){
			cout<<"s";
		}
	}
	cout<<endl;
	return 0;
}
