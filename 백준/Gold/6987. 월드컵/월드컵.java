import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    //대진표 만들기, 0~5 까지 조합 만들기

    int[][] match = new int[][]{{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
            {1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};

    int[][] input;
    int[][] output;
    int ans;

    public static void main(String[] args) throws Exception {
        new Main().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);

        for(int tc=0; tc<4; tc++){
            //입력받기
            input = new int[6][3];
            output = new int[6][3];
            ans = 0;

            for(int i=0; i<6; i++){
                for(int j=0; j<3; j++){
                    input[i][j] = sc.nextInt();
                }
            }
            recursive(0);
            System.out.println(ans);
        }
    }

    public void recursive(int idx){
        if(idx==15) {
            if(ans==1) return; //이미 가능한 경우로 판단된 경우

            //입력배열값과 결과배열값과 비교하여 일치하면 1 리턴
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    if (input[i][j] != output[i][j]) {
                        return;
                    }
                }
            }
            ans=1; //전부 일치하는 경우에만 1로 표시
            return;
        }

        int team1 = match[idx][0];
        int team2 = match[idx][1];

        //team1 승리
        output[team1][0]+=1;
        output[team2][2]+=1;

        recursive(idx+1);
        output[team1][0]-=1;
        output[team2][2]-=1;

        //team1 무승부
        output[team1][1]+=1;
        output[team2][1]+=1;
        recursive(idx+1);
        output[team1][1]-=1;
        output[team2][1]-=1;

        //team1 패배
        output[team1][2]+=1;
        output[team2][0]+=1;
        recursive(idx+1);
        output[team1][2]-=1;
        output[team2][0]-=1;
    }
}