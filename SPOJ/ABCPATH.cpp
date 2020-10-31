#include<iostream>
#include<list>
#include<cstring>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int	visited[55][55];
	int dist[55][55];
	
	int t=1;
	int r,c;
	cin>>r>>c;
	while(r!=0 && c!=0){
		string s[r];
		for(int i=0;i<r;i++){
			cin>>s[i];
		}
		
		int max=0;
		memset(visited,0,sizeof(visited));
		memset(dist,0,sizeof(dist));
		
		list<pair<int,int>> q;
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(s[i][j]=='A'){
					max=1;
					dist[i][j]=1;
					q.push_back({i,j});
				}
			}
		}
		
		int m1[8] = {-1,0,1,-1,1,-1,0,1};
		int m2[8] = {-1,-1,-1,0,0,1,1,1};
		
		while(!q.empty()){
			auto u = q.front();
			q.pop_front();
			
			for(int i=0;i<8;i++){
				int x = m1[i] + u.first;
				int y = m2[i] + u.second;
				
				if((x>=0 && x<r) && (y>=0 && y<c) && (s[x][y]) == (s[u.first][u.second] + 1)){
					if(!visited[x][y]){
						dist[x][y] = dist[u.first][u.second] + 1;
						visited[x][y]=1;
						if(dist[x][y]>max){
							max=dist[x][y];
						}
						q.push_back({x,y});
					}
				}
			}
			
		}
		cout<<"Case "<<t++<<": "<<max<<endl;
		cin>>r>>c;
	}
	return 0;
}

