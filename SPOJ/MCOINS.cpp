#include<iostream>
#include<cstring>
using namespace std;

#define ll long long int
#define MAXN 1000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll k,l,m;
	cin>>k>>l>>m;
	bool game[MAXN];
	memset(game,false,sizeof(game));
	
	for(ll i=0;i<MAXN;i++){
		if(i-1>=0 && game[i-1]==false){
			game[i]=true;
		}
		else if(i-l>=0 && game[i-l]==false){
			game[i]=true;
		}
		else if(i-k>=0 && game[i-k]==false){
			game[i]=true;
		}
	}
	
	ll x;
	for(ll i=0;i<m;i++){
		cin>>x;
		cout<<((game[x])?"A":"B");
	}
	cout<<endl;
}
