import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb; 
	
	static int n, m, r;
	static int[][] arr;
	
	static int[] dr = {0, 1, 0, -1};
	static int[] dc = {1, 0, -1, 0};
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		//초기화
		arr = new int[n][m];
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		rotate();
		
		print();
	}

	private static void rotate() {

		//n,m 중 더 작은 수의 절반만큼 회전시킬 사각형이 나옴 
		for (int i = 0; i < Math.min(n, m)/2; i++) {
			//
			int hei = n-i*2;
			int wid = m-i*2;
			
			//r번만큼 회전시킴 
			for (int rotateNum = 0; rotateNum < r%(2*hei+2*(wid-2)); rotateNum++) {
				//각 사각형의 시작점이 x, y임
				int r = i;
				int c = i;
				
				//맨 처음 시작점에 바로 값이 덮어쓰이기 때문에 마지막에 이 값을 저장해주기 위해서 따로 저장함 
				int tmp = arr[r][c];
				
				//시작점부터 시작하고 왼쪽, 아래쪽, 오른쪽, 위쪽 순서로 좌표값을 옮겨줌
				//돌리는 방향과 앞으로 봐야 할 방향은 서로 반대임 
				//현재 dir로 좌표를 옮기다가 범위를 벗어나면 방향을 다음 순서로 바꿔줌
				int dir = 0;
				while(dir<4) {
					int nr = r + dr[dir];
					int nc = c + dc[dir];
					
					//다음 자리가 범위를 벗어나지 않음 
					if(nr>=i && nr<n-i && nc>=i && nc<m-i) {
						arr[r][c] = arr[nr][nc];
						
						//r,c 값 업데이트 
						r = nr;
						c = nc;
					}
					//다음 자리가 범위를 벗어남 
					else {
						dir++;
					}
				}
				
				//(i,i)에 있던 값을 
				arr[i+1][i] = tmp;
			}
		}
	}

	private static void print() {
		sb = new StringBuilder();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sb.append(arr[i][j]+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

}
