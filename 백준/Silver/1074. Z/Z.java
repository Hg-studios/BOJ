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
    static int n,r,c, ans;

    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        recursive(0,0,(int)Math.pow(2,n));
        System.out.println(ans);
    }

    private static void recursive(int x, int y, int size) { //x,y는 시작점 r,c는 찾는점
        if(size==1) return;

        int half = size/2;
        //1사분면
        if(r<x+half && c<y+half){
            recursive(x,y,half);
        }
        else if(r<x+half && c>=y+half){
            ans+= half*half;
            recursive(x, y+half, half);
        }
        else if(r>=x+half && c<y+half){
            ans += 2*half*half;
            recursive(x+half, y, half);
        }
        else{
            ans += 3*half*half;
            recursive(x+half, y+half, half);
        }
    }
}