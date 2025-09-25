import sys

n = int(input())
points = []
for i in range(n):
    points.append(list(map(int, input().split())))

points.sort()

def calc_dist(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

def devide_and_conquer(start, end):
    if start == end:
        return sys.maxsize
    if start + 1 == end:
        return calc_dist(points[start], points[end])
    
    mid = (start + end) // 2
    min_dist = min(devide_and_conquer(start, mid), devide_and_conquer(mid, end))
    
    
    tmp_points = []
    for i in range(start, end + 1):
        if (points[mid][0] - points[i][0]) ** 2 < min_dist:
            tmp_points.append(points[i])
            
    tmp_points.sort(key=lambda x : x[1])
    
    m = len(tmp_points)
    for i in range(m - 1):
        for j in range(i + 1, m):
            if (tmp_points[i][1] - tmp_points[j][1]) ** 2 < min_dist:
                min_dist = min(min_dist, calc_dist(tmp_points[i], tmp_points[j]))
            else:
                break
    return min_dist

print(devide_and_conquer(0, n - 1))