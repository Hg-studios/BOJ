#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1005];
vector<pair<int,int>> cnt; //{빈도수, arr에서의 idx}

bool cmp(pair<int,int> a, pair<int,int>b){
    if(a.first!=b.first) return a.first> b.first;

    return a.second<b.second;
}

int main(){
    int n, c; cin>>n>>c;

    int tmp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //arr를 쭉 돌면서 벡터cnt에 {나온횟수, arr인덱스}로 저장
    for(int i=0; i<n; i++){
        if(!cnt.size()) cnt.push_back({1, i});
        else{
            //벡터 안에 이미 arr[i]원소가 저장된 경우
            bool flag=0;
            for(int j=0; j<cnt.size();j++){
                pair<int,int> cur = cnt[j];
                int idx = cur.second;

                if(arr[idx]==arr[i]){
                    cnt[j].first += 1;
                    flag = 1; //벡터에서 같은 원소 찾음
                    break;
                }
            }
            //벡터 안에 arr[i]가 저장되어있지 않은 경우
            //벡터에 해당 값을 추가해줘야함 
            if(!flag){
                cnt.push_back({1, i});
            }
        }
    }

    //위의 for문을 다 돌고나면 각 숫자가 몇 번 나왔는지 벡터에 저장됨
    //우선, 벡터의 첫번째 값인 빈도수가 큰 친구들을 앞으로 정렬하고 
    //빈도수가 같다면 나온 순서대로 정렬함
    sort(cnt.begin(), cnt.end(), cmp);

    for(auto i : cnt){
        int freq = i.first;
        int idx = i.second;

        while(freq--){
            cout<<arr[idx]<<" ";
        }
    }
}