class Solution {
public:
    string numberToWords(int num) {
        vector<string> tmp;
        f(num, tmp);
        string ans;
        for(int i = 0; i < tmp.size(); i++) {
            ans += tmp[i];
            if(i != tmp.size() - 1)
                ans += " ";
        }
        return ans;
    }

private:
    const int BILLION = 1e9;
    const int MILLION = 1e6;
    const int THOUSAND = 1e3;
    const int HUNDRED = 100;
    const int TEN = 10;

    unordered_map<int, string> m {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
    };

    // beaware of "0"
    void f(int n, vector<string> &tmp) {
        int b = n / BILLION;
        if(b) {
            int a = b / HUNDRED;
            if(a) {
                tmp.push_back(m[a]);
                tmp.push_back("Hundred");
            }
            b %= HUNDRED;

            if(b == 0) {
                // catch the zero
            } else if(1 <= b && b <= 19) {
                tmp.push_back(m[b]);
            } else {
                int c = b / TEN;
                int d = b % TEN;
                tmp.push_back(m[c * TEN]);
                if(d)
                    tmp.push_back(m[d]);
            }

            tmp.push_back("Billion");
        }
        n %= BILLION;

        int mi = n / MILLION;
        if(mi) {
            int a = mi / HUNDRED;
            if(a) {
                tmp.push_back(m[a]);
                tmp.push_back("Hundred");
            }
            mi %= HUNDRED;

            if(mi == 0) {
                // catch the zero
            } else if(1 <= mi && mi <= 19) {
                tmp.push_back(m[mi]);
            } else {
                int c = mi / TEN;
                int d = mi % TEN;
                tmp.push_back(m[c * TEN]);
                if(d)
                    tmp.push_back(m[d]);
            }

            tmp.push_back("Million");
        }
        n %= MILLION;

        int t = n / THOUSAND;
        if(t) {
            int a = t / HUNDRED;
            if(a) {
                tmp.push_back(m[a]);
                tmp.push_back("Hundred");
            }
            t %= HUNDRED;

            if(t == 0) {
                // catch the zero
            } else if(1 <= t && t <= 19) {
                tmp.push_back(m[t]);
            } else {
                int c = t / TEN;
                int d = t % TEN;
                tmp.push_back(m[c * TEN]);
                if(d)
                    tmp.push_back(m[d]);
            }

            tmp.push_back("Thousand");
        }
        n %= THOUSAND;

        // hundred leftover
        {
            int a = n / HUNDRED;
            if(a) {
                tmp.push_back(m[a]);
                tmp.push_back("Hundred");
            }
            n %= HUNDRED;

            if(n == 0) { // catch the zero
                if(tmp.empty())
                    tmp.push_back(m[n]);
            } else if(1 <= n && n <= 19) {
                tmp.push_back(m[n]);
            } else {
                int c = n / TEN;
                int d = n % TEN;
                tmp.push_back(m[c * TEN]);
                if(d)
                    tmp.push_back(m[d]);
            }
        }
    }
};
