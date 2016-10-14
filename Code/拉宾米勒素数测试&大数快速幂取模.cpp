    // montgomery快速幂模算法 (n ^ p) % m, 与power算法极类似  
    unsigned __int64 montgomery(unsigned __int64 n, unsigned __int64 p, unsigned __int64 m)  
    {   
        unsigned __int64 r = n % m;  
        unsigned __int64 tmp = 1;  
        while (p > 1)  
        {  
            if ((p & 1)!=0)  
            {  
                tmp = (tmp * r) % m;  
            }  
            r = (r * r) % m;  
            p >>= 1;  
        }  
        return (r * tmp) % m;  
    }  
      
      
    //返回true:n是合数, 返回false:n是素数  
    bool R_M_Help(unsigned __int64 a, unsigned __int64 k, unsigned __int64 q, unsigned __int64 n)  
    {  
        if ( 1 != montgomery( a, q, n ) )  
        {  
            int e = 1;  
            for ( int i = 0; i < k; ++i )  
            {  
                if ( n - 1 == montgomery( a, q * e, n ) )   
                    return false;  
                 
                e <<= 1;  
            }  
              
            return true;  
        }  
      
      
        return false;  
    }  
      
      
    //拉宾-米勒测试 返回true:n是合数, 返回false:n是素数    
    bool R_M( unsigned __int64 n )   
    {  
        if( n < 2 )  
            throw 0;  
      
      
        if ( n == 2 || n == 3 )  
        {  
            return false;  
        }  
      
      
        if( (n & 1) == 0 )  
            return true;  
      
      
        // 找到k和q, n = 2^k * q + 1;  
        unsigned __int64 k = 0, q = n - 1;  
        while( 0 == ( q & 1 ) )  
        {  
            q >>= 1;  
            k++;  
        }  
      
      
        /*if n < 1,373,653, it is enough to test a = 2 and 3.   
        if n < 9,080,191, it is enough to test a = 31 and 73.   
        if n < 4,759,123,141, it is enough to test a = 2, 7, and 61.   
        if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11.*/  
               
        if( n < 1373653 )  
        {  
            if( R_M_Help(2, k, q, n )   
             || R_M_Help(3, k, q, n ) )  
                return true;  
        }  
        else if( n < 9080191 )  
        {  
            if( R_M_Help(31, k, q, n )   
             || R_M_Help(73, k, q, n ) )  
                return true;  
        }    
        else if( n < 4759123141 )  
        {  
            if( R_M_Help(2, k, q, n )   
             || R_M_Help(3, k, q, n )  
             || R_M_Help(5, k, q, n )  
             || R_M_Help(11, k, q, n ) )  
                return true;  
        }  
        else if( n < 2152302898747 )  
        {  
            if( R_M_Help(2, k, q, n )   
             || R_M_Help(3, k, q, n )  
             || R_M_Help(5, k, q, n )  
             || R_M_Help(7, k, q, n )  
             || R_M_Help(11, k, q, n ) )  
                return true;  
        }  
        else   
        {  
            if( R_M_Help(2, k, q, n )   
             || R_M_Help(3, k, q, n )  
             || R_M_Help(5, k, q, n )  
             || R_M_Help(7, k, q, n )  
             || R_M_Help(11, k, q, n )  
             || R_M_Help(31, k, q, n )  
             || R_M_Help(61, k, q, n )  
             || R_M_Help(73, k, q, n ) )  
                return true;  
        }  
      
      
        return false;  
    }  