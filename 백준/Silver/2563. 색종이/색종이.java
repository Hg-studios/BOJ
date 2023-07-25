import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
private void solve() {
    Scanner sc = new Scanner(System.in);
	//Scanner sc = new Scanner(new FileInputStream("input.txt"));
    
    int n = sc.nextInt();
    int[][] board = new int[100][100];
    
    int cnt=0;
    for(int i=0; i<n; i++) {
    	int x = sc.nextInt();
    	int y = sc.nextInt();
    	
    	for(int j=x; j<x+10; j++) {
    		for(int k=y; k<y+10; k++) {
    			if(board[j][k]==0) {
    				cnt++;
    				board[j][k]=1;
    			}
    		}
    	}
    }
    System.out.println(cnt);
    
    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}