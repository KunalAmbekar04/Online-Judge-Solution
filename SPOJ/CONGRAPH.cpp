#include<bits/stdc++.h> 
using namespace std; 
  
void dfs(vector<int> adj[],int src,bool visited[])
{
	if(visited[src])
		return;

	visited[src] = true;
	for(auto edge : adj[src])
	{
		if(!visited[edge])
		{
			dfs(adj,edge,visited);
		}
	}
}

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
int connected(vector<int> adj[],int no_v,bool visited[])
{
	int cnt = 0;
	for(int i = 0;i<no_v;i++)
	{
		if(!visited[i])
		{
			cnt++;
			dfs(adj,i,visited);
		}
	}
	return cnt;
}

  
int main() 
{ 
	int no_v,e,u,v;
	cin>>no_v>>e;
    vector<int> adj[no_v+1];
	bool visited[no_v+1];
	memset(visited,false,sizeof(visited));
	for(int i = 0;i<e;i++)
	{
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	
	
	cout<<connected(adj,no_v,visited) - 1<<endl;
    
    return 0; 
} 