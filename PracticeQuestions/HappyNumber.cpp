/*
Question Link: https://leetcode.com/problems/happy-number/description/

19 = 1^2 + 9^2 = 82
82 = 8^2 + 2^2 = 68
68 = 6^2 + 8^2 = 100
100 = 1^2 + 0^2 + 0^2 = 1

81 = 8^2 + 1^2 = 65
65 = 6^2 + 5^2 = 61
61 = 6^2 + 1^2 = 37
37 = 3^2 + 7^2 = 58
58 = 5^2 + 8^2 = 89
89 = 8^2 + 9^2 = 145
145 = 1^2 + 4^2 + 4^2 = 40
40 = 4^2 + 0^2 = 16
16 =1^2 + 6^2 = 37 // Loop Starts here
37 = 3^2 + 7^2 = 58
58 = 5^2 + 8^2 = 89
89 = 8^2 + 9^2 = 145

Approach1: Recursion and Map
We recursively find the sqrd_sum of number, n.
After that we map the n to true if it's already been came as sum.

if sqrd_sum equals 1, We come out of recursion with true.

if value repeats in the map, we come out of recursion with false;

Approach2: Recursion and Behaviour of Single Digit Number
We can notice that if sum_sqrd had exactly one '1' in it and divisble by 100 or It is 1, then only it would be Happy Number.
When it is divisible by 10 but not having exactly 1 then it will not be Happy Number.
If it is not divisble by 10 then it may or may not be happy number.
*/

class Solution  1{
private:
    int sum_sqrd(int n){
        int sqrd_sum = 0;
        int dig;
        while(n>0){
            dig = n%10;
            sqrd_sum += pow(dig,2);
            n /= 10;
        }
        return sqrd_sum;
    }

    bool Happy(int n, unordered_map<int,bool>& m){
        if(n == 1){
            return true;
        }
        if(m.count(n) != 0){
            return false;
        }else{
            m[n] = true;
        }
        bool ans = Happy(sum_sqrd(n),m);
        return ans;
    }
public:
    bool isHappy(int n) {
        unordered_map<int,bool> m1;
        return Happy(n,m1);
    }
};

class Solution2 {
private:
    pair<int,int> sum_sqrd(int n){
        pair<int,int> ans;
        int sqrd_sum = 0;
        int dig;
        int dig_count = 0;
        while(n>0){
            dig = n%10;
            sqrd_sum += pow(dig,2);
            n /= 10;
            dig_count++;
        }
        ans.first = sqrd_sum;
        ans.second = dig_count;
        return ans;
    }
public:
    bool isHappy(int n) {
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n==7){
            return true;
        }
        pair<int,int> p1 = sum_sqrd(n);
        int dig_count = p1.second;
        int tenth = pow(10,dig_count-1);
        int rem = n%tenth;
        if( rem == 0 && n!=1 && n <10 && n > 0){
            return false;
        }
        return isHappy(p1.first);
    }
};

class Solution3 {
private:
    int sum_sqrd(int n){
        int sqrd_sum = 0;
        int dig;
        while(n>0){
            dig = n%10;
            sqrd_sum += pow(dig,2);
            n /= 10;
        }
        return sqrd_sum;
    }
    pair<int,bool> divisibility(int n){
        pair<int,bool> ans;
        int dig_count = 0;
        int temp = n;
        while(temp>0){
            dig_count++;
            temp = temp/10;
        }
        int ten = pow(10,dig_count-1);
        ans.first = ten;
        if(ten == 1){
            ans.second = true;
        }else{
            ans.second = (n%ten==0);
        }
        return ans;
    }
    bool happy(int n, map<int,bool>& m){
        if(n<10){
            return m[n];
        }
        pair<int,bool> collect = divisibility(n);
        if(collect.second){
            return m[n/collect.first];
        }
        return happy(sum_sqrd(n),m);
    }
public:
    bool isHappy(int n) {
        map<int,bool> refer;
        refer[0] = false;
        refer[1] = true;
        refer[2] = false;
        refer[3] = false;
        refer[4] = false;
        refer[5] = false;
        refer[6] = false;
        refer[7] = true;
        refer[8] = false;
        refer[9] = false;
        return happy(n,refer);
    }
};