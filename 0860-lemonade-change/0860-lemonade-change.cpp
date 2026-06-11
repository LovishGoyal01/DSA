class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0,remain=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five+=5;
                remain=0;
            }else if(bills[i]==10){
                ten+=10;
                remain=5;
                if(five<remain) return false;
                five-=remain;
            }else{
                twenty+=20;
                remain=15;
                if(ten>=10){
                    ten-=10;
                    remain-=10;
                }
                if(five>=remain){
                  five-=remain;
                }else return false;
            }
        }
        return true;
    }
};