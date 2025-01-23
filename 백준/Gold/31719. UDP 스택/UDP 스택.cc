#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

const int NOT_EXIST = -1;
const string YES = "YES";
const string NO = "NO";

// Stack 클래스: 첫 번째와 마지막 값을 저장하는 데이터 구조
struct Stack {
    int first, last;

// 기본 생성자
    Stack() : first(0), last(0) {}
    Stack(int f, int l) : first(f), last(l) {}
    Stack(int num) : first(num), last(num) {}
};

// UDPStacks 클래스: 최대 두 개의 Stack을 관리하는 데이터 구조
class UDPStacks {
    vector<Stack> stacks; // 스택 데이터
    vector<bool> hasStack; // 스택 존재 여부
    int size; // 활성화된 스택의 개수

public:
    UDPStacks() : stacks(2), hasStack(2, false), size(0) {}

    // 숫자를 스택에 추가하는 메서드
    bool addNumber(int num) {
        int existPossibleStack = findStackForNewNumber(num - 1);

        if (existPossibleStack != NOT_EXIST) {
            // 스택이 존재하면 해당 스택의 마지막 숫자를 업데이트
            stacks[existPossibleStack].last = num;
            return true;
        }

        if (size < 2) { // 활성 스택 개수가 2 미만일 경우
            for (int i = 0; i < 2; i++) {
                if (!hasStack[i]) { // 비어 있는 스택 슬롯에 새로운 스택 생성
                    stacks[i] = Stack(num);
                    hasStack[i] = true;
                    size++;
                    return true;
                }
            }
            throw invalid_argument("size가 충분한데 add 불가");
        }

        return false; // 스택 추가 실패
    }

    // 스택에서 num-1을 가진 스택의 인덱스 반환
    int findStackForNewNumber(int num) {
        for (int i = 0; i < 2; i++) {
            if (hasStack[i] && stacks[i].last == num) {
                return i;
            }
        }
        return NOT_EXIST;
    }

    // num을 첫 번째 숫자로 가진 스택의 인덱스 반환
    int findByFirstNumber(int num) {
        for (int i = 0; i < 2; i++) {
            if (hasStack[i] && stacks[i].first == num) {
                return i;
            }
        }
        return NOT_EXIST;
    }

    // num을 첫 번째 숫자로 가진 스택 제거
    int removeStack(int firstNum) {
        int stackWithFirstNum = findByFirstNumber(firstNum);
        if (stackWithFirstNum == NOT_EXIST) return NOT_EXIST;

        hasStack[stackWithFirstNum] = false; // 스택 제거
        size--; // 활성 스택 개수 감소
        return stacks[stackWithFirstNum].last; // 제거된 스택의 마지막 값 반환
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 테스트 케이스 개수
    cin >> T;

    while (T-- > 0) {
        int N; // 배열 크기
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int nextOut = 1; // 다음으로 나가야 할 숫자
        string answer = YES; // 기본 답변을 "YES"로 설정
        UDPStacks udpStacks; // UDPStacks 초기화

        for (int i = 0; i < N; i++) {
            int now = arr[i]; // 현재 처리할 숫자

            // 현재 숫자가 nextOut과 같으면 바로 내보냄
            if (now == nextOut) {
                nextOut++;

                // 스택에 저장된 숫자를 추가로 확인
                int result = udpStacks.removeStack(nextOut);
                if (result == NOT_EXIST) {
                    continue;
                }
                nextOut = result + 1;
                result = udpStacks.removeStack(nextOut);
                nextOut = result == NOT_EXIST ? nextOut : result + 1;
                continue;
            }

            // 현재 숫자를 스택에 저장
            bool result = udpStacks.addNumber(now);
            if (!result) { // 저장 실패 시
                answer = NO;
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
