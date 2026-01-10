import java.util.*;
import java.math.*;
import java.io.*;

class Solution {
    public String[] solution(String[] expressions) {
        int needFix = -1;
        
        List<Integer> needToFix = new ArrayList<>();
        List<Integer> candidates = new ArrayList<>();
        for(int i = 2; i <= 9 ;i++){
            candidates.add(i);
        }
        
        
        for(int e = 0; e < expressions.length; e++){
            String[] cur = expressions[e].split(" ");
            
            if("X".equals(cur[4])) 
                needToFix.add(e);
            
            
            List<Integer> tmp = new ArrayList<>();
            checkExpression(cur, tmp);
            candidates.retainAll(tmp);
        }
        
        List<String> answer = new ArrayList<>();
        
        for(int i = 0; i < needToFix.size(); i++){
            int idx = needToFix.get(i);
            String[] cur = expressions[idx].split(" ");
            StringBuilder sb = new StringBuilder();
            for(int c = 0; c <= 3; c++){
                sb.append(cur[c]);
                sb.append(" ");
            }
            String X = "X";
            
            for(int c = 0; c < candidates.size(); c++){
                int jb = candidates.get(c);
                int A = toDecimal(cur[0], jb);
                int B = toDecimal(cur[2], jb);
                int C = -1;
                if("+".equals(cur[1])) C = A + B;
                else if("-".equals(cur[1])) C = A - B;
                String result = toJB(C, jb);
                if("X".equals(X)){
                    X = result;
                } else if(!result.equals(X)){
                    X = "?";
                    break;
                }
            }
            sb.append(X);
            answer.add(sb.toString());
        }
        
        return answer.toArray(String[]::new);
    }
    
    static int checkExpression(String[] expression, List<Integer> results){
        String operation = expression[1];

        for(int jb = 2; jb <= 9; jb++){
            int A = toDecimal(expression[0], jb);
            int B = toDecimal(expression[2], jb);
            if("X".equals(expression[4])){
                if(A != -1 && B != -1) results.add(jb);
                continue;
            }
            
            int C = toDecimal(expression[4], jb);
            if(A == -1 || B == -1 || C == -1) continue;
            if( "-".equals(operation) && A - B == C)
                results.add(jb);
            else if ("+".equals(operation) && A + B == C)
                results.add(jb);
        }
        return 0;
    }
    
    static int toDecimal(String num, int jb){
        int len = num.length();
        int result = 0;
        for(int i = 0; i < len; i++){
            int cur = num.charAt(len - i - 1) - '0';
            if(cur >= jb) return -1;
            result += (cur * Math.pow(jb, i));
        }
        return result;
    }
    
    static String toJB(int num, int jb){
        if (num == 0) return "0";

        StringBuilder sb = new StringBuilder();
        int tmp = num;
        while(tmp > 0){
            sb.insert(0, tmp % jb);
            tmp /= jb;
        }
        return sb.toString();
    }
}



