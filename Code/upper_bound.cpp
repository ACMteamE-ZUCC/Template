int BSearch(int x, int y, int v) //二分求上界  
{  
    while(x <= y)  
    {  
        int mid = x+(y-x)/2;  
        if(S[mid] <= v) x = mid+1;  
        else y = mid-1;  
    }  
    return x;  
}  