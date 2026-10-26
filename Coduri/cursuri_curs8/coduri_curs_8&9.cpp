#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*** template ****/

class Produs
{
    int pret;
public:
    Produs(int pret = 0):pret(pret){}
    friend ostream& operator<<(ostream& out, Produs& p){return out<<p.pret<<" ";}
    friend istream& operator>>(istream& in, Produs& p){return in>>p.pret;}
};

/// void afis(int v[10], int n) { cout<<"nontemplate"; for(int i = 0; i <n; i++) cout<<v[i]<<" "; cout<<endl;} /// non-template
/// void afis(double v[10], int n) { for(int i = 0; i <n; i++) cout<<v[i]<<" "; cout<<endl;} /// non-template

template<class T>
void afis(T v[10], int n) { for(int i = 0; i <n; i++) cout<<v[i]<<" "; cout<<endl;}

template<>
void afis(int v[10], int n){cout<<"specializare explicita pe int"; for(int i = 0; i <n; i++) cout<<v[i]<<" "; cout<<endl;}

template<class T>
class Gestiune
{
    T v[10];
    int n;
public:
    void citire(){cin>>n; for(int i = 0; i<n; i++) cin>>v[i];}
///    void afis(){for(int i = 0; i < n; i++) cout<<v[i]<<" "; cout<<endl;}
    void afis();
};

template<class T>
void Gestiune<T>::afis(){for(int i = 0; i < n; i++) cout<<v[i]<<" "; cout<<endl;}

int main()
{
    Gestiune<int> A;
    A.citire();
    A.afis();

    Gestiune<Produs> B;
    B.citire();
    B.afis();
/*        int v[3]={4,1,2};
        double w[4]={9.7, 1.3, 5.6, 6.34};
        afis(v,3);
        afis<>(v,3);
        afis<int>(v,3);
        afis(w,4);
        Produs A[2]={Produs(67),Produs(194)};
        afis(A,2);
*/
}

/***** Magazin ******/
/*** Cerinte:
1. Citirea tuturor produselor din magazin, folosind functii virtuale, respectiv, operatorul >>
2. Afisarea tuturor produselor in ordinea citirii
3. Cat costa toate produsele alimentare
4. Afisarea initiala a tuturor Jucariilor (toate tipurile) ordonate dupa pret, iar apoi, afisarea Lego ordonate descrescator dupa varsta ***/
/*
class Produs
{
protected:
    int pret;
    string denumire;
public:
    virtual void citire(){cout<<"pretul si denumirea: "; cin>>pret>>denumire;}
    friend ostream& operator<<(ostream& out, Produs& p){return out<<"Pret si denumire: "<<p.pret<<" "<<p.denumire<<endl;}
///    friend istream& operator>>(istream& in, Produs&p){ p.citire(); return in;}
    friend istream& operator>>(istream& in, Produs& p)
    {
        cout<<"pretul si denumirea: "; in>>p.pret>>p.denumire; return in;
    }
    int get_pret(){return pret;}
};

class Alimentar: public Produs
{
protected:
    string expirare;
public:
    void citire(){Produs::citire();cout<<"Data de expirare: "; cin>>expirare;}
    friend ostream& operator<<(ostream& out, Alimentar& a)
    {
///        return out<<(Produs&)(a)<<"Data expirare: "<<a.expirare<<endl;
        return out<<static_cast<Produs&>(a)<<"Data expirare: "<<a.expirare<<endl;
    }

    friend istream& operator>>(istream& in, Alimentar& a)
    {
        in>>static_cast<Produs&>(a);
        cout<<"Data expirare: ";
        in>>a.expirare;
    return in;
    }
};

class Jucarie: public Produs
{
protected:
    string tara;
public:
    void citire(){Produs::citire(); cout<<"Tara de origine: "; cin>>tara;}
};

class Lego: public Jucarie
{
    int varsta;
public:
    void citire(){Jucarie::citire(); cout<<"Varsta minima permisa: "; cin>>varsta;}
};

int main()
{
///    Produs* A = new Alimentar();
///    cout<<typeid(A).name()<<endl<<typeid(*A).name();
///    Alimentar B; B.citire(); cout<<B;

    vector<Produs*> v;

    int nr = 5;
    for(int i = 0; i<nr; i++)
    {
        int tip;
        cout<<"tip produs: ";
        cin>>tip;
        if (tip == 1)
            v.push_back(new Alimentar());
        else if (tip == 2)
            v.push_back(new Jucarie());
        else if (tip == 3)
            v.push_back(new Lego());

        (v.back())->citire();
    }

///    for(auto& x : v)
///        x->citire();

///    for(auto& x : v) cin>>*x; /// e ok pt varianta cu op>>(care foloseste fct virtuala de citire)

///        for(auto& x : v)
///            if (typeid(*x) == typeid(Alimentar))
///            cin>>*dynamic_cast<Alimentar*>(x);

    int pret_total = 0;
    for(auto& x : v)
        if (typeid(*x) == typeid(Alimentar))
            pret_total += x->get_pret();
    cout<<pret_total<<endl;

    for(auto& x : v)
        if(typeid(*x) == typeid(Jucarie))   /// afiseaza EXACT Jucarie
        cout<<*x;

    cout<<"*************\n";

    for(auto& x : v)
        if(typeid(x) == typeid(Jucarie*))
        cout<<*x;

    cout<<"*************\n";

    for(auto& x : v)
        if(dynamic_cast<Jucarie*>(x))       /// afiseaza Jucarie si nepotii etc (derivatele)
        cout<<*x;

    cout<<"*************\n";
    /**** idee rezolvare 4 ****/
 /*   vector<Jucarie*> q;
    for(auto& x : v)
        if(auto t = dynamic_cast<Jucarie*>(x)) q.push_back(t);

    for(auto& x: q)
        cout<<*x;

    sort(q.begin(), q.end(),[](Jucarie* a, Jucarie* b){return a->get_pret() < b->get_pret();});

        for(auto& x: q)
        cout<<*x;
}
*/
/*
void f(int x)
{
    try
    {
        if (x<0) throw 123;
    }
    catch(int a)
    {
        cout<<"int\n"; throw;
    }
    cout<<"in functie dupa throw local\n";
}

int main()
{
    try
    {
        f(-7);
        cout<<"dupa throw local\n";
    }
    catch(int x)
    {
        cout<<"in main\n";
    }
    cout<<"continuare program";
    return 0;
}
*/

/*
class Test
{
    int x;
public:
    Test(int _x)
    {
        if (_x < 0) throw 100;
    }
};


int main()
{
    vector<Test> v;
    try{
    v.push_back(Test(23));
    v.push_back(Test(-1));
    }
    catch(int z){cout<<"nu pt "<<z<<"\n";}
    cout<<v.size();
    return 0;
}
*/
