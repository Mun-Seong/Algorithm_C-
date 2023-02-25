#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n,k;
    
    cin >> n >> k;
    
    int pascal_arr[n+1][k+1];  // 파스칼 삼각형 수가 저장되는 배열
    
    // 삼각형에서 맨 처음 값은 1로 고정임
    for (int i = 0; i <= n; i++) pascal_arr[i][0] = 1;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if (j > k) continue; // k 이상으로는 값을 구할 필요가 없기 때문에 continue 로 넘겨줌
            pascal_arr[i][j] = pascal_arr[i-1][j-1] % 10000019;
            
            // 행 마지막 값인 경우에는 왼쪽 위에 있는 값만 더해주고
            // 그게 아닌 경우에는 왼쪽 위, 오른쪽 위에 있는 값을 더해준다.
            // 해당 조건이 없는 경우 빈 배열에 있는 쓰레기 값이랑 더해져서 데이터가 정상적으로 나오지 않음
            if (i >= j)
				pascal_arr[i][j] = (pascal_arr[i][j] + pascal_arr[i-1][j]) % 10000019;
        }
    }
    
    cout << pascal_arr[n][k];
}