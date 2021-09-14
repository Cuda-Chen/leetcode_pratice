// naive

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> balloonCnt(5, 0);
        vector<int> freq(26, 0);
        for(char c : text)
            freq[c - 'a']++;
        balloonCnt[0] = freq['b' - 'a'];
        balloonCnt[1] = freq['a' - 'a'];
        balloonCnt[2] = freq['l' - 'a'] / 2;
        balloonCnt[3] = freq['o' - 'a'] / 2;
        balloonCnt[4] = freq['n' - 'a'];
        
        return *min_element(begin(balloonCnt), end(balloonCnt));
    }
};
