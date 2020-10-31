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

	int n,m;
	cin>>n>>m;
	char ch[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>ch[i][j];
		}
	}
	
	int check[n][m];
	memset(check,1,sizeof(check));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int l=0;l<m;l++){
				if(j==l){
					continue;
				}
				if(ch[i][j]!=ch[i][l]){
					check[i][j]=1;
				}
				else{
					check[i][j]=0;
					break;
				}
			}
			
			if(check[i][j]){
				for(int k=0;k<n;k++){
					if(i==k){
						continue;
					}
					if(ch[i][j]!=ch[k][j]){
						check[i][j]=1;
					}
					else{
						check[i][j]=0;
						break;
					}
				}
			}
			
			
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(check[i][j]){
				cout<<ch[i][j];
			}
		}
	}
	cout<<endl;
	
	return 0;
}
