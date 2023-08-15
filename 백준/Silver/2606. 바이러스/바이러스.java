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
    static boolean[][] arr; //a가 b를 갈 수 있는지 저장
    static boolean[] visited; //i번째 값을 이미 방문하여 답으로 카운트했는지 체크하기 위한 배열
    static int n, k;

    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        //2차원 배열을 만들어서 해당 인덱스에서 갈 수 있는 인덱스를 찾음
        //그 인덱스에서 방문 표시가 되어있는 곳을 또 체크함
        br = new BufferedReader(new InputStreamReader(System.in));

        //입력받기
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new boolean[n+1][n+1];
        visited = new boolean[n+1];

        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());

        for(int i=0; i<k; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            arr[a][b]=true;
            arr[b][a]=true; //이건가?
        }
        //좌표를 넣을 큐와 정답값인 카운트 변수 준비
        int cnt=0;
        Queue<Integer> q = new LinkedList<>();

        //1번 좌표 넣음
        visited[1]=true;
        q.offer(1);

        while(!q.isEmpty()){
            int x = q.poll();
            //n만큼 돌면서
            for(int i=1; i<=n; i++){
                if(arr[x][i] && !visited[i]) { //x가 i를 갈 수 있는지 확인
                    cnt++;
                    visited[i]=true;
                    q.offer(i);
                }
            }
        }

        System.out.println(cnt);
    }
}