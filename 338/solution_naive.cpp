// naive

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        
        for(int i = 0; i <= num; i++) {
            int temp = i;
            int counter = 0; // count number of '1's in temp's binary representation
            while(temp) {
                if(temp % 2 == 1)
                    counter++;
                temp /= 2;
            }
            result[i] = counter;
        }
        
        return result;
    }
};
