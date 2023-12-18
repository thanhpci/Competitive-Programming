/**STRANGE
Cho chuỗi s gồm các ký tự chữ cái (viết thường và viết hoa), chữ số và dấu câu, (số thứ tự từ 33 đến 126 trong bảng
mã ASCII). Chuỗi con, bao gồm các ký tự liên tiếp trong chuỗi đã cho được gọi là đặc biệt nếu không có 2 ký tự
giống nhau trong đó. Viết một chương trình đọc chuỗi s đã cho và tìm chuỗi con đặc biệt dài nhất.
INPUT
Chuỗi s.
OUTPUT
Dòng đầu tiên in ra: độ dài chuỗi con đặc biệt dài nhất, và vị trí chuỗi con đặc biệt trong chuỗi đã cho (được tính từ
0). Dòng 2 in ra chuỗi con đặc biệt dài nhất. Trường hợp có nhiều hơn một chuỗi con đặc biệt dài nhất, in ra chuỗi
con ngoài cùng bên phải trong chuỗi đã cho.
GIỚI HẠN
Độ dài của chuỗi đã cho là từ 1 đến 20.000.000 ký tự
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> lastPos(128, -1);
    int maxLength = 0;
    int maxStartPos = 0;
    int currentStartPos = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (lastPos[c] >= currentStartPos) {
            currentStartPos = lastPos[c] + 1;
        }

        int currentLength = i - currentStartPos + 1;
        if (currentLength >= maxLength) {
            maxLength = currentLength;
            maxStartPos = currentStartPos;
        }

        lastPos[c] = i;
    }

    cout << maxLength << " " << maxStartPos << endl;
    cout << s.substr(maxStartPos, maxLength) << endl;

    return 0;
}
