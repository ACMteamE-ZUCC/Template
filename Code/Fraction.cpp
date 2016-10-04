//
// Created by yaot on 16-10-4.
//
#include <iostream>
#include <string>
using namespace std;
template <class T>
class fenshu {
private:
    T numerator;
    T denomenator;
public:
    ONLY SUPPORT INT put'//' to turn off this WARNING
    T gcd(T m,T n){
        T t;
        while(m%n!=0)
        {
            t=m%n;
            m=n;
            n=t;
        }
        return n;
    }
    fenshu(T m, T n){
        T mod=gcd(m,n);
        numerator=m/mod;
        denomenator=n/mod;
    }
    fenshu(): numerator(0),denomenator(1){}
    T geta()const{ return numerator;}
    T getb() const {return denomenator;}
};


template <class T>
ostream& operator<< (ostream &out, T &v)
{
    out << v.geta() << '/' << v.getb() << endl;
    return out;
}

template <class T>
T operator*(T &v1, T &v2)
{
    T a(v1.geta()*v2.geta(), v1.getb()*v2.getb());
    return a;
}

template <class T>
T operator/(T &v1, T &v2)
{
    T a(v1.geta()*v2.getb(), v1.getb()*v2.geta());
    return a;
}

template <class T>
T operator+(T &v1, T &v2)
{
    T a(v1.geta()*v2.getb()+ v1.getb()*v2.geta(), v1.getb() * v2.getb());
    return a;
}

template <class T>
T operator-(T &v1, T &v2)
{
    T a(v1.geta()*v2.getb()- v1.getb()*v2.geta(), v1.getb() * v2.getb());
    return a;
}
