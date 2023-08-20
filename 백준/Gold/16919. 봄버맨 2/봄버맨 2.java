import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static class Point{
		int x,y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	static int r, c, n, timer;
	static char[][] arr;
	static int[][] timeBoard; //매 초마다 값을 저장함. 1초는 반복x, 2초부터 4번씩 반복되므로 저장해야되는 페이지수는 5개임
	static int[][][] ans; //timeBoard로 계속 연산하고 매 시간마다 구해진 정답을 ans에 저장함
	static BufferedReader br;
	static StringBuilder sb;
	static StringTokenizer st;
	
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		//입력받기
		st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken()); //r입력 받기
		c = Integer.parseInt(st.nextToken()); //c입력 받기
		n = Integer.parseInt(st.nextToken()); //n초 입력받기
		
		//초기화
		timeBoard = new int[r][c]; //6초까지는 구해놔야하고 그 이후엔 반복으로 처리
		ans = new int[5][r][c];

		//입력받기
		for (int i = 0; i < r; i++) { 
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			
			for(int j=0; j < c; j++) {
				char c = str.charAt(j);
				if(c=='O') timeBoard[i][j] = 0;
				else timeBoard[i][j]=-1; //나머지곳은 -1로 초기화함 
			}
		}
		
		//초기값 ans[0][][]에 저장
		for (int i = 0; i < r; i++) { 
			for(int j=0; j < c; j++) {
				ans[0][i][j] = timeBoard[i][j];
			}
		}
		
		//0~5초에 일어나는 일을 ans에 저장함 -> 2~5초는 계속 반복됨 
		//timeBoard[0]이 0초이자 1초에 해당하는 ..
		timer+=2; //0초에서 2초로 넘어감, 1초는 아무것도 안하므로
		int idx=0; //ans 페이지 수 
		while(timer<=5) {
			idx++;
			
			//짝수초는 빈곳에 폭탄 설치하기
			if(timer%2==0) { //2초랑 4초는 빈칸에 timer수로 채움 
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if(timeBoard[i][j]==-1) timeBoard[i][j]=timer;
					}
				}
			}
			
			//print(ans);
			//홀수초는 (timer-3)초에 해당하는 폭탄 터트리기
			else {
				Queue<Point> q = new LinkedList<>();
				for (int i = 0; i < r; i++) { 
					for(int j=0; j < c; j++) {
						if(timeBoard[i][j]==timer-3) {
							q.offer(new Point(i,j)); //터트릴 폭탄 넣어두기
							timeBoard[i][j]=-1; //-1로 폭탄터트린 곳을 초기화시킴
						}
					}
				}
				
				while(!q.isEmpty()) {
					Point cur = q.poll();
					int curX = cur.x;
					int curY = cur.y;
					
					for(int dir=0; dir<4; dir++) {
						int nx = curX + dx[dir];
						int ny = curY + dy[dir];
						
						if(nx<0||nx>=r||ny<0||ny>=c) continue; //범위 벗어나면 탐색 끝
						timeBoard[nx][ny]=-1; //-1로 폭탄터트린 곳을 초기화시킴
					}
				}
			}
			
			//해당 초에 행동을 다했으면 ans에 답 저장하기
			for (int i = 0; i < r; i++) { 
				for(int j=0; j < c; j++) {
					ans[idx][i][j] = timeBoard[i][j];
				}
			}
			//print(ans);
			timer++; //다 했으니 시간 1초 증가 
		}
		
		//n에 해당하는 ans페이지를 만들고 -1이면 . 출력, 아니면 O 출력
		int page = (n-2)%4+1; //n에 해당하는 페이지
		if(n==0||n==1) page=0;
		for (int i = 0; i < r; i++) { 
			for(int j=0; j < c; j++) {
				//System.out.print(ans[page][i][j]);
				
				if(ans[page][i][j]==-1) sb.append(".");
				else sb.append("O");
			}
			sb.append('\n');
		}
		
		System.out.println(sb);
		
	}

	private static void print(int[][][] ans2) {
		System.out.println("**");
		for(int k=0; k<5; k++) {
			for (int i = 0; i < r; i++) { 
				for(int j=0; j < c; j++) {
					System.out.print(ans2[k][i][j]+"\t");
				}
				System.out.println();
			}
			System.out.println();
		}
		System.out.println();
	}
	
	
}