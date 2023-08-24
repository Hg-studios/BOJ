import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int n, d, k, c, ans, cnt;
    static int[] kind, dishes;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        //초기화
        dishes = new int[n];
        kind = new int[d+1]; //초밥의 종류를 저장

        for (int i = 0; i < n; i++) {
            dishes[i] = Integer.parseInt(br.readLine());
        }

        //처음 k개의 초밥을 먹음
        for (int i = 0; i < k; i++) {
            if(kind[dishes[i]]==0){
                ans++;
            }
            kind[dishes[i]]++;
        }
        //쿠폰에 적힌 초밥이 새로운 종류라면
        cnt = ans;
        ans = (kind[c]==0)? cnt+1 : cnt;

        //이제 하나씩 먹을 것임 -> 하나 먹고 하나 빼고 하면서 슬라이딩으로
        sliding();

        System.out.println(ans);
    }

    private static void sliding() {
        int start = k;

        while(true){
            //슬라이드를 밀면서 전에 먹었던 스시는 빼줌
            kind[dishes[(start-k)%n]]--;
            //이전 스시 뺐는데 0이면 종류에서도 하나 빼줌
            if(kind[dishes[(start-k)%n]]==0) cnt--;

            //그 다음 추가되는 스시 더해줌
            if(kind[dishes[start%n]] == 0){
                cnt++;
            }
            kind[dishes[start%n]]++;

            //앞스시는 빼고 뒷스시는 넣었으니 이번 차례는 다 본것임
            //몇 종류의 스시를 먹었는지 확인하기
            ans = Math.max(ans, (kind[c]==0)? cnt+1 : cnt);

            //그 다음 스시로 넘어감
            start++;
            //한 바퀴를 다 돌았다면 끝냄
            if(start == n-1+k) break;
        }
    }
}
