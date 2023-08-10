import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
    int n;
    int[][] arr;
    BufferedReader br;
    StringTokenizer st;
    BufferedWriter bw;

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    private void solve() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][2];

        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        recursive(0,0); //cnt, cost, day
        System.out.println(ans);
    }
    int ans=0;
    private void recursive(int cost, int day) {
        if(day>n){
            return;
        }

        if(day<=n){
            ans = Math.max(ans, cost);
        }

        for(int i=day; i<n; i++){
            recursive(cost+arr[i][1], i+arr[i][0]);
        }
    }
}