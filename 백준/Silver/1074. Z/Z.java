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

        recursive(r,c,(int)Math.pow(2,n));
        System.out.println(ans);
    }

    private static void recursive(int r, int c, int size) {
        if(size==1) return;

        int half = size/2;
        //1사분면
        if(r<half && c<half) {
            recursive(r,c,half);
        }
        //2사분면
        else if(r<half && c>=half){
            ans+=half*half;
            recursive(r,c-half,half);
        }
        //3사분면
        else if(r>=half && c<half){
            ans+=2*half*half;
            recursive(r-half, c, half);
        }
        //4시분면
        else if(r>=half && c>=half){
            ans+=3*half*half;
            recursive(r-half, c-half, half);
        }
    }
}