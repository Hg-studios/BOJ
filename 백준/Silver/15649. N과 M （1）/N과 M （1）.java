import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int[] arr = new int[] {0,1,2,3,4,5,6,7,8};
    static int[] select = new int[9];
    static boolean[] visited = new boolean[9];
    static int n,m;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        recursive(1); //select의 idx, 모든 배열의 인덱스는 1부터 시작함**
    }

    private static void recursive(int idx) {
        //basis
        if(idx==m+1) { //m개 가 다 차고 나서
            //select 배열 출력해주기
            for(int i=1; i<=m; i++) {
                System.out.print(select[i]+" ");
            }
            System.out.println();
        }

        //inductive
        for(int i=1; i<=n; i++) {
            if(!visited[i]) { //아직 뽑히지 않은 원소를 선택함
                select[idx] = arr[i];
                visited[i]=true;
                recursive(idx+1);
                visited[i]=false;

            }
        }
    }


}