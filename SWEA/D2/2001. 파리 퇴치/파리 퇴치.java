import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) throws FileNotFoundException {
        //System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();

        for(int t=1; t<=tc; t++){
            //입력 받기
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] arr = new int[n][n];

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    arr[i][j] = sc.nextInt();
                }
            }

            int ans=-1;
            for(int i=0; i<n-m+1; i++) {
                for (int j = 0; j < n - m + 1; j++) {
                    int sum = 0;

                    for(int a=i; a<i+m; a++){
                        for(int b=j; b<j+m; b++){
                            sum+=arr[a][b];
                        }
                    }
                    ans = Math.max(ans, sum);
                }
            }
            System.out.println("#"+t+" "+ans);
        }
    }
}