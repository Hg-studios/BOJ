import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Iterator;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int t, n, map[][], ans, dist[][];

    static int dx[] = {1,-1,0,0};
    static int dy[] = {0,0,-1,1};

    public static class Node {
		int x;
		int y;
		int dist;
		public Node(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}
	}
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= t; tc++) {
            n = Integer.parseInt(br.readLine());

            //초기화
            map = new int[n][n];
            dist = new int[n][n];
            ans = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                String str = br.readLine();
                for (int j = 0; j < n; j++) {
                    map[i][j] = str.charAt(j) - '0';
//                    System.out.print(map[i][j]+" ");
                }
//                System.out.println();
            }

            bfs();

            sb = new StringBuilder();
            sb.append("#"+tc+" "+dist[n-1][n-1]);
            System.out.println(sb);
        }
    }

	private static void bfs() {
		//cost배열에는 작은 값만 들어가야 하므로 큰 값을 저장해놓음
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = Integer.MAX_VALUE;
			}
		}
		
		//bfs를 돌림
		Queue<Node> q = new ArrayDeque<>();
		
		dist[0][0] = 0;
		q.add(new Node(0,0,0));
		
		while(!q.isEmpty()) {
			Node cur = q.poll();
			
			if(cur.x==n-1 && cur.y==n-1) {
				dist[cur.x][cur.y]=Math.min(dist[cur.x][cur.y], cur.dist); 
				continue;
			}
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				
				if(nx<0||nx>=n||ny<0||ny>=n) continue;
				
				int distance = cur.dist + map[nx][ny];
				//기존에 구해놓은 값보다 작을 때에만 큐에 넣어줌
				if(distance < dist[nx][ny]) {
					dist[nx][ny] = distance;
					q.add(new Node(nx,ny,distance));
				}
			}
		}
		
	}
}