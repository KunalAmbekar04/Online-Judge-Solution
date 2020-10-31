#include<bits/stdc++.h> 
using namespace std; 


typedef pair<int, int> iPair; 


int dijkstras(list<iPair> adj[],int src,int des,int no_cities)
{
	int distance[no_cities+1];
	
	//first item  of pair is weight
   //as first item is by default used to compare
   //two pairs
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
	for(int i = 1;i<=no_cities;i++)
	{
		distance[i] = INT_MAX;
		//visited[i] = false;
	}
	//in pq pair of distance from src and point whose distance is given.
	pq.push(make_pair(0, src)); 
	distance[src] = 0;

	while (!pq.empty()) 
    { 

        int minVertex = pq.top().second; 
		int minDist = pq.top().first;
        pq.pop(); 
		if(minVertex == des)
			break;
		
		if(distance[minVertex] < minDist){
			continue;
		}
		for(auto edge : adj[minVertex])
		{
			int weight = edge.second;
			int v = edge.first;
			int dist = distance[minVertex] + weight;
			if(dist < distance[v])
			{
				distance[v] = dist;
				pq.push(make_pair(distance[v], v)); 
			}
			
		}
	}

	
	
	return distance[des];
	
	
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int no_cities,no_edges;
		string city_name;
		cin>>no_cities;
		list<iPair> adj[no_cities+1];

		unordered_map<string,int> city_map;
		for(int i = 1;i<=no_cities;i++)
		{
			cin>>city_name;
			city_map[city_name] = i;
			cin>>no_edges;
			while(no_edges--)
			{
				int weight,v;
				cin>>v>>weight;
				adj[i].push_back(make_pair(v,weight));
				adj[v].push_back(make_pair(i,weight));
			}
		}

		int no_paths,src,des,ans;
		string name1,name2;
		cin>>no_paths;
		for(int i = 0;i<no_paths;i++)
		{
			cin>>name1>>name2;
			src = city_map[name1];
			des = city_map[name2];
			
			ans = dijkstras(adj,src,des,no_cities);
			cout<<ans<<endl;
		}
		
	}

}