class Solution {
public:
    long long int bitwiseComplement(long long int N) {
        
        if(N==0)
            return 1;
        else if(N==1)
            return 0;
        
        long long int bin = 0;
        long long int full_num =0;
        long long int c = 0;
        while(N>0)
        {
            long long int rem = N%2;
            bin = bin + rem * pow(10,c);
            full_num += 1*pow(10,c);
            c++;
            N/=2;
        }
        
        long long int required = full_num - bin;
        
        long long int result =0;
        c=0;
        while(required)
        {
            long long int rem = required%10;
            result += rem*pow(2,c);
            c++;
            required/=10;
        }
        
        return result;
        
        
    }
};