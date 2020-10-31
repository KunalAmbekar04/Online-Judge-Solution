#include<iostream>
#include<list>
#include<cstring>
using namespace std;

bool prime[10000];

void soe(){
	for(int i=2;i*i<=10000;i++){
		if(!prime[i]){
			for(int j=i*i;j<=10000;j+=i){
				prime[j]=true;
			}
		}
	}
}

void intoArray(int *ar, int num){
	int k=3;
	while(num){
		ar[k]=num%10;
		num/=10;
		k--;
	}
}

int intoNum(int *ar){
	int temp=0;
	int k=0;
	while(k<4){
		temp = temp*10 + ar[k];
		k++;
	}
	return temp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(prime,false,sizeof(prime));
	soe();
	
	int T;
	cin>>T;
	int a,b;
	while(T--){
		cin>>a>>b;
		int digit[4],visited[10000],dist[10000];
		memset(visited,0,sizeof(visited));
		memset(dist,-1,sizeof(dist));
		
		list<int> q;
		q.push_back(a);
		dist[a]=0;
		while(!q.empty()){
			int u = q.front();
			q.pop_front();
			for(int k=3;k>=0;k--){
				intoArray(digit,u);
				for(int i=0;i<=9;i++){
					digit[k]=i;
					int temp = intoNum(digit);
					if(!prime[temp] && dist[temp]==-1 && temp>=1000){
						dist[temp]=dist[u]+1;
						q.push_back(temp);
					}
				}
			}
		}
		
		dist[b]!=-1 ? cout<<dist[b]<<endl : cout<<"impossible"<<endl;
	}
	return 0;
}

