class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        int aToppingCount = 0;
        int bToppingCount = 0;
        int[] aToppings = new int[10001];
        int[] bToppings = new int[10001];
        for(int i = 0; i < topping.length; i++){
            int cur = topping[i];
            if(aToppings[cur] == 0)
                aToppingCount += 1;   
            aToppings[cur] += 1;
        }
        for(int i = 0; i < topping.length; i++){
            int cur = topping[i];
            if(bToppings[cur] == 0)
                bToppingCount += 1;
            bToppings[cur] += 1;
            aToppings[cur] -= 1;
            if(aToppings[cur] == 0)
                aToppingCount -= 1;
            if(aToppingCount == bToppingCount)
                answer += 1;
        }
        
        return answer;
    }
}