# priority_queue (heap)
# note that Python doesn't have max-heap, so I change the sign of stations distance instead

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        n = len(stations)
        pq = []
        i = stops = 0
        current = startFuel
        
        while True:
            if current >= target:
                return stops
            
            while i < n and current >= stations[i][0]:
                heappush(pq, -(stations[i][1]))
                i += 1
            if not pq:
                break
                
            current += -(heappop(pq))
            stops += 1
            
        return -1
