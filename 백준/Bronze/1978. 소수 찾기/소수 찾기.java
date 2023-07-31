import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	private Scanner sc = new Scanner(System.in);
	
	private void solve() throws FileNotFoundException {
	    //Scanner sc = new Scanner(new FileInputStream("input.txt"));
	    int n = sc.nextInt();
	    int cnt=0; //n개 중 소수는 몇 개인지를 확인하기
	    
	    for(int i=0; i<n; i++) {
	    	int x = sc.nextInt();
	    	
	    	if(x==1) continue; //1이면 소수가 아님 
	    	int flag=1;
	    	for(int j=2; j*j<=x; j++) {
	    		if(x%j==0) flag=0; //소수가 아님 
	    	}
	    	
	    	if(flag==1) cnt++;
	    }
	    System.out.println(cnt);
	    
	    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}