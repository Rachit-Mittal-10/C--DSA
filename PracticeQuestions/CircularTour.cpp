// Question Link: https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

struct petrolPump
{
    int petrol;
    int distance;
} typedef petrolPump;

class Approach1
{
/*
Brute Force Approach
TC: O(N^2)
SC: O(N)
*/
    int tour(petrolPump p[], int n)
    {
        // Your code here
        int balance;
        petrolPump temp;
        petrolPump temp2;
        int i;
        int balance_arr[n];
        for (i = 0; i < n; i++)
        {
            temp = p[i];
            balance = 0;
            if (temp.distance > temp.petrol)
            {
                balance = balance + temp.petrol - temp.distance;
                balance_arr[i] = balance;
                continue;
            }
            int j;
            for (j = i; j < n; j++)
            {
                temp2 = p[j];
                balance = balance + temp2.petrol - temp2.distance;
                if (balance < 0)
                {
                    balance_arr[i] = balance;
                    break;
                }
            }
            if (j == n)
            {
                for (j = 0; j < i; j++)
                {
                    temp2 = p[j];
                    balance = balance + temp2.petrol - temp2.distance;
                    if (balance < 0)
                    {
                        balance_arr[i] = balance;
                        break;
                    }
                }
            }

            balance_arr[i] = balance;
        }
        for (i = 0; i < n; i++)
        {
            if (balance_arr[i] > 0)
            {
                return i;
            }
        }
        return -1;
    }
};

class Approach2{
    // Video 61 Love Babbar C++ Placement Series
    // TC: O(N)
    //SC: O(1)
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int balance = 0, deficit = 0, start = 0;
       for(int i=0;i<n;i++){
           balance += p[i].petrol - p[i].distance;
           if(balance < 0){
               deficit += balance;
               balance = 0;
               start = i + 1;
           }
       }
       
       if(deficit + balance >= 0){
           return start;
       }else{
           return -1;
       }
    }
};