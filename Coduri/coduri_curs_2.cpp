#include <iostream>
#include <vector>
using namespace std;

/**** modificatorii de acces private, protected, public ****/

class Test
{
    int x;
protected:
    int y;
public:
    int z;
public:
    void afis(){cout<<x<<" "<<y<<" "<<z<<endl;}
};

class Derivata : protected Test
{
public:
    void afis2(){afis();}
};

class Derivata2 : public Derivata{
public:
    void afis3(){afis();}
    };

int main()
{
    Test A;
///    cout<<A.x<<" "<<A.y<<" "<<A.z<<endl; /// inaccesibil x si y
    A.afis();
    Derivata B;
///    B.afis(); ///inaccesibila pt ca mostenire privata
    B.afis2();
    Derivata2 C;
 C. afis(); ///inaccesibil chiar daca mostenirea Deriv2 este publica
    C.afis3();
}

/**** pot utiliza functii din clasa fara sa instantiez clasa? ****/
/*
class Test
{
public:
    static void f(){}
    void g(){}
};

int main()
{
    Test::f(); /// functiile statice pot fi folosite direct cu numele clasei
    Test A;
    A.f();
///    Test::g();
}
*/
/**** struct poate participa la mostenire ****/
/*
struct Baza
{
  void afis(){cout<<"baza\n";}
};

class Derivata :  private Baza{
public:
    void afis(){cout<<"derivata\n";}
};

int main()
{
    Derivata A;
    A.afis();
}
*/
/************* functii virtuale + upcast ****/
/*
class Baza
{
public:
   virtual void afis(){cout<<"baza\n";}
///    virtual void afis1(){cout<<"baza\n";}
///     virtual void afis2(){cout<<"baza\n";}
};

class Derivata : public Baza
{
public:
    void afis(){cout<<"derivata\n";}
};

int main()
{
///    Derivata *A = new Derivata();
///    A->afis();
    Baza* B = new Derivata(); /// upcast
///    B->afis();

    cout<<sizeof(Baza);
    return 0;
}
*/

/***** new si delete sau malloc/calloc/realloc? Raspuns: STL :D *******/
/*
int main()
{
    vector<int> v;
    cout<<v.size()<<" "<<v.capacity()<<'\n';
    v.push_back(12);
    cout<<v.size()<<" "<<v.capacity()<<'\n';
    v.push_back(34);
    cout<<v.size()<<" "<<v.capacity()<<'\n';
    v.push_back(56);
    cout<<v.size()<<" "<<v.capacity()<<'\n';

    for(int i = 0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    vector<int>::iterator p;
    for(p = v.begin(); p != v.end(); p++)
        cout<<*p<<" ";
    cout<<endl;
   for(int& x : v) cout<<x<<" ";
   cout<<endl;
   for(auto& x : v) cout<<x<<" ";
   cout<<endl;
}
*/
/********** cand se apeleaza constructorul si destructorul la obiecte si pointeri ****/
/*
class Test
{
    int x;
    public:
    Test(){x = 100; cout<<"constructor\n";}
    ~Test(){cout<<"dest\n";}
    void afis(){cout<<x;}
};

int main()
{
  ///  Test A;  /// constr si destr se apeleaza automat pentru obiecte
  ///  A.afis();
  Test *B;
  B = new Test(); /// pentru pointeri, constr se apeleaza doar cu new si destructorul cu delete
  delete B;
}
*/

/************* exemplu de supraincarcare de functii in cadrul mostenirii ****/
/*
class Baza
{
public:
    void afis(){cout<<"baza\n";}
};

class Derivata : public Baza
{
public:
    void afis(){
        ///cout<<"derivata\n";
        Baza::afis();
        }
};

int main()
{
    Derivata A;
    A.afis();  /// se preia functia din clasa proprie (sau cea mai apropiata in ierarhie)
///    A.Baza::afis(); /// se apeleaza functia din clasa parinte
    return 0;
}
*/

/********** utilizarea operatorului de rezolutie de scop pentru accesarea var globale **/
/*
int x = 10;
void f(int x)
{
    cout<<::x;/// afiseaza x global
    cout<<x; /// afiseaza x din zona stivei functiei f
}
int main()
{
    int x = 30;
    f(x);
}
*/
