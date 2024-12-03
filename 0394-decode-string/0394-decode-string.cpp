class Solution {
public:
    string decodeString(string s) {
        stack<string> stackS;
        stack<int> stackI;
        string temp = "", ans = "";
        stackS.push("");
        int i , cnt = 0 , n = s.size() , c = 0;
        for(i = 0 ; i < n ; ++i) {
            cout << i << endl;
            if(isdigit(s[i])) {
                cout << i <<" 1 " << s[i] << endl;
                while( i < n && isdigit(s[i])){
                c = (c*10) + (s[i] - '0');
                ++i;
                }
                i--;
            } else if(s[i] == '[') {
                cout << i << " 2 " << s[i] << " "<< c << endl;
                stackI.push(c);
                c = 0;
                stackS.push(temp);
                temp = "";
            } else if(isalpha(s[i])) {
                temp += s[i];
            } else {
                cout << i <<" 4 last string " << temp << endl;
                cnt = stackI.top();
                cout << "4 I top " << cnt << endl;
                stackI.pop();
                ans = stackS.top();
                cout << "4 S top " << ans << endl;
                stackS.pop();
                for(int j = 1 ; j <= cnt ; ++j) {
                    ans += temp;
                }
                c = 0;
                cout << "4 S ans " << ans << endl;
                temp = ans;
            }
        }
        return temp;
    }
};