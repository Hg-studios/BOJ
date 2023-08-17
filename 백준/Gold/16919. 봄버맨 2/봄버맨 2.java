import java.io.*;
import java.util.*;

public class Main {
    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static char[][][] ans;
    static int R, C;

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    static Queue<Point> q;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        //입력받기
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        // 0 : 초기
        // 1 : 한 번 터진후 결과
        // 2 : 두 번 터진후 결과
        ans = new char[R][C][4];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                for (int k = 1; k < 4; k++) {
                    ans[i][j][k] = 'O'; //초기화
                }
            }
        }

        for (int i = 0; i < R; i++) { // 나머지 줄
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            for (int j = 0; j < C; j++) {
                ans[i][j][0] = s.charAt(j);
            }
        }

        for (int c = 0; c < 2; c++) {
            q = new LinkedList<>();
            for (int i = 0; i < ans.length; i++) {
                for (int j = 0; j < ans[i].length; j++) {
                    if (ans[i][j][c] == 'O') {
                        q.offer(new Point(i, j));
                    }
                }
            }
            bfs(c + 1);
        }

        //출력
        if (N == 1) {
            print(ans, 0);
        } else if (N % 2 == 0) {
            print(ans, 3);
        } else if (N % 4 == 3) {
            print(ans, 1);
        } else if (N % 4 == 1) {
            print(ans, 2);
        }

    }

    private static void bfs(int c) {
        while (!q.isEmpty()) {
            Point p = q.poll();
            ans[p.x][p.y][c] = '.';
            for (int d = 0; d < dx.length; d++) {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && ans[nx][ny][c] == 'O') {
                    ans[nx][ny][c] = '.';
                }
            }
        }

    }

    private static void print(char[][][] answer, int idx) {
        for (int i = 0; i < answer.length; i++) {
            for (int j = 0; j < answer[i].length; j++) {
                System.out.print(answer[i][j][idx]);
            }
            System.out.println();
        }
    }
}