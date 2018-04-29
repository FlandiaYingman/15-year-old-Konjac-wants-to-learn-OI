    //P1980 计数问题
    #include<iostream>
    #include<string>

    using namespace std;

    int appear_times(int, int);

    int main() {
        int n, x;
        cin >> n >> x;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += appear_times(i, x);
        }
        cout << ans;
        return 0;
    }

    int appear_times(int i, int j) {
        string str = to_string(i);
        string strj = to_string(j);

        int flag;
        int sum = 0;
        while ((flag = str.find(strj)) != -1) {
            str = str.substr(flag + strj.length(), str.length() - strj.length());
            sum++;
        }

        return sum;
    }

