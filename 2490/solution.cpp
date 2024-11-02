class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> v;
        stringstream ss(sentence);
        string tmp;
        while(getline(ss, tmp, ' '))
            v.push_back(tmp);

        int n = v.size();
        for(int i = 0; i < n; i++) {
            if(v[i].back() != v[(i + 1) % n][0])
                return false;
        }
        return true;
    }
};
