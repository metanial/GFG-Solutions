//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public: 
    void reverse(vector<int>& arr, int start, int end) {
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        
    }
    
    void nextPermutation(vector<int>& arr) {
        int length = arr.size();
        int pivot = -1;
        for(int i = length - 1; i > 0; i--) {
            if(arr[i - 1] < arr[i]) {
                pivot = i - 1;
                break;
            }
        }
        
        if(pivot == -1) {
            reverse(arr, 0, length - 1);
            return;
        } 
        
        for(int i = length - 1; i > pivot; i--) {
            if(arr[i] > arr[pivot]) {
                swap(arr[i], arr[pivot]);
                break;
            }
        } 
        
        reverse(arr, pivot + 1, length - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends