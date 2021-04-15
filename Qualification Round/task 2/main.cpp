#include <iostream>

using namespace std;
int main() {
    int tests;
    cin>>tests;
    for(int i=0; i<tests; i++){
        int x,y;
        cin>>x;
        cin>>y;
        string mural;
        cin>>mural;
        int sum=0;
        int sign=0;
        for(int j=0; j<mural.length(); j++){
            if(mural[j]=='?') continue;
            else if(mural[j]=='C') {
                sign = 1;
                break;
            }
            else {
                sign=2;
                break;
            }
        }
        if(sign==0){
            cout << "Case #" << i + 1 << ": 0\n";
            continue;
        }
        for(int j=0; j<mural.length(); j++){
            if(mural[j]=='?') {
                if (sign == 1) mural[j] = 'C';
                else mural[j] = 'J';
            }
            else if(mural[j]=='J') sign=2;
            else sign=1;
        }
        for(int j=1; j<mural.length(); j++){
            if(mural[j]=='C' && mural[j-1]=='J') sum=sum+y;
            if(mural[j]=='J' && mural[j-1]=='C') sum=sum+x;
        }
        cout<< "Case #" << i + 1 << ": "<<sum<<"\n";
    }
    return 0;
}
