import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
private void solve() {
    Scanner sc = new Scanner(System.in);
    //Scanner sc = new Scanner(new FileInputStream("input.txt"));

    int n = sc.nextInt();

    int cnt=0;
    for(int i=1; i<=500; i++) { //a
    	for(int j=1; j<=i; j++) { //b
    		if(i*i-j*j==n) cnt++;
    	}
    }
    System.out.println(cnt);
    
    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}