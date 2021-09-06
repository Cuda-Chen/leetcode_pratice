// naive
// First count the maximum duration of each character
// Then find the maximum duration backward (i.e., lexicographically)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> keyPressedCnt(26, 0);
        int n = releaseTimes.size();
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                keyPressedCnt[keysPressed[i] - 'a'] = max(keyPressedCnt[keysPressed[i] - 'a'], releaseTimes[i]);
            } else {
                keyPressedCnt[keysPressed[i] - 'a'] = max(keyPressedCnt[keysPressed[i] - 'a'], releaseTimes[i] - releaseTimes[i - 1]);
            }
        }
        
        return (char)(abs(std::max_element(keyPressedCnt.rbegin(), keyPressedCnt.rend()) - keyPressedCnt.rend()) + 'a' - 1);
    }
};
