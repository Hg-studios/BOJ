import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
private void solve() {
    Scanner sc = new Scanner(System.in);
    //Scanner sc = new Scanner(new FileInputStream("input.txt"));

    int n = sc.nextInt();
    int m = sc.nextInt();
    int k = sc.nextInt();
    
    int ans = 0;
    for(int i=0; i<=k; i++) {
    	//시험 볼 k명을 여자와 남자에서 빼줌 
    	int girl = n-i;
    	int boy = m-(k-i);
    	
    	if(girl<0 || boy<0) continue;
    	
    	//현재 여자 명수로 만들 수 있는 최대 팀 수를 구함
    	for(int j=girl; j>1; j--) {
    		//현재 여자의 수에 해당하는 남자가 있을 때 팀 결성
    		if(j/2<=boy) ans = Math.max(ans, j/2);
    	}
    }
    System.out.println(ans);
    
    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}