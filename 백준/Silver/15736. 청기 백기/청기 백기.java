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
	    
	    int ans = 0;
	    for(int i=1; i*i<=n; i++) {
	    	ans++;
	    }
	    System.out.println(ans);
	    
	    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}