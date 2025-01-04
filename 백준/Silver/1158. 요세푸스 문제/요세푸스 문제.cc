#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        v[i] = i + 1; // 1부터 N까지 초기화
    }
    
    int index = 0; // 현재 인덱스
    cout << "<";
    
    while (!v.empty()) {
        index = (index + k - 1) % v.size(); // k-1 만큼 이동 후 현재 남은 크기에서 모듈러 연산
        cout << v[index]; // 제거되는 사람 출력
        v.erase(v.begin() + index); // 제거
        
        if (!v.empty()) {
            cout << ", "; // 아직 남은 사람이 있다면 쉼표 추가
        }
    }
    
    cout << ">" << endl;
    return 0;
}