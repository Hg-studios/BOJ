import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
private void solve() throws FileNotFoundException {
    Scanner sc = new Scanner(System.in);
	//Scanner sc = new Scanner(new FileInputStream("input.txt"));
    
    //입력 받기
    int[] n = new int[5];
    for(int i=0; i<5; i++) {
    	n[i] = sc.nextInt();
    }
    
    int ans = Integer.MAX_VALUE;
    for(int i=0; i<5; i++) {
    	int mul=1; //곱해지는 배수 1->2->3->..
    	while(true) {
    		int num = n[i]*mul;
    		//배수가 이전에 나왔던 정답보다 커지면 더이상 탐색할 필요가 없음 
    		if(num>ans) break;
    		
    		int cnt=0;
    		//해당 배수가 적어도 대부분의 배수인지 체크
    		for(int j=0; j<5; j++) {
    			if(num%n[j]==0) cnt++;
    		}
    		//맞다면 정답을 갱신해주고 해당 자연수의 탐색은 그만함
    		if(cnt>=3) {
    			ans = Math.min(ans, num);
    			break;
    		}
    		mul++;
    	}
    }
    
    System.out.println(ans);
    
    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}