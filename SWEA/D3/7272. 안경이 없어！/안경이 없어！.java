import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	private String solve()  {
	    
		//Scanner sc = new Scanner(new FileInputStream("input.txt"));
	    	String str1 = sc.next(); 
	    	String str2 = sc.next();
	    	
	    	if(str1.length()!=str2.length()) {
	    		return "DIFF";
	    	}
	    	
	    	for(int i=0; i<str1.length(); i++) {
	    		char c1 = str1.charAt(i);
	    		char c2 = str2.charAt(i);
	    		//B인 경우
	    		if(c1=='B') {
	    			if(c2!='B') return "DIFF";
	    		}
	    		//ADOPQR인 경우
	    		else if(c1=='A'||c1=='D'||c1=='O'||c1=='P'||c1=='Q'||c1=='R') {
	    			if(c2=='A'||c2=='D'||c2=='O'||c2=='P'||c2=='Q'||c2=='R') ;
	    			else return "DIFF";
	    		}
	    		//CEFGHIJKLMNSTUVWXYZ인 경우
	    		else {
	    			if(c2=='B'||c2=='A'||c2=='D'||c2=='O'||c2=='P'||c2=='Q'||c2=='R')
	    				return "DIFF";
	    		}
	    	}
	    	return "SAME";
	}

	public static void main(String[] args) throws Exception {
		int tc = sc.nextInt();
	    
	    for(int t=1; t<=tc; t++) {
	    	System.out.println("#"+t+" "+new Solution().solve());
	    }
	    
	    sc.close();
	    
	}
}
