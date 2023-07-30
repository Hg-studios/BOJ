import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		//int tc = sc.nextInt();
		
		new Main().solve();
	}
	
	private void solve() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int l = sc.nextInt();
		
		int[] cnt = new int[n]; //각 사람이 공을 몇 번 받았는지 체크
		
		int turn = 0;
		while(true) {
			cnt[turn]++;
			if(cnt[turn]>=m) break;
			
			if(cnt[turn]%2==1) turn = (turn+l)%n;
			else turn = (n+turn-l)%n;
		}
		
		int ans=0;
		for(int i=0; i<n; i++) ans+=cnt[i];
		System.out.println(ans-1);
	}
}
