import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int n;
    static int[] score;
    static int[][] dp; //dp[a][i]=b : a칸에 왔을 때 현재까지 i번 연속으로 밟았을 때 최대 점수가 b
                       //단, 반드시 a칸은 밟아야 함

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        //sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        dp = new int[301][3];
        score = new int[301];

        for(int i=1; i<=n ;i++){
            score[i] = Integer.parseInt(br.readLine());
        }

        dp[1][1] = score[1];
        dp[1][2] = 0;
        dp[2][1] = score[2];
        dp[2][2] = score[1] + score[2];

        for(int i=3; i<=n; i++){
            dp[i][1] = Math.max(dp[i-2][1], dp[i-2][2]) + score[i]; //자신은 무조건 밟음
            dp[i][2] = dp[i-1][1] + score[i];
        }

        System.out.println(Math.max(dp[n][1], dp[n][2]));
    }
}