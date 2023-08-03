import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	int[] arr = new int[9];
	int[] select = new int[9];
	boolean[] visited = new boolean[9];
	int n, m;
	StringBuilder sb = new StringBuilder();
	
	public void solve() throws NumberFormatException, IOException {
		Scanner sc = new Scanner(System.in);
		
		//입력 받기
		n = sc.nextInt();
		m = sc.nextInt();
		//배열 
		for(int i=0; i<n; i++) {
			arr[i]=i+1;
		}
		
		recursive(0,0);
		System.out.println(sb);
		
		sc.close();
	}
	
	//1-n까지 순열
	private void recursive(int cnt, int start) { //idx : select의 인덱스
		if(cnt==m) {
			//출력하기
			
			for(int i=0; i<m; i++) {
				sb.append(select[i]+" ");
			}
			sb.append('\n');
			
			return;
		}
		
		//inductive
		for(int i=start; i<n; i++) { //arr배열의 인덱스 설정
			select[cnt] = arr[i];
			recursive(cnt+1, i+1);
		}
		
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		new Main().solve();
	}
}