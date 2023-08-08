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
    static class Point{
        int x,y;

        public Point(int x, int y) {
            // TODO Auto-generated constructor stub
            this.x=x;
            this.y=y;
        }
    }
    static int n,m;
    static int[][] arr;
    static int[][] visited;
    static BufferedReader br;
    //static BufferedWriter bw;

    static int[] dx = new int[] {1,-1,0,0};
    static int[] dy = new int[] {0,0,-1,1};

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        //bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(st.nextToken());

        for(int t=1; t<=tc; t++) {
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            arr = new int[n][m];
            visited = new int[n][m];

            //System.out.println(m+" "+n+" "+k);

            //입력받아서 땅에 지렁이 있는 곳을 표시
            for(int i=0; i<k; i++) {
                st = new StringTokenizer(br.readLine());
                int mm = Integer.parseInt(st.nextToken());
                int nn = Integer.parseInt(st.nextToken());
                //System.out.println("nn"+nn+" "+mm);
                arr[nn][mm]=1;
            }

            int cnt=0;
            //for문을 돌면서 지렁이가 있는 땅을 체크함
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(arr[i][j]==0 || visited[i][j]==1) continue; //지렁이가 없거나 이미 방문했으면 탐색x
                    cnt++; //bfs할 새로운 땅을 찾았으므로 cnt++해줌
                    //System.out.println(i+ " "+j);
                    Queue<Point> q = new LinkedList<>();

                    visited[i][j]=1;
                    q.offer(new Point(i,j)); //시작점 넣어줌

                    while(!q.isEmpty()) {
                        Point cur = q.poll();
                        int curX = cur.x;
                        int curY = cur.y;
                        for(int dir=0; dir<4; dir++) {
                            int nx = curX + dx[dir];
                            int ny = curY + dy[dir];
                            if(nx<0||nx>=n||ny<0||ny>=m) continue;
                            if(arr[nx][ny]==0 || visited[nx][ny]==1) continue;

                            visited[nx][ny]=1;
                            q.offer(new Point(nx,ny));
                        }
                    }
                }
            }
            System.out.println(cnt);
        }
    }
}