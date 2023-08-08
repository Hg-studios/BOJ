import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
    static int[][] question;
    static boolean[] visited;
    static int n, ans=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        //입력받기
        n = Integer.parseInt(st.nextToken());
        question = new int[n][3];
        visited = new boolean[10];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            question[i][0] = Integer.parseInt(st.nextToken());
            question[i][1] = Integer.parseInt(st.nextToken());
            question[i][2] = Integer.parseInt(st.nextToken());
        }

        //중복없는 순열을 만들어내고 조건을 모두 만족하는지 확인하는 함수 호출
        recursive(0,0); //중복없는 순열, 그냥 for문 돌려도 됨

        System.out.println(ans);
    }

    private static void recursive(int cnt, int num) {
        if(cnt==3){
            //System.out.println(num);
            String number = Integer.toString(num); //인덱스비교를 위해 스트링으로 변환
           //세자리를 모두 정했으므로 가능성이 있는 수인지 조건 체크함
            for(int i=0; i<n; i++){
                String n = Integer.toString(question[i][0]); //인덱스비교를 위해 스트링으로 변환
                int s = question[i][1];
                int b = question[i][2];

                int cntS=0, cntB=0;
                //num과 n이 몇스트라이크 몇볼인지 확인
                for(int x=0; x<3; x++){
                    for(int y=0; y<3; y++){
                        if(x==y){
                            if(number.charAt(x)==n.charAt(y)) cntS++;
                        }
                        else{
                            if(number.charAt(x)==n.charAt(y)) cntB++;
                        }
                    }
                }
                if(cntS!=s || cntB!=b) return;
            }
            ans++; //n번의 질문을 모두 통과한 수라면 카운트함
            return;
        }
        for(int i=1; i<=9; i++){
            if(!visited[i]){
                visited[i]=true;
                num = num*10+i;
                recursive(cnt+1, num);
                num = (num-i)/10;
                visited[i]=false;
            }

        }
    }
}