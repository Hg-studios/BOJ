import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main{
    static class Point{
        int x, y;
        public Point(int x, int y){
            this.x=x;
            this.y=y;
        }
    }
    static int[][] arr; //a가 b를 갈 수 있는지 저장
    static boolean[][] visited; //i번째 값을 이미 방문하여 답으로 카운트했는지 체크하기 위한 배열
    static int n;

    static BufferedReader br;
    static StringBuilder sb;
    static StringTokenizer st;

    static int[] dx = new int[] {-1,1,0,0};
    static int[] dy = new int[] {0,0,-1,1};

    public static void main(String[] args) throws IOException {
        //2차원 배열을 만들어서 해당 인덱스에서 갈 수 있는 인덱스를 찾음
        //그 인덱스에서 방문 표시가 되어있는 곳을 또 체크함
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        //입력받기
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][n];
        visited = new boolean[n][n];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for(int j=0; j<n; j++){
                arr[i][j]=str.charAt(j)-'0';
            }
        }

        List<Integer> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]!=1 || visited[i][j]) continue;

                //시작점을 하나 찾은 후 시작점과 이어져있는 곳을 모두 탐색함
                int cnt=0;
                Queue<Point> q = new LinkedList<>();
                cnt++;
                visited[i][j]=true;
                q.offer(new Point(i,j));

                while(!q.isEmpty()){
                    Point cur = q.poll();
                    int curX = cur.x;
                    int curY = cur.y;

                    for(int dir=0; dir<4; dir++){
                        int nx = curX+dx[dir];
                        int ny = curY+dy[dir];

                        if(nx<0||nx>=n||ny<0|ny>=n) continue;
                        if(arr[nx][ny]!=1 || visited[nx][ny]) continue;

                        cnt++;
                        visited[nx][ny]=true;
                        q.offer(new Point(nx,ny));
                    }
                }
                //다 탐색한 후 땅의 크기를 list에 저장함
                list.add(cnt);
            }
        }
        Collections.sort(list);

        System.out.println(list.size());
        for(int x : list) System.out.println(x);

    }
}