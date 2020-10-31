// https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
  bool checkPossibility(vector<int>& ar) {
    int n = ar.size();
    int count = 0;
    int idx = -1;
    for (int i = 0; i < n - 1; i++) {
      if (ar[i] > ar[i + 1]) {
        count++;
        idx = i;
      }

      if (count > 1) {
        return false;
      }
    }

    if (count == 1) {
      if (idx > 0 && idx < n - 2) {
        if (ar[idx - 1] > ar[idx + 1] && ar[idx] > ar[idx + 2]) {
          return false;
        }
      }
    }
    return true;
  }
};