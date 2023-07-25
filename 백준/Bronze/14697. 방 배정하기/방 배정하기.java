import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
private void solve() throws FileNotFoundException {
    Scanner sc = new Scanner(System.in);
	//Scanner sc = new Scanner(new FileInputStream("input.txt"));
    
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int n = sc.nextInt();
    
    for(int i=0; i<n/a; i++) {
    	for(int j=0; j<n/b; j++) {
    		for(int k=0; k<n/c; k++) {
    			if(a*i+b*j+c*k==n) {
    				System.out.println(1);
    				return;
    			}
    		}
    	}
    }
    System.out.println(0);
    
    
    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}