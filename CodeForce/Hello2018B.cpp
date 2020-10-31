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

	/*int n;
	cin>>n;
	int ar[n+1];
	memset(ar,-1,sizeof(ar));
	int degree[n+1];
	memset(degree,0,sizeof(degree));
	for(int i=2;i<=n;i++){
		cin>>ar[i];
		degree[ar[i]]++;
	}
	
	vector<int> leaf,nonleaf;
	for(int i=1;i<=n;i++){
		if(degree[i]){
			nonleaf.push_back(i);
		}
		else{
			leaf.push_back(i);
		}
	}
	
	int res[n+1];
	memset(res,0,sizeof(res));
	for(int i=0;i<nonleaf.size();i++){
		res[nonleaf[i]]=3;
	}
	
	for(int i=0;i<leaf.size();i++){
		res[ar[leaf[i]]]--;
	}
	int flag=0;
	for(int i=0;i<nonleaf.size();i++){
		if(res[nonleaf[i]]>0){
			flag=1;
			break;
		}
	}
	
	cout<<((flag)?"No":"Yes")<<endl;
	*/
	
	int n;
	cin>>n;
	vector<int> ar[n+1];
	int x;
	for(int i=2;i<=n;i++){
		cin>>x;
		ar[x].push_back(i);
	}
	int p=0;
	for(int i=1;i<=n;i++){
		p = (ar[i].size())? 0 : 3;
		for(auto j : ar[i]){
			if(ar[j].size()==0){
				p++;
			}
		}
		if(p<3){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
