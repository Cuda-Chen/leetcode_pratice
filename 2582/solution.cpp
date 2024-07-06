class Solution {
public:
    int passThePillow(int n, int time) {
        int a = n - 1;
        int dir = time / a;
        int steps = time % a;
        return (dir % 2 == 0)
            ? (1 + steps)
            : (n - steps);
    }
};
