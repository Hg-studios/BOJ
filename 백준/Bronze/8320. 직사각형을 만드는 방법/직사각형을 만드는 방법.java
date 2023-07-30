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
	    
	    int cnt=0;
	    for(int i=1; i<=n; i++) {
	    	for(int j=i; i*j<=n; j++) {
	    		cnt++;
	    	}
	    }
	    System.out.println(cnt);
	    
	    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}