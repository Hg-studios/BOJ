import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	static int[] dx = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] dy = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 };
	
	public static void main(String[] args) {
		int tc = sc.nextInt();
		
		for(int t=1; t<=tc; t++) {
			System.out.print("#"+t+" ");
			new Solution().solve();
		}
	}
	
	
	private void solve() {
		int n = sc.nextInt(); //4,6,8 중 하나 
		int m = sc.nextInt();
		
		int[][] arr = new int[n][n];
		
		//처음에 4개 돌 놓기
		//1: 흑돌, 2: 백돌
		arr[n/2-1][n/2-1]=2;
		arr[n/2][n/2]=2;
		arr[n/2-1][n/2]=1;
		arr[n/2][n/2-1]=1;
		
		for(int cs=0; cs<m; cs++) {
			int y = sc.nextInt()-1;
			int x = sc.nextInt()-1;
			int c = sc.nextInt();
			
			int cnt=0;
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(arr[i][j]==0) cnt++;
				}
			}
			if(cnt==0) break; //다 찼으면 끝냄 
			
            arr[x][y]=c;
            
			//8방 탐색
			for(int i=0; i<8; i++) {
				int flag = 0;
				
				//해당 방향으로 최대 7칸을 이동할 수 있음 
				//해당 방향으로 최대 몇 칸까지 이동할 수 있는지 확인하는 부분 
				for(int k=1; k<n; k++) { 
					int nx = x + dx[i]*k;
					int ny = y + dy[i]*k;
					
					if(nx<0||ny<0||nx>=n||ny>=n) break; //바꿀 부분을 찾지 못하고 범위를 벗어남
					if(arr[nx][ny]==0) break; //이쪽 방향으로는 바꿀 수 없음
					if(arr[nx][ny]==c && flag==0) break; //같은색이나왔지만 중간에 다른색이 없었던 경우
					
					if(arr[nx][ny]!=0 && arr[nx][ny]!=c) flag = 1; //다른색이 나온경우 바꿔줄수 있으므로 표시
					if(arr[nx][ny]==c) { //바꿔줄 칸이 있는 경우에 다시 나의색이 나온 경우
						while(true) {
							if(nx==x && ny==y) break;
							
							nx = nx-dx[i];
							ny = ny-dy[i];
							arr[nx][ny]=c;
						}
						break; //색을 바꿔줬으니 빠져나와야함
					}
				}
			}
		}
		
		int b=0, w=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(arr[i][j]==1) b++;
				else if(arr[i][j]==2) w++;
			}
		}
		System.out.println(b+" "+w);
	}
}
