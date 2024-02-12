#include<bits/stdc++.h>
using namespace std;

// Finding the m raised to power of n with default value for n being 2
class Power{
    
    private:
        int base;
        int exponent;
    
    public:
        int power_(int m,int n=2){
            base = m;
            exponent = n;
            int result = 1;
            for(int i = 0;i<exponent;i++){
                result = result * base;
            }
            return result;
        }
};

int main(){
    Power P;
    int m;
    int n;
    int result;
    cout << "Enter Value of m: ";
    cin >> m;
    cout << "Enter the Value of n: ";
    cin >> n;
    result = P.power_(m,n);
    cout << "Answer: " << result << endl;
    cout << "Answer(Default):" << P.power_(m) << endl;
    return 0;
}