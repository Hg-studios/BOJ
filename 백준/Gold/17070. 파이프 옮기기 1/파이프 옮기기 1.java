import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static int n, cnt;
	static boolean board[][];
	
	static int[] dx = {0, 1, 1}; //[0]:가로 [1]:세로 [2]:대각선
	static int[] dy = {1, 0, 1};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		//초기화
		board = new boolean[n+1][n+1];
		
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= n; j++) {
				if(Integer.parseInt(st.nextToken()) == 0) {
					board[i][j] = false;
				}
				else {
					board[i][j] = true;
				}
			}
		}
		
		recursive(1,2,0);
		
		sb = new StringBuilder();
		sb.append(cnt);
		System.out.println(sb);
		
	}

	//status -> 1:가로 2:세로 3:대각선
	private static void recursive(int x, int y, int status) {
		if(x==n && y==n) { //도착점에 도착함 
			cnt++;
			
			return;
		}
		
		if(status==0) { //가로
			for (int dir = 0; dir < dx.length; dir+=2) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(OOB(nx,ny)) continue;
				if(board[nx][ny]) continue;
				if(dir==2) { //대각선인 경우 세군데의 좌표가 빈칸인지 봐야함
					if(board[nx-1][ny]) continue;
					if(board[nx][ny-1]) continue;
				}
				recursive(nx, ny, dir);
			}
		}
		else if(status==1) { //세로
			for (int dir = 1; dir < dx.length; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(OOB(nx,ny)) continue;
				if(board[nx][ny]) continue;
				if(dir==2) { //대각선인 경우 세군데의 좌표가 빈칸인지 봐야함
					if(board[nx-1][ny]) continue;
					if(board[nx][ny-1]) continue;
				}
				
				recursive(nx, ny, dir);
			}
		}
		else if(status==2) { //대각선
			for (int dir = 0; dir < dx.length; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(OOB(nx,ny)) continue;
				if(board[nx][ny]) continue;
				if(dir==2) { //대각선인 경우 세군데의 좌표가 빈칸인지 봐야함
					if(board[nx-1][ny]) continue;
					if(board[nx][ny-1]) continue;
				}
				
				recursive(nx, ny, dir);
			}
		}
	}

	private static boolean OOB(int x, int y) {
		return x<1 || x>n || y<1 || y>n;
	}
}
