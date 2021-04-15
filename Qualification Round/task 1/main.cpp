#include <iostream>
using namespace std;
int main() {
    int tests;
    cin>>tests;
    for(int i=0; i<tests; i++){
        int length;
        cin>>length;
        int tab[length];
        for(int j=0; j<length; j++)
            cin>>tab[j];
        if(length==0) cout<<"Case #"<<i+1<<": 0"<<endl;
        else{
            int index=0;
            int sum=0;
            for(int j=0; j<length-1; j++){
                for(int x=j; x<length; x++){
                    if(tab[x]==j+1){
                        index=x;
                        break;
                    }
                }
                sum=sum+index-j+1;
                for (int n = j; n < (index-j+1)/2+j; n++) {
                    swap(tab[n],tab[index-n+j]);
                }
                index=0;
            }
            cout<<"Case #"<<i+1<<": "<<sum<<endl;
        }
    }
    return 0;
}
