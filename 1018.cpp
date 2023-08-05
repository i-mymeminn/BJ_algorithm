#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
#include <utility>
#define Max 
using namespace std;
string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];
int WBcnt(int x,int y,int Bcnt){
    int cnt = 0;
    for(int i=0; i<8; i++)
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != WB[i][j])
                cnt++;
            if (Bcnt <= cnt)   return cnt;
        }
    return cnt;
}
int BWcnt(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != BW[ i][j])
                cnt++;
        }
    return cnt;
}
int main() {
	int min=INT_MAX;
	int n, m;
    int Bcnt, Wcnt,temp;

	cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i < n - 7; i++)
		for (int j = 0; j < m - 7; j++) {
            Bcnt = BWcnt(i, j);
            if (Bcnt == 0) {
                cout << Bcnt;
                return 0;
            }
            else {
            Wcnt = WBcnt(i, j,Bcnt);
            temp = (Bcnt < Wcnt) ? Bcnt : Wcnt;
            if (min > temp)
                min = temp;
            }
		}
    cout << min;
    return 0;
}
