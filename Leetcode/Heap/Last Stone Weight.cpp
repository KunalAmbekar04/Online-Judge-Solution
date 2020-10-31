class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;

        for (auto itr : stones) {
            maxH.push(itr);
        }

        while (!maxH.empty()) {
            int s1 = maxH.top();
            maxH.pop();

            if (maxH.empty()) {
                return s1;
            }

            int s2 = maxH.top();
            maxH.pop();

            if (s1 != s2) {
                maxH.push(s1 - s2);
            }
        }
        return 0;
    }
};