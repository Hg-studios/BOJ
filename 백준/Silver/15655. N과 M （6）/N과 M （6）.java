import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    int[] arr, select;
    //boolean[] visited;
    int n,m;
    BufferedWriter bw;

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    private void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        select = new int[m];
        //visited = new boolean[n];

        st = new StringTokenizer(br.readLine());

        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        recursive(0,0); //중복없는 조합

        bw.close();
    }

    public void recursive(int cnt, int start) throws IOException {
        if(cnt==m){
            for (int i=0; i<m; i++){
                bw.write(select[i]+" ");
            }
            bw.write('\n');
            return;
        }

        for(int i=start; i<n; i++){
            select[cnt]=arr[i];
            recursive(cnt+1, i+1);
        }
    }
}