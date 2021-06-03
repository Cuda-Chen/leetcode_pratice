// sort + linear search (O(nlgn) + O(n))
// Use linear search to reduce time of searching max element.

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        vector<int> a(horizontalCuts.size() + 1);
        vector<int> b(verticalCuts.size() + 1);
        for(int i = 0; i < a.size(); i++) {
            if(i == 0) {
                a[i] = horizontalCuts[i] - 0;
            } else if(i == a.size() - 1) {
                a[i] = h - horizontalCuts[i - 1];
            } else {
                a[i] = horizontalCuts[i] - horizontalCuts[i - 1];
            }
        }
        for(int i = 0; i < b.size(); i++) {
            if(i == 0) {
                b[i] = verticalCuts[i] - 0;
            } else if(i == b.size() - 1) {
                b[i] = w - verticalCuts[i - 1];
            } else {
                b[i] = verticalCuts[i] - verticalCuts[i - 1];
            }
        }
        
        
        int aMax = *max_element(a.begin(), a.end());
        int bMax = *max_element(b.begin(), b.end());
        
        long result = ((long)aMax * (long)bMax) % kMod;
        
        return result;
    }
    
private:
    long kMod = 1e9 + 7;
};
