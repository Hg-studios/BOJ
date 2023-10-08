import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb;
	static int n, ans=Integer.MAX_VALUE;
	static int[] num;
	static boolean[][] list;
	static boolean[] select;

	public static void main(String[] args) throws Exception {
		n = Integer.parseInt(br.readLine());
		
		//초기화
		num = new int[n];
		list = new boolean[n][n];
		select = new boolean[n];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int end = Integer.parseInt(st.nextToken());
			for (int j = 0; j < end; j++) {
				int idx = Integer.parseInt(st.nextToken())-1;
				list[i][idx] = true;
				list[idx][i] = true;
			}
		}
		
		
//		for (boolean[] string : list) {
//			System.out.println(Arrays.toString(string));
//		}
		
		//선거구 나누기 
		seperate(0);
		
		System.out.println(ans==Integer.MAX_VALUE?-1:ans);
	}

	private static void seperate(int cnt) {
		if(cnt==n) {
			
			List<Integer> listA = new ArrayList<>();
			List<Integer> listB = new ArrayList<>();
			
			
			int sumA=0, sumB=0;
			for (int i = 0; i < n; i++) {
				if(select[i]) {
					sumA += num[i];
					listA.add(i);
				}
				else {
					sumB += num[i];
					listB.add(i);
				}
			}
			
			
			if(listA.size()==0 || listB.size()==0) return;
			
			
			if(!bfs(listA)) return;
			if(!bfs(listB)) return;
			
			ans = Math.min(ans, Math.abs(sumA-sumB));
			
			
			return;
		}
		
		//A
		select[cnt]=true;
		seperate(cnt+1);
		
		//B
		select[cnt]=false;
		seperate(cnt+1);
		
	}

	//list를 받아서 그 팀끼리 연결되어 있는지 확인하는 함수 
	private static boolean bfs(List<Integer> listA) {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		boolean visited[] = new boolean[n];
		
		boolean team = select[listA.get(0)];
		visited[listA.get(0)] = true;
		q.add(listA.get(0));
		
		int cnt=0;
		while(!q.isEmpty()) {
			int cur = q.poll();
			cnt++;
			
			for (int i = 0; i < n; i++) {
				if(!list[cur][i]) {
					continue;
				}
				if(visited[i]) {
					continue;
				}
				if(select[i]!=team) {
					continue;
				}
				
				visited[i]=true;
				q.add(i);
			}
		}
		
		return cnt==listA.size();
	}
}
