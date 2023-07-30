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
	    int[] arr = new int[n];
	    
	    for(int i=0; i<n; i++) {
	    	arr[i] = sc.nextInt();
	    }
	    
	    Arrays.sort(arr);
	    
	    int ans = 0;
	    for(int i=0; i<n; i++) {
	    	for(int j=0; j<=i; j++) {
	    		ans+=arr[j];
	    	}
	    }
	    System.out.println(ans);
	    
	    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}