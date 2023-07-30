import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		//int tc = sc.nextInt();
		
		for(int t=1; t<=10; t++) {
			System.out.println("#"+t+" "+new Solution().solve());
		}
	}

	private int solve() {
		int n = sc.nextInt();
		String str = sc.next();
		List<Integer> list = new ArrayList<Integer>();
		
		//입력받기
		for(int i=0; i<str.length(); i++) {
			list.add(str.charAt(i)-'0');
		}
		
		//int flag = 1; //빠져나갈 수 있는지 확인
		while(true) {
			int flag=1; //검사하는 매 turn마다 빠져나갈 수 있는지를 확인해야함 
			//같은 수 검사하기
			for(int i=0; i<list.size()-1; i++) {
				if(list.get(i).equals(list.get(i+1))) {
					list.remove(i); //remove하는 순간 없어지는 것임..!!!!
					list.remove(i);
					flag=0; //같은 수가 있는 상태 
					break;
				}
			}
			//더이상 같은 수가 없다면 
			if(flag==1) break;
		}
		
		int ans =0;
		for (Integer i : list) {
			ans = ans*10+i;
		}
		
		return ans;
	}
}
