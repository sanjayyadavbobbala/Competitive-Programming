/* N=1 --> 0 
   N=2 --> 01
   N=3 --> 0110
   N=4 --> 01101001
   N=5 --> 0110100110010110
   N=6 --> 01101001100101101001011001101001

   I: N=6, k=5
   O: 1

   I: N=6, k=21
   O: 0

*/

#include<bits/stdc++.h>
using namespace std;

int kthSymbolInNthRow(int n, int k, int val){
   if(n==1)return val;
   int totalNodesInNthRow = 1<<(n-1);
   if(k > totalNodesInNthRow/2){
        int rightVal = (val == 0)? 1 : 0;
        return kthSymbolInNthRow(n-1, k-totalNodesInNthRow/2, rightVal);       
    }
    else{
        int leftVal = (val == 0)? 0 : 1;
        return kthSymbolInNthRow(n-1, k, leftVal);
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    cout<< kthSymbolInNthRow(n, k, 0);
    return 0;
}