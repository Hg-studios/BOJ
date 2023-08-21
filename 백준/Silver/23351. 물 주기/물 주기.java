import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int n,k,a,b;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        //초기화
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = k; //k만큼 물을 머금고 있음
        }

        int day=0;
        //그리디적으로 가장 적은 물의 양을 갖고 있는 n개의 화분에 물을 주면 됨
        //정렬을 하면서 하면 될듯!?
       L:while(true){
            day++;
            Arrays.sort(arr);
            for (int i = 0; i < a; i++) { //정렬해서 양이 적은 a개의 화분에 물을 채움
                arr[i]+=b; //b만큼 증가함
            }
            for (int i = 0; i < n; i++) {
                arr[i]-=1; //모든 화분에 수분 1씩 감소
                if(arr[i]==0) break L;
            }
        }

        System.out.println(day);
    }



}