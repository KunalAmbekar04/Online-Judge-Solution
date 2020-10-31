#include<iostream>
#include<vector>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;

#define ll long long int

ll v,maxDist,farNode;
bool visited[10009];
ll dist[10009];
vector<ll> graph[10009];

void bfs(ll s){
	memset(visited,false,sizeof(visited));
	memset(dist,0,sizeof(dist));
	list<ll> q;
	q.push_back(s);
	visited[s]=true;
	while(!q.empty()){
		ll u = q.front();
		q.pop_front();
		
		for(auto itr = graph[u].begin();itr!=graph[u].end();itr++){
			if(visited[*itr]==false){
				dist[*itr] = dist[u] + 1;
				q.push_back(*itr);
				visited[*itr]=true;
			}
		}
	}
	
	maxDist=0;
	for(ll i=1;i<=v;i++){
		maxDist = max(maxDist,dist[i]);
		if(maxDist==dist[i]){
			farNode = i;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>v;
	ll a,b;
	for(ll i=0;i<v-1;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(1);
	bfs(farNode);
	cout<<maxDist<<endl;
	return 0;
}

