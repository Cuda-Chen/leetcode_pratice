class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i1 = a.size() - 1;
        int i2 = b.size() - 1;
        int carry = 0;
        while(i1 >= 0 || i2 >= 0) {
            int tmp =  
                (i1 >= 0 ? a[i1] - '0' : 0) + 
                (i2 >= 0 ? b[i2] - '0' : 0) + 
                carry;
            ans.push_back('0' + (tmp % 2));
            carry = tmp / 2;
            i1--;
            i2--;
        }
        if(carry)
            ans.push_back('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
