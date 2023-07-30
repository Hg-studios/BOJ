import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private Scanner sc = new Scanner(System.in);
	
	private void solve() throws FileNotFoundException {
	    //Scanner sc = new Scanner(new FileInputStream("input.txt"));
	    
	    int n = sc.nextInt();
	    int m = sc.nextInt();
	    
	    int[] arr = new int[n];
	    for(int i=0; i<n; i++) {
	    	arr[i] = sc.nextInt();
	    }
	    
	    int ans =0;
	    for(int i=0; i<n-2; i++) {
	    	for(int j=i+1; j<n-1; j++) {
	    		for(int k=j+1; k<n; k++) {
	    			int sum = arr[i]+arr[j]+arr[k];
	    			if(sum<=m) ans= Math.max(ans, sum);
	    		}
	    	}
	    }
	    System.out.println(ans);
	    
	    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}