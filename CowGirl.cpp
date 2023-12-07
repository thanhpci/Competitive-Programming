/**
Cô gái chăn bò
    Trên một thảo nguyên nhỏ bé có 1 gia đình gồm 3 anh em: 2 người anh trai là Nvutri và Andorea còn người em gái là Lola.
    Cuộc sống gia đình khá giả nhưng gia đình có truyền thống chăn nuôi và muốn để các con tự lập nên cha mẹ 3 người quyết định để các con hàng ngày sẽ đi chăn một số bò nào đó (tùy ý 3 người con).

    Thảo nguyên là 1 cánh đồng chia làm M x N ô vuông, mỗi con bò chỉ đứng trong 1 ô và mỗi ô chỉ chứa 1 con bò. Chỉ có 1 quy tắc duy nhất là không bao giờ được để 4 con bò tạo thành 1 hình vuông 2 x 2 hoặc để trống 1 khu đất 2 x 2.

    Hai người anh mãi chơi nên đã hỏi lộ kem đề Lola chăn bò 1 mình. Lola muốn biết tất cả có bao nhiêu cách xếp bò thoả mãn quy tắc trên để đề phòng mọi trường hợp. Vì con số này rất lớn nên nhờ giúp Lola tính toán con số này.

Input
    Dòng đầu gồm 1 số T duy nhất là số test (T ≤ 111).
    T dòng tiếp theo gồm 2 số M, N cho biết kích thước của thảo nguyên (M x N ≤ 30).
Output
    Gồm T dòng, mỗi dòng ứng với 1 test là số cách xếp bò của test đó.


*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(bitset<32> x, bitset<32> y, int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        if (x[i] && x[i + 1] && y[i] && y[i + 1])
        {
            return false;
        }

        if (!(x[i] || x[i + 1] || y[i] || y[i + 1]))
        {
            return false;
        }
    }

    return true;
}

int cowgirl(int const m, int const n)
{
    int max_size = int(pow(2, n));
    vector<vector<int>> results(m, vector<int>(max_size, 0));
    for (int i = 0; i < max_size; i++)
    {
        results[0][i] = 1;
    }

    vector<bitset<32>> binary_arr(max_size, 0);

    for (int i = 0; i <= max_size - 1; i++)
    {
        bitset<32> binary(i);
        binary_arr[i] = binary;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < max_size; j++)
        {

            for (int k = 0; k < max_size; k++)
            {
                if (check(binary_arr[j], binary_arr[k], n))
                {
                    results[i][j] += results[i - 1][k];
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < max_size; i++)
    {
        result += results[m - 1][i];
    }

    return result;
}

int main()
{

    int t, m, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {

        cin >> m >> n;
        if (m < n)
            swap(m, n);
        cout << cowgirl(m, n) << endl;
    }

    return 0;
}