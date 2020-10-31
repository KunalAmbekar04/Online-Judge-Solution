#include<iostream>
#include<list>
#include<cstring>
using namespace std;

int bug,xn;
int graph[2019][2019];
int color[2019];

bool bipartite(int s){
	list<int> q;
	q.push_back(s);
	color[s]=1;
	while(!q.empty()){
		int v = q.front();
		q.pop_front();
		
		for(int i=1;i<=bug;i++){
			if(graph[v][i] && color[i]==-1){
				color[i] = 1 - color[v];
				q.push_back(i); 
			}
			else if(graph[v][i] && color[v]==color[i]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	
	for(int t=1;t<=T;t++){
		memset(graph,0,sizeof(graph));
		cin>>bug>>xn;
		int b1,b2;
		for(int i=0;i<xn;i++){
			cin>>b1>>b2;
			graph[b1][b2]=1;
			graph[b2][b1]=1;
		}
		
		for(int i=1;i<=bug;i++){
			color[i]=-1;
		}
		int flag=0;
		bool res;
		for(int i=1;i<=bug;i++){
			if(color[i]==-1){
				res = bipartite(i);
				if(res==false){
					flag=1;
					break;
				}
			}
		}
		
		if(flag==1){
			cout<<"Scenario #"<<t<<":\nSuspicious bugs found!"<<endl;
		}
		else{
			cout<<"Scenario #"<<t<<":\nNo suspicious bugs found!"<<endl;
		}
	}
	return 0;
}

