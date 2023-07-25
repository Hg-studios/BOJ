import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
private void solve() {
    Scanner sc = new Scanner(System.in);
    //Scanner sc = new Scanner(new FileInputStream("input.txt"));

    int n = sc.nextInt();

    int cnt=0;
    for(int i=1; i<n-1; i++) { //남규
        for(int j=1; j<n-1; j++) { //영훈
            for(int k=1; k<n-1; k++) { //택희
                if(i+j+k==n) {
                    if(i-j>=2) {
                        if(k%2==0) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    System.out.println(cnt);


    sc.close();
}

public static void main(String[] args) throws Exception {
    new Main().solve();
}
}