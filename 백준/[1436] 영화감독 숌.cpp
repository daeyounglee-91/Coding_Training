#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
   
   int N,num = 0;
   int count = 0;

   scanf("%d",&N);

   while(++num){
       int temp = num;
       bool flag = false;
       while(temp){
           if(temp % 1000 == 666){
               flag = true;
               break;
           }
           temp /= 10;
       }
        if(flag){
            count++;
            if(count == N){
                break;
            }
        }
   }

   printf("%d",num);

   return 0;
}