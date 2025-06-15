#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    
    vector<int> stock(14, 0);
    for(int i=0; i<14; i++) cin>>stock[i];
    
    // 준현이부터 계산
    int joonCash = n; // 준현이의 남은 현금 
    int joonStockCnt = 0; // 준현이의 보유 주식 개수
    for(int i=0; i<13; i++) {
        int tmpCnt = joonCash/stock[i];
        joonCash -= stock[i]*tmpCnt;
        joonStockCnt += tmpCnt;
    }
    // 14일날일 때 자산구하기
    int joonTotal = joonCash + stock[13] * joonStockCnt;
    // cout<<joonTotal<<'\n';
    //cout<<joonStockCnt;
    
    int jeongCash = n;
    int jeongStockCnt = 0;
    int high=0, low=0;
    for(int i=0; i<13; i++) {
        // 오늘 결과 기록하기
        if(i!=0) {
            if(stock[i] > stock[i-1]) {
                high++;
                low=0;
            }
            else if(stock[i] < stock[i-1]) {
                low++;
                high=0;
            }
        }
        
        // 3일 연속 전일 대비 상승했다면
        if(high>=3) {
            // cout<<"*"<<i+1<<"\n";
            // 전량 매도
            jeongCash += stock[i]*jeongStockCnt;
            jeongStockCnt = 0;
            
        }
        
        // 3일 연속 전일 대비 하락했다면
        else if(low>=3) {
            // cout<<"**"<<i+1<<"\n";
            // 전량 매수
            int tmpCnt = jeongCash/stock[i];
            jeongCash -= stock[i] * tmpCnt;
            jeongStockCnt += tmpCnt;
        }
        
    }
    
    int jeongTotal = jeongCash+ stock[13]*jeongStockCnt;
    // cout<<jeongTotal<<'\n';
    
    if(joonTotal > jeongTotal) cout<<"BNP";
    else if(joonTotal == jeongTotal) cout<<"SAMESAME";
    else cout<<"TIMING";
    
    return 0;
}