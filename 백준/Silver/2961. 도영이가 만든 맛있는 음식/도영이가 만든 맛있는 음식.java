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
    static int n, ans=Integer.MAX_VALUE;
    static int[][] info;
    static boolean[] select;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        //입력 받기
        n = Integer.parseInt(st.nextToken());
        info = new int[n][2];
        select = new boolean[n];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            info[i][0] = Integer.parseInt(st.nextToken());
            info[i][1] = Integer.parseInt(st.nextToken());
        }

        //n개의 재료로 구할 수 있는 모든 길이의 부분집합을 구해야하므로 Powerset 구하기
        powerset(0);

        System.out.println(ans);
    }

    private static void powerset(int cnt) {
        if(cnt==n){
            //공집합은 뺌
            int cntTrue=0;
            for(int i=0; i<n; i++){
                if(select[i]) cntTrue++;

            }
            if(cntTrue==0) return; //공집합은 검사하지 않음

            //해당 집합에서의 신맛과 쓴맛의 차를 구함
            int t1 = 1;
            int t2 = 0;
            for(int i=0; i<n; i++){
                if(select[i]) {
                    t1*=info[i][0]; //신맛은 곱해줌
                    t2+=info[i][1]; //쓴맛은 더해줌
                }
            }

            ans = Math.min(ans, Math.abs(t1-t2));
            return;
        }

        select[cnt]=true;
        powerset(cnt+1);
        select[cnt]=false;
        powerset(cnt+1);
    }
}