import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	private Scanner sc = new Scanner(System.in);
	
	private void solve() throws FileNotFoundException {
	    //Scanner sc = new Scanner(new FileInputStream("input.txt"));
	    String str = sc.nextLine();
	    //System.out.println(str);
	    
	    int flagTag=0;
	    int idxWord=-1;
	    for(int i=0; i<str.length(); i++) {
	    	
	    	//태그의 경우 바로 출력함 
	    	if(str.charAt(i)=='<') { //태그는 찾는 즉시 바로 출력
	    		if(idxWord!=-1) { //태그가 나오기 전에 단어가 나온 경우
	    			for(int j=i-1; j>=idxWord; j--) {
	    				System.out.print(str.charAt(j));
	    			}
	    			idxWord=-1;
	    		}
	    		
	    		flagTag=1;
	    		System.out.print(str.charAt(i));
	    	}
	    	else if(str.charAt(i)=='>') {
	    		flagTag=0;
	    		System.out.print(str.charAt(i));
	    	}
	    	else if(flagTag==1) {
	    		System.out.print(str.charAt(i));
	    	}
	    	
	    	else if(flagTag==0 && idxWord==-1) { //단어의 첫글자를 만난 경우
	    		idxWord=i;
	    	}
	    	else if(str.charAt(i)==' ' && idxWord!=-1) { //하나의 단어가 끝난 경우 출력
	    		
	    		//idxWord부터 i 전까지 순서를 뒤집어줌
	    		for(int j=i-1; j>=idxWord; j--) {
	    			System.out.print(str.charAt(j));
	    		}
	    		System.out.print(str.charAt(i)); //공백도 출력 
	    		idxWord=-1;
	    	}
	    	else if(i==str.length()-1) { //마지막 단어인 경우 
	    		if(flagTag==0 && idxWord!=-1) { //태그가 아니라면
	    			for(int j=i; j>=idxWord; j--) {
		    			System.out.print(str.charAt(j));
		    		}
	    		}
	    	}
	    	
	    	
	    	//System.out.print(str.charAt(i));
	    	
	    	//마지막 단어는 따로 출력해줘야함 
	    }
	    
	    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}