#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         deque<long long int> dq; //a deque for storing negative number's index within window of size K
         vector<long long> ans;  //finally store ans in this vector
         int negative = -1;
         
         //process first window
         for(int i=0; i<K; i++) {  //for first window
             if(A[i] < 0) {  //if negative
                 dq.push_back(i);  //   push index
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {  //if any neg number in first window
             ans.push_back(A[dq.front()]);  // then front will be pointing to first negative number
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element of previous window to accomodate new element of upcoming window
             
             
             if(!dq.empty() && (i - dq.front())>=K ) {  //if front is out of window
                 dq.pop_front(); // remove it
             }
             
             //then push current element from upcoming window
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }