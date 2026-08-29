class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int sum=0;
      int n = cardPoints.size();
      for(int i=n-1;i>=n-k;i--){
        sum+=cardPoints[i];
      }

      int maxi = sum;

      for(int i=0;i<k;i++){
        sum-=cardPoints[n-k+i];
        sum+=cardPoints[i];
        maxi = max(maxi,sum);
      }
      return maxi;

    }
};