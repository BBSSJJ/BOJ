import java.util.*;
import java.io.*;

public class Main {

    static int G, P;
    static int[] gates;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        G = Integer.parseInt(br.readLine());
        P = Integer.parseInt(br.readLine());
        gates = new int[G + 1];

        for(int i = 0 ; i <= G; i++){
            gates[i] = i;
        }

        int answer = 0;
        
        for(int i = 0 ; i < P; i++){
            int p = Integer.parseInt(br.readLine());
            if (findEmptyGate(p) == 0) break;
            answer += 1;
            union(findEmptyGate(p), findEmptyGate(p) - 1);

        }
        System.out.println(answer);
    }

    static int findEmptyGate(int a){
        if (gates[a] == a) return a;
        else return gates[a] = findEmptyGate(gates[a]);
    }

    static void union(int a, int b){
        a = findEmptyGate(a);
        b = findEmptyGate(b);
        gates[a] = b;
    }
}