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
    static class Shark{
        int r,c,speed,dir,size;

        public Shark(int r, int c) {
            super();
            this.r = r;
            this.c = c;
            this.speed = 0;
            this.dir = 0;
            this.size = 0;
        }

        public Shark(int r, int c, int speed, int dir, int size) {
            this.r = r;
            this.c = c;
            this.speed = speed;
            this.dir = dir;
            this.size = size;
        }

        public void init(){
            this.speed = 0;
            this.dir = 0;
            this.size = 0;
        }

        public void set(int speed, int dir, int size){
            this.speed = speed;
            this.dir = dir;
            this.size = size;
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int r,c,m,ans;
    static Shark[][] arr;
    //static List<Shark> list = new LinkedList<>();

    static int[] dr = {0,-1,1,0,0};
    static int[] dc = {0,0,0,1,-1};

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new Shark[r][c];

        for(int i=0; i<r; i++){
            for (int j = 0; j < c; j++) {
                arr[i][j] = new Shark(i,j);
            }
        }
        //초기화
        //상어를 모두 넣어줌
        while(m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken())-1; //0-indexed
            int c = Integer.parseInt(st.nextToken())-1; //1-indexed
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            arr[r][c] = new Shark(r,c,s,d,z);
        }

        //낚시왕이 먼저 상어를 잡고 나서 상어가 움직임
        for(int i=0; i<c; i++) { //열만큼 움직임
            //i열에 있는 땅에 가장 가까운 상어 잡기
            catchShark(i);

            //상어 움직임
            moveShark();
        }

        //낚시를 다 했으니 정답 출력
        System.out.println(ans);
    }
    private static void catchShark(int c) {
        //해당 c에 있는 상어 중 가장 작은 r값을 가진 상어를 삭제하면서 그 상어의 사이즈를 더해줌
        for(int i=0; i<r; i++){
            if(arr[i][c].size>0) {
                ans += arr[i][c].size; //잡은 상어 사이즈 더해줌
                //System.out.println(i+ " "+c+" "+ans);
                arr[i][c].init(); //해당 좌표는 초기화를 해줌
                break; //상어를 찾았으니 탐색 끝
            }
        }
    }
    private static boolean OOB(int x, int y) {
        return x<0||y<0||x>=r||y>=c;
    }
    private static void moveShark() {
        List<Shark> list = new ArrayList<>();
        //상어 위치에서 이동 방향으로 속력만큼 이동함
        //이동하다가 동시에 같은 칸에 간 상어들은 제거를 해줘야 함
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(arr[i][j].size>0){ //상어가 있을 때 list에 새롭게 구해진 좌표의 상어를 넣어주면서 현재 칸은 init함

                    //상어의 새로운 좌표 구하기
                    int speed = arr[i][j].speed;
                    int dir = arr[i][j].dir;
                    int size = arr[i][j].size;

                    //원래 상어가 있던 자리는 상어를 없애줌
                    arr[i][j].init();

                    int nr = i + dr[dir]*speed;
                    int nc = j + dc[dir]*speed;

                    //포문으로 직접 i, j부터 dir으로 speed만큼 가면서 방향도 바꿔주고 하기
                    if(OOB(nr,nc)){ //상어가 이동하다가 벽에 부딪힌 경우
                        // 좌표뿐만 아니라 방향도 바꿔야 함
                        //한번 방향을 바꾸지 않고 여러 번 바꿀 수도 있음

                        nr=i; nc=j; //다시 원래 좌표로 초기화
                        int ndir = dir; //일단 원래 방향으로 초기화

                        //여기를 줄여야할 것 같음
                        //불필요한 왕복을 어케줄일까..
                        int turn = 0;
                        if(ndir==1||ndir==2) turn = speed % ((r-1)*2);
                        else turn = speed % ((c-1)*2);

                        for(int num=0; num<turn; num++){
                            nr = nr + dr[ndir];
                            nc = nc + dc[ndir];

                            if(nr<0) { //dir가 위쪽인 경우
                                nr = 1;
                                ndir = 2;
                            }
                            else if(nr>=r){ //dir가 아래쪽인 경우
                                nr = r-2;
                                ndir = 1;
                            }
                            else if(nc<0){ //dir가 왼쪽인 경우
                                nc = 1;
                                ndir = 3;
                            }
                            else if(nc>=c){ //dir가 오른쪽인 경우
                                nc = c-2;
                                ndir = 4;
                            }
                        }
                        //새로운 좌표로 다 이동했으면 list에 추가해줌
                        list.add(new Shark(nr,nc,speed,ndir,size));
                    }
                    else{ //이동한 좌표가 벽에 닿지 않아서 방향을 바꾸지 않았을 때
                        //좌표만 바뀐 채로 넣어주면 됨
                        list.add(new Shark(nr,nc,speed,dir,size));
                    }

                }
            }
        }

        //list를 돌면서 모두 좌표에 넣어주면서 같은 좌표라면 큰 size 상어로 덮어쓰기
        for(Shark s : list){
            //System.out.println(s.r + " " + s.c+ " dir: "+s.dir+" speed: "+s.speed+" size:"+s.size);
            //이미 상어가 있으면 size 비교하기
            //상어가 없으면 현재 size는 0일 것이고
            //상어가 있다면 현재 size는 0 이상일 것임
            //그래서 상어가 있든 없든 현재 값보다 크면 넣어주면 됨
            if(arr[s.r][s.c].size < s.size){
                arr[s.r][s.c].set(s.speed, s.dir, s.size);
            }
        }
    }
}