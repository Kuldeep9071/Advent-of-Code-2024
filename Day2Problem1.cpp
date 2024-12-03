#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool Inc(vector<int> &arr){
	int n=arr.size();
	for(int i=0;i<n-1;i++) if((arr[i+1]<=arr[i]) || (arr[i+1]>arr[i]+3)) return 0;
	return true;
}

bool Dec(vector<int> &arr){
	int n=arr.size();
	for(int i=0;i<n-1;i++) if((arr[i+1]>=arr[i]) || (arr[i+1]<arr[i]-3)) return 0;
	return true;
}

int main() {
    vector<vector<int>> data;
    string line;
    
    for (int i = 0; i < 1000; ++i) {
        getline(cin, line);
        stringstream ss(line);
        int number;
        vector<int> row;
        
        while (ss >> number) {
            row.push_back(number);
        }
        data.push_back(row);
    }
    int ans=0;
    for(auto row : data) if(Inc(row) || Dec(row)) ans++;
    cout<<ans<<"\n";
    return 0;
}
