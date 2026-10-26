#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class pereche
{
    int x,y;
public:
    pereche(int x = 0, int y = 0) : x(x),y(y){}
    void afis(){cout<<"("<<x<<" "<<y<<") "<<endl;}
///    friend int cmp(const pereche& a, const pereche& b);
    int get_x(){return x;}
    int get_y(){return y;}
};

class Test
{
    vector<int> persoane;
    vector<int> jucarii;
public:
    Test(){persoane.push_back(23); persoane.push_back(12); jucarii.push_back(70); jucarii.push_back(25); jucarii.push_back(40);}
    friend class Meniu;
    friend void f1(Test&);
    friend void f2(Test&);
    friend void f3(Test&);
};

class Meniu
{
    Test t;
public:
    void optiuni();
    void optiuni_lambda();
};

void f1(Test& t){for(auto& x : t.persoane) cout<<x<<" "; cout<<endl;}
void f2(Test& t){for(auto& x : t.jucarii) cout<<x<<" "; cout<<endl;}
void f3(Test& t){sort(t.persoane.begin(), t.persoane.end()); for(auto& x : t.persoane) cout<<x<<" "; cout<<endl;}
void Meniu::optiuni()
{
    int optiune;
    cin>>optiune;
    while(optiune)
    {
        if (optiune == 1) { f1(t);}
        else if (optiune == 2)  { f2(t);}
        else if (optiune == 3) { f3(t); }
    cin>>optiune;
    }
}

void Meniu::optiuni_lambda()
{
    int optiune;
    cin>>optiune;
    while(optiune)
    {
        if (optiune == 1) { auto f = [&](){for(auto& x : t.persoane) cout<<x<<" "; cout<<endl;}; f();}
        else if (optiune == 2)  { auto f = [this](){for(auto& x : t.jucarii) cout<<x<<" "; cout<<endl;}; f();}
        else if (optiune == 3) { auto f = [this](){sort(t.persoane.begin(), t.persoane.end()); for(auto& x : t.persoane) cout<<x<<" "; cout<<endl;}; f();}
    cin>>optiune;
    }
}

/*
int cmp(pereche& a, pereche& b)
{
    if (a.get_x() > b.get_x()) return 1;
    return 0;
}
*/

int main()
{

    vector<pereche> v = {pereche(2,5),pereche(6,7), pereche(4,3), pereche(1,0)};
    for(auto& x : v) x.afis();
    cout<<endl;
///    sort(v.begin(),v.end(),cmp);
    sort(v.begin(),v.end(),[](pereche& a, pereche& b){if (a.get_x() < b.get_x()) return 1; return 0;});

    for(auto& x : v) x.afis();

    Meniu m; m.optiuni();
    cout<<"\n cu lambda \n";
    m.optiuni_lambda();

    return 0;
}

/*
void Meniu::optiuni()
{
    int optiune;
    cin>>optiune;
    while(optiune)
    {
        if (optiune == 1) { for(auto& x : t.persoane) cout<<x<<" "; cout<<endl;}
        else if (optiune == 2)  { for(auto& x : t.jucarii) cout<<x<<" "; cout<<endl;}
        else if (optiune == 3) { sort(t.persoane.begin(), t.persoane.end()); for(auto& x : t.persoane) cout<<x<<" "; cout<<endl;}
    cin>>optiune;
    }
}
*/

/*
int main()
{
    map<int,int> m;
    m.insert(m.end(),make_pair(7,100));
    m.insert(m.end(),make_pair(1,200));
    m.insert(m.end(),make_pair(4,500));
    m.insert(m.end(),make_pair(7,300)); /// nu il insereaza, ramane perechea (7,100)

    for(auto p = m.begin(); p != m.end(); p++)
        cout<<p->first<<" "<<p->second<<endl;

    cout<<"multimap\n";
    multimap<int,int> m1;
    m1.insert(m1.end(),make_pair(7,300));
    m1.insert(m1.end(),make_pair(1,200));
    m1.insert(m1.end(),make_pair(4,500));
    m1.insert(m1.end(),make_pair(7,100));

    for(auto p = m1.begin(); p != m1.end(); p++)
        cout<<p->first<<" "<<p->second<<endl;

    return 0;
}
*/
