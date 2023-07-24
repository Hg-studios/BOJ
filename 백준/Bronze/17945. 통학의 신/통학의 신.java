import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    private void solve(){
        //Scanner sc = new Scanner(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		int x1 = -a - (int)(Math.sqrt(a*a-b));
		int x2 = -a + (int)(Math.sqrt(a*a-b));
		
		if(x1==x2) System.out.println(x1);
		else {
			System.out.println(x1+" "+x2);
		}
    }
    
    
	public static void main(String[] args) throws Exception {
		new Main().solve();
	}
	
}
