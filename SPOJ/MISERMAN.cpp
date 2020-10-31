#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	int ar[n][m];
	int dp[n][m];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>ar[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0){
				dp[i][j]=ar[i][j];
				continue;
			}
			
			if(j==0){
				dp[i][j] = ar[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
			}
			else if(j==m-1){
				dp[i][j] = ar[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
			}
			else{
				dp[i][j] = ar[i][j] + min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
			}
		}
	}
	
	int k = INT_MAX;
	
	for(int i=0;i<m;i++){
		if(k>dp[n-1][i]){
				k=dp[n-1][i];
			}
	}
	
	cout<<k<<endl;
	
	return 0;	
}
