class Solution {
    public int solution(String s) {
        String answer = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)>='0' && s.charAt(i)<='9') { //숫자인 경우 
                answer += s.charAt(i);
            }
            else { // 영어인 경우 
                  //s[i]부터 시작해서 해당하는 영어단어를 찾아야함
                if(s.charAt(i)=='z') {
                    answer += '0';
                    i+=3;
                }
                else if(s.charAt(i)=='o') {
                    answer += '1';
                    i+=2;
                }
                else if(s.charAt(i)=='t') {
                    if(s.charAt(i+1)=='w') {
                        answer += '2';
                        i+=2;
                    }
                    else if(s.charAt(i+1)=='h') {
                        answer += '3';
                        i+=4;
                    }
                }
                else if(s.charAt(i)=='f') {
                    if(s.charAt(i+1)=='o') {
                        answer += '4';
                        i+=3;
                    }
                    else if(s.charAt(i+1)=='i') {
                        answer+='5';
                        i+=3;
                    }
                }
                else if(s.charAt(i)=='s') {
                    if(s.charAt(i+1)=='i'){
                        answer+='6';
                        i+=2;
                    }
                    else if(s.charAt(i+1)=='e'){
                        answer+='7';
                        i+=4;
                    }
                }
                else if(s.charAt(i)=='e'){
                    answer+='8';
                    i+=4;
                }
                else if(s.charAt(i)=='n'){
                    answer+='9';
                    i+=3;
                }
            }
        }
        
        return Integer.parseInt(answer);
    }
}