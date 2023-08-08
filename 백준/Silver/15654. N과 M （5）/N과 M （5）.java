import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    int[] arr, select;
    boolean[] visited;
    int n,m;

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    private void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        select = new int[m];
        visited = new boolean[n];

        st = new StringTokenizer(br.readLine());

        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

//        for(int i=0; i<n; i++){
//            System.out.println(arr[i]);
//        }
//        System.out.println(n+" "+m);

        recursive(0); //중복없는 순열

    }

    public void recursive(int cnt){
        if(cnt==m){
            for (int i=0; i<m; i++){
                System.out.print(select[i]+" ");
            }
            System.out.println();
            return;
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                select[cnt]=arr[i];
                visited[i]=true;
                recursive(cnt+1);
                visited[i]=false;
            }
        }
    }
}