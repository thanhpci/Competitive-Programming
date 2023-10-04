/**4. JUMPARRAY 
Mảng nhảy - cho trước một mảng các số không âm, bắt đầu từ phần tử đầu tiên và đến cuối với số lần nhảy tối 
thiểu. Một bước nhảy không được vượt quá độ dài có trong vị trí hiện tại. 
INPUT: 
Dòng đầu nhập số n - số lượng phần tử của mảng 
Dòng sau nhập n số 
là các phần tử của mảng. 
OUTPUT: 
1 <= n <= 3000
1 <= <= n 
*/

#include <bits/stdc++.h>


using namespace std;


int back_track(vector<int> array) {
    
}


int jumparray(int n, vector<int> array) {


    int min_turn = n;

    for (int i = 0; i < n; i++) {
        back_track(array, min_turn, )
    }


    return 0;
}





int main() {
    int n;
    vector<int> array(n, 0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }


    jumparray(n, array);

    return 0;
}
