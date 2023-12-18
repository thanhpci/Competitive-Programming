/**
 MEETING 
Hai người bạn cũ đã lâu không gặp nhau, quyết định gặp mặt trong nhà hàng của trung tâm thương mại mới. Người 
đầu tiên nói rằng có thể từ phút L1 đến phút R1. Người thứ 2 nói rằng có thể từ phút L2 đến phút R2 và sẽ bận với 
một cuộc điện thoại ở phút thứ K. Họ sẽ có thể giao tiếp trong bao nhiêu phút ?  
INPUT 
Dòng đầu ghi 5 số nguyên L1, R1, L2, R2, K.  
OUTPUT 
In ra thời gian liên lạc của 2 người bạn tính bằng phút. Nếu cả hai đều không thể giao tiếp, in ra 0.  
GIỚI HẠN 
1 ≤ L1, R1, L2, R2, K ≤ 50000  
*/

#include <iostream>

using namespace std;

int main() {

    int L1, R1, L2, R2, K;
    cin >> L1 >> R1 >> L2 >> R2 >> K;

    int start = max(L1, L2);
    int end = min(R1, R2);

    if(K >= start && K <= end) end--;

    if(start <= end) cout << end - start + 1 << endl;
    else cout << 0 << endl;

    return 0;

}
