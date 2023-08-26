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
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static int n, d, k, c;
	static int[] arr; //회전초밥 접시 수, 하나씩 볼 것임  
	static int[] kind; //초밥 가짓 수
	static int ans, cnt;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken()); 
		d = Integer.parseInt(st.nextToken()); 
		k = Integer.parseInt(st.nextToken()); 
		c = Integer.parseInt(st.nextToken());
		
		//초기화
		arr = new int[n];
		kind = new int[d+1];
		
		//회전초밥 벨트에 놓은 접시 
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		//처음 k개를 봄 
		for (int i = 0; i < k; i++) {
			if(kind[arr[i]]==0) ans++; //처음으로 먹는 스시 종류이면 ans를 하나 증가시킴
			kind[arr[i]]++; //이번 스시 종류에 대한 값 하나 증가시킴
		}
		
		cnt = ans; //한번 k개를 보고 난 후의 값을 cnt에 저장해둠, 쿠폰을 제외한 스시 종류값을 저장 
		ans = (kind[c]==0) ? cnt+1 : cnt;
		
		sliding();
		
		System.out.println(ans);
	}

	private static void sliding() {
		int start = 1;
		while(true) {
			//System.out.println("**"+start);
			//한칸 밀린 초밥을 빼줌 
			int minus = start-1;
			//System.out.println(minus%n);
			kind[arr[minus%n]]--;
			if(kind[arr[minus%n]]==0) cnt--;
			
			//한칸 새로 들어온 초밥을 더해줌 
			int add = start+k-1;
			//System.out.println(add%n);
			if(kind[arr[add%n]]==0) cnt++;
			kind[arr[add%n]]++;
			
			//쿠폰 적용 되는지 체크
			//cnt = (kind[c]==0)? cnt+1 : cnt;
			//이번 차례에서 구한 답으로 업데이트해줌
			ans = Math.max(ans, (kind[c]==0)? cnt+1 : cnt);
			
			start++; //다음 k개 보러 감 
			if(start==n) break; //다 봤으면 끝냄 
		}
	}
}