// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
	vector<vector<int>> result;
	void solve(vector<vector<int>> &graph, int u, vector<int> &path) {
		path.push_back(u);
		if (u == graph.size() - 1) {
			result.push_back(path);
		}

		for (auto itr : graph[u]) {
			solve(graph, itr, path);
		}

		path.pop_back();
	}
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> path;
		solve(graph, 0, path);
		return result;
	}
};