#include<iostream>
#include<math.h>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		
		ll i = sqrt(n),j=0;
		while(i>0){
			if(j*j > n){
				cout<<"No"<<endl;
				break;
			}
			else if(i*i + j*j == n){
				cout<<"Yes"<<endl;
				break;
			}
			else if(i*i + j*j < n){
				j++;
			}
			else {
				i--;
			}
		}
	}
	return 0;
}

