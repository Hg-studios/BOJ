import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
private void solve() {
    Scanner sc = new Scanner(System.in);
    //Scanner sc = new Scanner(new FileInputStream("input.txt"));
    
    int ans = 0;
    for(int i=0; i<10; i++) {
    	int x = sc.nextInt();
    	if(Math.abs(100-ans) >= Math.abs(100-(ans+x))) ans+=x;
        else break;
    }
    System.out.println(ans);
    
    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}