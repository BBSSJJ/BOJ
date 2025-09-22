

def solution(plans):
    answer = []
    
    plans.sort(key=lambda x: x[1])
    
    tasks = []
    for plan in plans:
        h, m = map(int, plan[1].split(":"))
        time = h * 60 + m
        tasks.append([time, plan[0], int(plan[2])])
    
    st = []
    curTime = tasks[0][0]
    
    for task in tasks:                
        while st:
            doing = st[-1]
            if curTime + doing[2] > task[0]:
                st.pop()
                doing[2] -= (task[0] - curTime)
                curTime = task[0]
                st.append(doing)
                break
            curTime += doing[2]
            answer.append(doing[1])
            st.pop()
        
        st.append(task)
        curTime = task[0]

        
    while st:
        doing = st[-1]
        st.pop()
        answer.append(doing[1])
    
    return answer