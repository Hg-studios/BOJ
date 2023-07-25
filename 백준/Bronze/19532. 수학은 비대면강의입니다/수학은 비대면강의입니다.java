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
    int d = sc.nextInt();
    int e = sc.nextInt();
    int f = sc.nextInt();
    
    for(int i=-999; i<=999; i++) {
    	for(int j=-999; j<=999; j++) {
    		if(a*i+b*j==c && d*i+e*j==f) {
    			System.out.println(i+" "+j);
    			return;
    		}
    	}
    }
    
    
    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}