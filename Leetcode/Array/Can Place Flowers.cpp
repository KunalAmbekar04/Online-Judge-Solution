// https://leetcode.com/problems/can-place-flowers/


// Solution 1
class Solution {
public:
    bool canPlaceFlowers(vector<int>& ar, int k) {
        int n = ar.size();
        int curr = 0;

        for (int i = 0; i <= n; i++) {
            if (i < n && !ar[i]) {
                curr++;
                if (i == 0) curr++;
                if (i == n - 1) curr++;
            }
            else {
                k -= (curr - 1) / 2;
                if (k <= 0) {
                    return true;
                }
                curr = 0;
            }
        }

        return false;
    }
};


// Solution 2
class Solution {
public:
    bool canPlaceFlowers(vector<int>& ar, int k) {
        int n = ar.size();
        if (n == 1 && ar[0] == 0 && (k == 1 || k == 0)) {
            return true;
        }

        if (ar[0] == 0 && ar[1] == 0 && k > 0) {
            ar[0] = 1;
            k--;
        }

        if (ar[n - 1] == 0 && ar[n - 2] == 0 && k > 0) {
            ar[n - 1] = 1;
            k--;
        }

        for (int i = 1; i <= n - 2; i++) {
            if (ar[i] == 0 && ar[i - 1] == 0 && ar[i + 1] == 0 && k > 0) {
                ar[i] = 1;
                k--;
            }
        }

        if (k == 0) {
            return true;
        }
        return false;
    }
};