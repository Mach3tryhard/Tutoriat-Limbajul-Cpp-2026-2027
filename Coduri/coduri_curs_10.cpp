#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(3);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.push_back(45);
    cout<<v.size()<<" "<<v.capacity()<<endl;
   v.push_back(45);
    cout<<v.size()<<" "<<v.capacity()<<endl;
       v.push_back(45);
    cout<<v.size()<<" "<<v.capacity()<<endl;
       v.push_back(45);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v[0] = 78;
    v[1] = 90;
    v[2] = 1234;
    for(int i = 0; i<v.size(); i++) cout<<v[i]<<" ";
    for(auto& p : v) cout<<p<<" ";
    for(auto p = v.begin(); p!= v.end(); p++)
        cout<<*p<<" "; cout<<endl;
    for(vector<int>::iterator p = v.begin(); p!= v.end(); p++)
        cout<<*p<<" ";
///    v.clear();
        cout<<v.size()<<" ";

return 0;
}

/*
///template<class T>
///class Test;

///template<class T>
///istream& operator>>(istream& in, Test<T>& ob){cout<<"Citire din operator: ";return in>>ob.x;}

template<class T>
class Test
{
    T x;
public:
    void citire(){cout<<"x = "; cin>>x;}
///    void afisare(){cout<<x<<endl;}
    void afisare();
///    friend istream& operator>>(istream& in, Test& ob){cout<<"Citire din operator: ";return in>>ob.x;}
///    friend istream& operator>>(istream& in, Test<T>& ob){cout<<"Citire din operator: ";return in>>ob.x;}
///    friend istream& operator>> <>(istream& in, Test<T>& ob);
    template<class T1>
    friend istream& operator>> (istream& in, Test<T1>& ob);
};

template<class T>
void Test<T>::afisare(){cout<<x<<endl;}

template<class T>
istream& operator>>(istream& in, Test<T>& ob){cout<<"Citire din operator: ";return in>>ob.x;}


int main()
{
    Test<int> A;
    Test<float> B;
    ///A.citire();
    cin>>A;
    A.afisare();

    return 0;
}
*/
