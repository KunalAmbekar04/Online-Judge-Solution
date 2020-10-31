https://leetcode.com/problems/online-stock-span/

// Solution 1
class StockSpanner {
    stack<int> s;
    unordered_map<int, int> mp;
public:
    StockSpanner() {

    }

    int next(int price) {
        if (s.empty()) {
            s.push(price);
            mp[price] = 1;
            return 1;
        }

        int count = 1;
        while (!s.empty() && s.top() <= price) {
            count += mp[s.top()];
            s.pop();
        }
        s.push(price);
        mp[price] = count;
        return count;
    }
};

// Solution 2
class StockSpanner {
    stack<pair<int, int>> s;
public:
    StockSpanner() {

    }

    int next(int price) {
        if (s.empty()) {
            s.push({price, 1});
            return 1;
        }

        int count = 1;
        while (!s.empty() && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }

        s.push({price, count});
        return count;
    }
};
