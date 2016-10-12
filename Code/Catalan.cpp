    #include <iostream>  
    using namespace std;  
      
    int bit_cnt(int n)  
    {  
        int result = 0;  
        for (; n; n &= n-1, ++result);  
        return result;  
    }  
      
    int main(void)  
    {  
        int F[6], B[6];  
        int i,j,k,state,ok,ans = 0;  
        for (state = 0; state < (1 << 12); ++state)  
        {  
            if (bit_cnt(state) == 6)  
            {  
                i = j = 0;  
                for (int k = 0; k < 12; ++k)  
                {  
                    if(state&(1<<k))  
                        F[i++] = k;  
                    else  
                        B[j++] = k;  
                }  
                ok = 1;  
                for (k = 0; k < 6; ++k)  
                {  
                    if (B[k] < F[k])  
                    {  
                        ok = 0;  
                        break;  
                    }  
                }  
                ans += ok;  
            }  
        }  
        cout << ans << endl;  
        return 0;  
    }  
