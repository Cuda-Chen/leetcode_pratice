// two sum variant

class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sum1 = Arrays.stream(A).sum();
        int sum2 = Arrays.stream(B).sum();
        int diff = (sum1 - sum2) / 2;
        Set<Integer> s = new HashSet();
        for(int elem : A) {
            s.add(elem);
        }
        
        for(int x : B) {
            int target = x + diff;
            if(s.contains(target)) {
                return new int[] {target, x};
            }
        }
        
        return new int[] {};
    }
}
