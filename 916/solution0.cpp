// hash table (TLE)
// O(n^2)

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<vector<int>> aCount; // number of alphabets of each word in A
        vector<vector<int>> bCount; // number of alphabets of each words in B
        
        for(string a : A) {
            vector<int> wordCount(26, 0);
            for(char c : a) {
                wordCount[c - 'a']++;
            }
            aCount.emplace_back(wordCount);
        }
        for(string b : B) {
            vector<int> wordCount(26, 0);
            for(char c : b) {
                wordCount[c - 'a']++;
            }
            bCount.emplace_back(wordCount);
        }
        
        vector<string> result;
        for(int i = 0; i < A.size(); i++) {
            int flag = 0;
            for(int j = 0; j < B.size(); j++) {
                vector<int> temp(26, 0);
                vector<int> ref(26, 0);
                for(int k = 0; k < 26; k++) {
                    if(aCount[i][k] >= bCount[j][k] && bCount[j][k])
                        temp[k]++;
                    if(bCount[j][k])
                        ref[k]++;
                }
                if(temp == ref)
                    flag = 1;
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                result.emplace_back(A[i]);
        }
        return result;
    }
};
