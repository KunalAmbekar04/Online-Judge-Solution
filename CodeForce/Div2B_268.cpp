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

	int p,q,l,r;
	cin>>p>>q>>l>>r;
	vector<pair<int,int>> x,z;
	int a,b,c,d;
	for(int i = 0; i < p; i++){
		cin>>a>>b;
		z.push_back({a,b});
	}
	for(int i = 0; i < q; i++){
		cin>>c>>d;
		x.push_back({c,d});
	}
	
	int ans=0;
	for(int i = l; i <= r; i++){
		for(int j = 0; j < q; j++){
			c = x[j].first + i;
			d = x[j].second + i;
			int flag=0;
			for(int k = 0; k < p; k++){
				a = z[k].first;
				b = z[k].second;
				
				if(d<a || c>b){
					continue;
				}
				ans++;
				flag=1;
				break;
			}
			if(flag){
				break;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
