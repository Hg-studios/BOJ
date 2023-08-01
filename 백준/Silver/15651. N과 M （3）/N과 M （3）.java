import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int[] arr = new int[] {1,2,3,4,5,6,7,8};
    static int[] select = new int[8];
    //static boolean[] visited = new boolean[9];
    public static StringBuilder sb = new StringBuilder();
    static int n,m;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        recursive(0); //select의 idx, 모든 배열의 인덱스는 1부터 시작함**
        System.out.print(sb);
    }

    private static void recursive(int idx) {
        //basis
        if(idx==m) { //m개 가 다 차고 나서
            //select 배열에 추가하기
            for(int i=0; i<m; i++){
                sb.append(select[i]+" ");
            }
            sb.append('\n');
            return;
        }

        //inductive
        for(int i=0; i<n; i++) {
            select[idx] = arr[i];
            recursive(idx+1);
        }
    }
}