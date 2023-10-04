import java.io.*;
import java.util.*;

public class Solution {
	
    static class Point{
    	int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
    	
    	public void move(int dir) {
    		if(dir==1) y--;
    		else if(dir==2) x++;
    		else if(dir==3) y++;
    		else if(dir==4) x--;
    	}
    }
    
    static class BC{
    	int x, y, c, p;

		public BC(int x, int y, int c, int p) {
			super();
			this.x = x;
			this.y = y;
			this.c = c;
			this.p = p;
		}
    }
    
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int m, a, ans;
    static int[] amove, bmove;
    static BC[] BCs;
   
    public static void main(String[] args) throws NumberFormatException, IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		
    	int t = Integer.parseInt(br.readLine());
    	
    	for (int tc = 1; tc <= t; tc++) {
			st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			a = Integer.parseInt(st.nextToken());
			
			//초기화
			BCs = new BC[a];
			amove = new int[m];
			bmove = new int[m];
			ans = 0;
			
			//a이동 입력받기
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				amove[i] = Integer.parseInt(st.nextToken());
			}
			
			//b이동 입력받기
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				bmove[i] = Integer.parseInt(st.nextToken());
			}
			
			for (int i = 0; i < a; i++) {
				st = new StringTokenizer(br.readLine());
				// BC 정보 (x, y, c, p 저장)
				BCs[i] = new BC(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
						Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}

			solve();
			
			sb = new StringBuilder();
			sb.append("#"+tc+" "+ans);
			System.out.println(sb);
		}
	}

	private static void solve() {
		//Point객체인 A, B를 만들고 이 둘을 이동시키면서 이동할 때마다 charge가 되는지 확인함 
		Point userA = new Point(1,1);
		Point userB = new Point(10,10);
		
		//처음 좌표에서도 충전 가능한지 판단해야함
		charge(userA, userB);
		
		for (int i = 0; i < m; i++) {
			userA.move(amove[i]);
			userB.move(bmove[i]);
			charge(userA, userB);
		}
	}

	private static void charge(Point userA, Point userB) {
		//현재 A, B의 자리에서 BCs까지의 거리를 구하고 충전가능한 것만 list에 저장함
		//저장된 listA, listB에 대해서 각 상황에 맞게 처리해줌 
		
		List<Integer> listA = new ArrayList<>();
		List<Integer> listB = new ArrayList<>();
		
		for (int i = 0; i < a; i++) { //모든 BC를 모두 검사함 
			//A와 BC 사이의 거리 구하기
			if(BCs[i].c >= (Math.abs(BCs[i].x-userA.x)) + (Math.abs(BCs[i].y - userA.y))) {
				listA.add(i);
			}
			//B와 BC 사이의 거리 구하기
			if (BCs[i].c >= (Math.abs(BCs[i].x - userB.x)) + (Math.abs(BCs[i].y - userB.y))) {
				listB.add(i);
			}
		}
		
		
		//listA와 listB의 사이즈에 따라서 처리하는 일이 다름
		int max=0, tmp=0;
		
		//1. A와 B가 접속 가능한 BC가 1개 이상이라면 
		if(listA.size()>0 && listB.size()>0) {
			//중복 조합을 통해 누가 어떤 BC에 접속하는 것이 가장 이득인지를 구해야함
			for(int i : listA) {
				for(int j : listB) {
					tmp = 0;
					
					//같은 BC에 접속하게 되면 값을 나눠갖게 되므로 한 번만 더한 것과 같음
					if(i==j) { 
						tmp = BCs[i].p;
					}
					else {
						tmp += BCs[i].p;
						tmp += BCs[j].p;
					}
					
					max = Math.max(max, tmp);
				}
			}
		}
		//2. A가 접속 가능한 BC가 1개 이상이라면
		else if(listA.size() > 0) {
			for(int i : listA) {
				if(max < BCs[i].p) {
					max = BCs[i].p;
				}
			}
		}
		//3. // B가 접속 가능한 BC가 1개 이상이라면
		else if(listB.size() > 0) {
			for(int i : listB) {
				if(max < BCs[i].p) {
					max = BCs[i].p;
				}
			}
		}
		
		ans += max;
	}
}