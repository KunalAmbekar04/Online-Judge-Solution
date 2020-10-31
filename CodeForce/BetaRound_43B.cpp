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

	int comb[5][5] = {
						{0,1,2,3,4},
						{1,2,0,3,4},
						{2,3,1,4,0},
						{3,4,2,1,0},
						{4,3,2,1,0}
					 };

	
	unordered_map<string,int> hash;
	hash["S"]=0;
	hash["M"]=1;
	hash["L"]=2;
	hash["XL"]=3;
	hash["XXL"]=4;
	
	int size[5];
	for(int i=0;i<5;i++){
		cin>>size[i];
	}
	int k;
	cin>>k;
	string s;
	while(k--){
		cin>>s;
		for(int i=0;i<5;i++){
			if(size[comb[hash[s]][i]]>0){
				for(auto itr : hash){
					if(itr.second == comb[hash[s]][i]){
						cout<<itr.first<<endl;
						break;
					}
				}
				size[comb[hash[s]][i]]--;
				break;
			}
		}
	}
	return 0;
}
