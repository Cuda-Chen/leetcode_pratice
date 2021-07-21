// https://zxi.mytechroad.com/blog/math/leetcode-313-super-ugly-number/
// DP (priority queue)
struct Node {
    int num;
    int index;
    int prime;
    
    bool operator>(const Node &n) const {
        if(this->num == n.num) return this->index > n.index;
        return this->num > n.num;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        vector<int> nums(n, 1);
        priority_queue<Node, vector<Node>, greater<Node>> q;
        for(int p : primes)
            q.push({p, 1, p});
        
        for(int i = 1; i < n; i++) {
            nums[i] = q.top().num;
            while(nums[i] == q.top().num) {
                Node n = q.top();
                q.pop();
                n.num = nums[n.index++] * n.prime;
                q.push(n);
            }
        }
        
        return nums.back();
    }
};
