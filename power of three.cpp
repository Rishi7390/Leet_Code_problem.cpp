#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }
        if(n<1||n%3!=0){
            return false;
        }
        return isPowerOfThree(n/3);
    }

};
int main(){
    int n;
    cin>>n;
    Solution sol;
    bool result = sol.isPowerOfThree(n);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
