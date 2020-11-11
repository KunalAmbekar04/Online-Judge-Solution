// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
	vector<int> graph[100007];

	void dfs(int u, bool *visited) {
		visited[u] = true;
		for (auto itr : graph[u]) {
			if (!visited[itr]) {
				dfs(itr, visited);
			}
		}
	}

public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (connections.size() < n - 1) {
			return -1;
		}

		for (int i = 0; i < connections.size(); i++) {
			int a = connections[i][0];
			int b = connections[i][1];

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int cc = 0;

		bool *visited = new bool[n] {false};
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs(i, visited);
				cc++;
			}
		}

		return cc - 1;
	}
};