#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int ar[3];
		cin>>ar[0]>>ar[1]>>ar[2];
		sort(ar,ar+3);
		int a=ar[2]; 
		int b=ar[1]; 
		int c=ar[0]; 
		int res=0;
		if(a>0){
			res++;
			a--;
		}
		
		if(b>0){
			res++;
			b--;
		}
		
		if(c>0){
			res++;
			c--;
		}
		
		if(a>0 && b>0){
			res++;
			a--;
			b--;
		}
		
		if(b>0 && c>0){
			res++;
			b--;
			c--;
		}
		
		if(a>0 && c>0){
			res++;
			a--;
			c--;
		}
		
		if(a>0 && b>0 && c>0){
			res++;
			a--;
			b--;
			c--;
		}
		
		cout<<res<<endl;
	}
}
