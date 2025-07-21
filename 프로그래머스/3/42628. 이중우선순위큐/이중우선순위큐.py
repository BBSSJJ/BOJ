import heapq

def solution(operations):
    answer = []
    
    maxHeap = []
    minHeap = []
    count = 0
    
    for operation in operations:
        if operation[0] == "I" :
            value = int(operation[2:])
            heapq.heappush(maxHeap, -1 * value)
            heapq.heappush(minHeap, value)
            count += 1
        elif operation[0] == "D":
            if count <= 0: continue;
            if len(operation) == 3:
                while len(maxHeap) > count:
                    heapq.heappop(maxHeap)
                heapq.heappop(maxHeap)
                count -= 1
            elif len(operation) == 4:
                while len(minHeap) > count:
                    heapq.heappop(minHeap)
                heapq.heappop(minHeap)
                count -= 1
            if count == 0:
                maxHeap = []
                minHeap = []
    if count == 0:
        answer = [0, 0]
    else:
        answer = [heapq.heappop(maxHeap) * -1, heapq.heappop(minHeap)]
    
    return answer