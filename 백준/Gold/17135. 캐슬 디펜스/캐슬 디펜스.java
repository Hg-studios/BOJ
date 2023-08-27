import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int n,m,d,ans=Integer.MIN_VALUE;
    static boolean[][] enemy, enemyCopy;
    static List<int[]> archer; //궁수 위치를 담는 리스트

    static int[] dr = {0,-1,1,0,0};
    static int[] dc = {0,0,0,1,-1};

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        //초기화
        enemy = new boolean[n][m];
        enemyCopy = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                if(Integer.parseInt(st.nextToken())==1){
                    enemy[i][j]=true;
                }
                else enemy[i][j]=false;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                for (int k = j+1; k < m; k++) {
                    archer = new ArrayList<>(); //각 조합마다 리스트 생성

                    //i j k 세 사람이 뽑힘
                    archer.add(new int[] {n,i}); //처음엔 n행에 있음
                    archer.add(new int[] {n,j});
                    archer.add(new int[] {n,k});

                    //매번 enemy가 표시된 배열을 복사하여 사용해야 함 -> 0으로 바꾸기 때문
                    for (int l = 0; l < n; l++) {
                        for (int o = 0; o < m; o++) {
                            enemyCopy[l][o] = enemy[l][o];
                        }
                    }

                    //뽑힌 궁수 3명으로 적을 잡음
                    ans = Math.max(ans,attack());
                }
            }
        }

        System.out.println(ans);
    }

    private static int attack() {
        int cnt=0;
        int turn = n;
        while(true){ //궁수의 위치를 한칸씩 줄여나갈 건데 0보다 클 때까지만 반복함
            //적이 아무도 없으면 끝냄
            if(!remainEnemy(turn)) break;

            //이번 턴에서 찾은 삭제할 적들의 좌표를 저장할 list
            //중복되는 좌표가 있을 수 있므으로 한 번 더 온 좌표는 ans++를 해주지 않음
            List<int[]> deleteEnemy = new ArrayList<>();

            //적이 한명이라도 남아있다면 각 적을 기준으로 3명의 궁수와의 거리를 구함
            for (int[] a : archer) { //궁수 3명에 대해서 공격 가능한 적의 좌표를 창음
               int r = a[0]; //현재 궁수의 좌표
               int c = a[1];
               int minEnemyR = -1; //현재 궁수가 공격할 적의 좌표
               int minEnemyC = -1;
               int mindist = Integer.MAX_VALUE; //궁수가 공격할 적의 최소거리 저장


                for (int i = 0; i < turn; i++) {
                    for (int j = 0; j < m; j++) {
                        if(!enemyCopy[i][j]) continue; //적이 없는 구간은 패스

                        //적이 있다면 list에 있는 궁수와의 거리를 구함
                        //거리를 구한 후 최소거리이면서 가장 왼쪽인 좌표를 새로운 list에 넣음
                        //찾자마자 바로 삭제하면 안되므로 모둔 점에 대해서 거리를 다 구한 후
                        //list에 저장되어 있는 좌표의 적을 없애고 ans++을 함
                        int dist = Math.abs(r-i) + Math.abs(c-j);

                        if(dist>d) continue; //구한 거리값이 d보다 크면 공격할 수 없으니 컨티뉴

                        if(mindist > dist){ //더 가까운 거리의 적을 찾은 경우
                            //최소거리값과 최소거리좌표 업데이트
                            mindist = dist;
                            minEnemyR = i;
                            minEnemyC = j;
                        }
                        else if(mindist==dist){ //같은 거리의 적인 경우
                            if(minEnemyC > j){ //현재 찾은 좌표가 더 왼쪽에 있는 경우
                                //최소거리좌표 업데이트
                                minEnemyR = i;
                                minEnemyC = j;
                            }
                        }
                    }
                }
                //이번 궁수가 공격할 적을 다 구함
                //그럼 deleteEnemy 리스트에 삭제할 적의 좌표를 넣음
                if(minEnemyR!=-1 && minEnemyC!=-1){ //-1로 초기화해놨었음
                    //공격할 적을 찾은 경우만 list에 추가해줌
                    deleteEnemy.add(new int[] {minEnemyR, minEnemyC});
                }

            }

            //각 궁수에 대해서 공격할 적의 좌표를 deleteEnemy에 저장했으므로
            //enmey에 그 좌표값이 true이면 ant++를 해줌
            for(int[] i : deleteEnemy){
                int a = i[0];
                int b = i[1];

                if(enemyCopy[a][b]) { //이미 지운 적은 정답으로 카운트하면 안되므로 아직 제거한 적 없는 적일 때만 카운트
                    cnt++; //제거한 적의 수 +1
                    enemyCopy[a][b]=false;
                }
            }
            //한 turn을 다 돌았으니 하나 줄여줌
            if(turn-1<0) break;
            turn--;

            //궁수의 열 좌표를 한칸씩 위로 올려야 함
            for (int[] i : archer){
                i[0]--; //궁수의 첫번째 인자가 행을 의미하므로 행을 하나 줄여줌으로써 한칸 위로 올림
            }
        }

        //이번 조합에서 제거한 적의 수를 리턴함
        return cnt;
    }

    private static boolean remainEnemy(int turn) { //turn : 현재까지 남아있는 행의 수
        for (int i = 0; i < turn; i++) {
            for (int j = 0; j < m; j++) {
                if(enemyCopy[i][j]) return true; //한명이라도 남아있으면 true
            }
        }
        return false; //더이상 적이 없다면 false
    }
}