#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    char turn; //���� �ֱٿ� �˻��� char
    int count=0; //�׷� üĿ �ܾ� ����
    
    for(int i=0; i<n; i++){
        string word;
        cin>>word; //n���� ���ļ� �ܾ �Է¹���
        int count_wrong=0; //�׷�ܾ �ƴϰ� ���� ���ĺ� ���� 
        
        for(int j=0; j<word.length(); j++){
		//ù��° char�� �� �� ����
            if(j!=0){ //�ι�° char����
                if(turn!=word[j]){ //�ٷ� ���� �Ŷ� �ٸ��� �տ� ���Դ� �ֵ��� �� �˻��ؾ� ��
                    for(int k=0; k<j; k++){
                        if(word[j]==word[k]){ //�տ� ���Դ� �Ŷ� ���� �Ǹ� �׷�ܾ �ƴ�
                            count_wrong++;
                        }
                    }
                }
            }
            turn = word[j]; //��� ���� turn�� ���� �ֱٿ� �˻��� char�� ������Ʈ����
        }
        if(count_wrong!=0) count++; //count_wrong�� 0���� ũ�� �׷�ܾ �ƴ� 
    }
    cout<<(n-count)<<'\n';
}