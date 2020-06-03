// priority_queue (max-heap)

class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        int current = startFuel;
        int i = 0, stops = 0;
        
        while(true) {
            while(i < stations.length && current >= stations[i][0]) {
                pq.offer(stations[i][0]);
                i++;
            }
            if(current >= target) {
                return stops;
            }
            if(pq.isEmpty()) {
                break;
            }
            
            current += pq.poll();
            stops++;
        }
        
        return -1;
    }
}
