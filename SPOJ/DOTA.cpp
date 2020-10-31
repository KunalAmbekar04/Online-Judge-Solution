#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	int n,m,d;
	while(T--){
		cin>>n>>m>>d;
		int h;
		int count=0;
		while(n--){
			cin>>h;
			if(h>d){
				while(h>0){
					h-=d;
					count++;
				}
				count--;
			}
		}
		(count>=m) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
	return 0;
}


