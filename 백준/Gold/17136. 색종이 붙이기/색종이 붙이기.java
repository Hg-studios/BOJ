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
    static int arr[][];
    static int ans=Integer.MAX_VALUE;
    static int[] colorPaper;

    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        //초기화
        arr = new int[10][10];
        colorPaper = new int[] {0,5,5,5,5,5};

        //입력받기
        for (int i = 0; i < 10; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 1인 부분을 찾으면 붙일 수 있는 최대크기 색종이부터 작은사이즈 순으로 백트래킹함
        recursive(0,0,0); //x, y, cnt
        if(ans==Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }
    private static void recursive(int x, int y, int cnt) {
        //색종이를 붙일 수 있는 곳을 찾음
        boolean flag = false;

        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {

                if(arr[i][j]==1) { //색종이가 붙어있다면
                    flag=true; //색종이 붙일 좌표를 찾았음을 표시함

                    //붙일 공간을 찾아봄
                    //색종이 크기 1부터 5까지 돌면서 붙일 수 있는 색종이를 찾음
                    for(int c=1; c<=5; c++) {
                        if(colorPaper[c]<1) continue; //색종이를 다 써서 붙일 수가 없는 상황

                        if(check(i,j,c)) { //붙일 수 있는 크기라면
                            updatePaper(i,j,c,0); //arr갱신해줌, 색종이를 붙였으니 arr값을 1에서 0으로 바꿔줌
                            colorPaper[c]-=1; //한장 썼으니 -1 해줌

                            recursive(i+c, j+c, cnt+1); //재귀를 부름

                            colorPaper[c]+=1; //다시 원상복구 해줌
                            updatePaper(i,j,c,1); //arr다시 원래로 돌려줌
                        }
                    }
                    if(arr[i][j]==1) return; //종이는 있지만 붙이지 못한 경우 ?? 이게 몬경우지??

                }
            }
        }

        //더이상 탐색할 곳이 없다면 return 해줘야 함
//        if(checkFinish()) {
//            ans = Math.min(ans, cnt);
//
//            return;
//        }
        if(!flag) {
            ans = Math.min(ans, cnt);

            return;
        }
        //if(!flag) return; //탐색 좌표가 없다면 return

    }
    private static boolean checkFinish() {
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                if(arr[i][j]==1) return false;
            }
        }
        return true;
    }
    private static void updatePaper(int x, int y, int size, int cond) { //x,y부터 size만큼 cond가 1이면 종이를 붙이고 cond가 0이면 종이가를 뗌
        for(int i=x; i<x+size; i++) {
            for(int j=y; j<y+size; j++) {
                if(i>=10 || j>=10) continue;
                if(cond==1) {
                    arr[i][j]=1;
                }
                else {
                    arr[i][j]=0;
                }
            }
        }
    }
    private static boolean check(int x, int y, int size) {
        for(int i=x; i<x+size; i++) {
            for(int j=y; j<y+size; j++) {
                if(i>=10 || j>=10) return false; //범위를 벗어남
                if(arr[i][j]==0) return false; //색종이를 붙일 수 없음
            }
        }

        return true; //범위를 벗어나지 않았거나 색종이를 붙일 수 있다면 true를 반환
    }
}