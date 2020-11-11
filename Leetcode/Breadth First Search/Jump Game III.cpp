// https://leetcode.com/problems/jump-game-iii/

class Solution {
	bool solve(vector<int> graph[], vector<bool> &visited, vector<int> &ar, int u) {
		visited[u] = true;
		if (ar[u] == 0) {
			return true;
		}

		for (auto itr : graph[u]) {
			if (!visited[itr]) {
				if (solve(graph, visited, ar, itr)) {
					return true;
				}
			}
		}
		return false;
	}
public:
	bool canReach(vector<int>& ar, int start) {
		int v = ar.size();
		vector<int> graph[v];
		vector<bool> visited(v, false);

		for (int i = 0; i < v; i++) {
			int temp = i - ar[i];
			if (temp >= 0 && temp < v) {
				graph[i].push_back(temp);
			}

			temp = i + ar[i];
			if (temp >= 0 && temp < v) {
				graph[i].push_back(temp);
			}
		}

		return solve(graph, visited, ar, start);
	}
};


class Solution {
	bool solve(vector<int> &ar, vector<bool> &visited, int i) {
		if (i < 0 || i >= ar.size() || visited[i]) {
			return false;
		}

		if (ar[i] == 0) {
			return true;
		}

		visited[i] = true;

		return solve(ar, visited, i - ar[i]) || solve(ar, visited, i + ar[i]);
	}
public:
	bool canReach(vector<int>& ar, int start) {
		vector<bool> visited(ar.size(), false);
		return solve(ar, visited, start);
	}
};