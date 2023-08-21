import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int n, k;
    static int[] arr, check;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        //초기화
        arr = new int[n];
        check = new int[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }

        //처음에 영기가 시작함
        check[0]=1; //영기는 방문을 했으므로 체크함
        int turn = arr[0]; //다음턴 사람을 구함
        int m=1; //영기가 말해야 하는 가장 작은 수임
        //사이클이 생길 수 있음.
        //문제는 k가 없는 상태로 사이클이 생기면 -1을 출력해야 함
        while(true){
            if(turn==k){ //이번 사람이 보성이라면
                break; //찾은 것이므로 끝냄
            }
            if(check[turn]==1){ //내가 이미 나온 적이 있다면 사이클이 생긴 것임
                m=-1; //그렇다면 보성이한테 갈 수 없으므로 -1을 출력해야 함
                break;
            }
            //보성이도 아니고 이미 나온 적도 없다면
            check[turn]=1; //방문 체크
            turn = arr[turn]; //다음 지목하는 사람으로 turn을 옮김
            m++; //차례가 한 번 더 늘어남
        }

        System.out.println(m);

    }
}