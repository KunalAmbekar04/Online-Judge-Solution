#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	int h,a;
	while(T--){
		int count=0;
		cin>>h>>a;
		
		if(h<=0 || a<=0){
			cout<<count<<endl;
			break;
		}
		
		h+=3;
		a+=2;
		count++;
		while(true){
			if(h>5 && a>10){
				h-=2;
				a-=8;
				count+=2;
			}
			else if(h>20 && a<=10){
				h-=17;
				a+=7;
				count+=2;
			}
			else{
				cout<<count<<endl;
				break;
			}
		}
	}
	return 0;
}

