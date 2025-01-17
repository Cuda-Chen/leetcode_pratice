// from hint: The xor-sum of the derived array should be 0 since there is always a duplicate occurrence of each element.

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int tmp = std::accumulate(begin(derived), end(derived), 0, std::bit_xor<int>());
        return tmp == 0;
    }
};
