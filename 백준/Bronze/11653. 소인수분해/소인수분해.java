import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	private Scanner sc = new Scanner(System.in);
	
	private void solve() throws FileNotFoundException {
	    //Scanner sc = new Scanner(new FileInputStream("input.txt"));
	    int n = sc.nextInt();
	    
	    if(n!=1) {
	    	List<Integer> list = new ArrayList<Integer>(); //소인수분해한 결과 저장 
	    	
	    	int isPrime;
	    	while(true) {
	    		isPrime=1; //n이 소수인지 체크하기, 밑의for문을 돌고나서도 변수값이 0이면 소인수분해 끝난 상황 
	    		
	    		for(int i=2; i*i<=n; i++) {
	    			if(n%i==0) {
	    				isPrime=0; //아직 소인수분해 안끝남 
	    				n /= i; //n을 i로 나눈 값으로 업데이트해줌 
	    				list.add(i); //i는 소인수에 해당함, i가 가장 작은 소수일수밖에없음!!!
                        break; //n에서의 가장 작은 소인수를 구했으니 빠져나옴 
	    			}
	    		}
	    		
	    		if(isPrime==1) { //소인수분해가 끝났다면
                    list.add(n); //마지막 소인수 넣어줌
                    break;
                }
	    	}
	    	
	    	for (Integer i : list) {
				System.out.println(i);
			}
	    	
	    }
	    
	    sc.close();
	}

	public static void main(String[] args) throws Exception {
	    new Main().solve();
	}
}