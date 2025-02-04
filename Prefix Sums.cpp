#include<iostream>
#include<vector>

using namespace std;

int main(){
vector<int>arr={1,2,3,4};
int n=arr.size();
vector<int>ans(n);

vector<int>suffix(n,1);
vector<int>prefix(n,1);


//////////////////////////////////////////////////////////
for(int i=1;i<n;i++){
prefix[i]=prefix[i-1]*arr[i-1];
}
for(int i=n-2;i>=0;i--){
	suffix[i]=suffix[1+i]*arr[i+1];
}
for(int i=0;i<n;i++){
	ans[i]=prefix[i]*suffix[i];
	
}

///////////////////////////////////////////////////////////////////

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";  
    }



return 0;
}