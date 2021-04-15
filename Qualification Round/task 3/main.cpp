#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int tests;
    cin>>tests;
    for(int i=0; i<tests; i++){
        int length;
        cin>>length;
        int check;
        cin>>check;
        int tab[length];
        if(check==length-1) {
            cout<<"Case #"<<i+1<<": ";
            for(int j=0; j<length; j++) cout<<j+1<<" ";
            cout<<'\n';
        }
        else{
            int iteration=0;
            int max=1;
            for(int j=0; j<length; j++)
                max=max*(j+1);
            for(int j=0; j<length; j++)
                tab[j]=j+1;
            for(int a=0; a<10000; a++) {
                next_permutation(tab,tab+length);
                int tab_temp[length];
                for(int j=0; j<length; j++) tab_temp[j]=tab[j];
                if(iteration==max){
                    cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<'\n';
                    break;
                }
                iteration++;
                int index=0;
                int sum=0;
                for(int j=0; j<length-1; j++){
                    for(int x=j; x<length; x++){
                        if(tab_temp[x]==j+1){
                            index=x;
                            break;
                        }
                    }
                    sum=sum+index-j+1;
                    for (int n = j; n < (index-j+1)/2+j; n++) {
                        swap(tab_temp[n],tab_temp[index-n+j]);
                    }
                    index=0;
                }
                if(sum==check) {
                    cout << "Case #" << i + 1 << ": ";
                    for (int j = 0; j < length; j++) cout << tab[j] << " ";
                    cout << '\n';
                    break;
                }
            }
        }
    }
}
