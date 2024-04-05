#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossible(vector<int>cooksRanks, int nP, int mid){
    int currPrata = 0;
    for(int i=0; i<cooksRanks.size(); i++){
        int R = cooksRanks[i];
        int j = 1;
        int timeTaken = 0;

        while(true){
            if(timeTaken + j*R <= mid){
                currPrata++;
                timeTaken += j*R;
                j++;
            }
            else{
                break;
            }
        }
        if(currPrata >= nP){
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(vector<int>cooksRanks, int nP){
    int start = 0;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int end = highestRank * (nP * (nP + 1) / 2);
    int ans = -1;

    while (start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(cooksRanks, nP, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int nP, nC;
        cin >> nP >> nC;
        vector<int>cooksRanks;
        while(nC--){
            int R;
            cin >> R;
            cooksRanks.push_back(R);
        }
        cout << minTimeToCompleteOrder(cooksRanks, nP) << endl;
    }
    return 0;
}