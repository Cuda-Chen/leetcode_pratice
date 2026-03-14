class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> A;
        string tmp;
        f(n, tmp, A);

        return A.size() < k
            ? ""
            : A[k - 1];
    }

private:
    void f(int n, string &tmp, vector<string> &A) {
        if(tmp.size() == n) {
            A.push_back(tmp);
            return;
        }

        for(char c : {'a', 'b', 'c'}) {
            if(!tmp.empty() && tmp.back() == c)
                continue;
            tmp.push_back(c);
            f(n, tmp, A);
            tmp.pop_back();
        }
    }
};
