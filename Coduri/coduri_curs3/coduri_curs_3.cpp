#include <iostream>

using namespace std;

class test
{
    int x;
public:
    test(int z){ x = z;}
    operator int() {return x;}
};

int main()
{
    test A = 67; /// necesar pentru cast un constr param cu 1 param
    int y;
    y = A; /// necesar operatorul de cast catre tipul int;
    cout<<y;
}

/**** pointeri catre derivate? ****/
/*
class baza{
public:
    baza(int x = 12){cout<<"constr baza\n";}
    virtual~baza(){cout<<"destr baza\n";}
};

class derivata : public baza
{
    public:
    derivata(int x = 23){cout<<"constr deriv\n";}
    ~derivata(){cout<<"destr derivata\n";}
};

class derivata2 : public derivata
{
    public:
    derivata2(int x = 23){cout<<"constr deriv2\n";}
    ~derivata2(){cout<<"destr derivata2\n";}
};

int main()
{
  ///  derivata A;
  ///  derivata* p = new derivata();
  ///  delete p;
  /// baza* q = new derivata();
  /// delete q;
  baza* r = new derivata2();
  delete r;
}
*/

/**** pointeri catre obiecte ****/

/*
class baza
{
public:
///    baza(){}
    baza(int x = 12){cout<<"constr\n";}
    ~baza(){cout<<"destr\n";}
};

int main()
{
    baza A(67);
    baza *p;
    p = new baza(34);
    delete p;
    baza *v = new baza[2];
    delete[] v;
}
*/

/**** move constructor CUT+PASTE****/
/*
class test
{
    int *v;
public:
    test(){ v = NULL;}
    test(int n) { v = new int[n]; cout<<"para\n";}
    ~test(){delete[] v; cout<<"destr\n";}
    void afis(){cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;}
///    test(const test& obj) = default;
    test(const test& obj){v = new int[3]; for(int i = 0; i <3; i++) v[i] = obj.v[i]; cout<<"copiere\n";}
    test(test&& obj){v = obj.v; obj.v = NULL; cout<<"mutare\n";}

};

int main()
{
    test A(3);
    A.afis();
    test B = A;
    B.afis();
    test C = move(B);
    C.afis();
    B.afis();
    return 0;
}
*/

/**** constructorul de copiere ****/
/*
class test
{
    int *v;
public:
    test(){ v = NULL;}
    test(int n) { v = new int[n]; for(int i = 0; i < n; i++) v[i] = (i+1)*10;}
    ~test(){delete[] v;}
    void afis(){cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;}
///    test(const test& obj) = default;
    test(const test& obj){v = new int[3]; for(int i = 0; i <3; i++) v[i] = obj.v[i];}
};

int main()
{
    test A(3);
    A.afis();
    test B = A;
    B.afis();
    test C = move(B);
    C.afis();
    return 0;
}
*/
/********** functii si clase friend *********/
/// friend - acceseaza datele membre private si protected dintr-o clasa
/// a se folosi cu moderatie
/// utile la supraincarcarea de operatori, cand conteaza ordinea parametrilor functiilor operator
/*
class masina
{
    int an;
public:
    void afis();
    friend void citire(masina& obj);
    friend istream& operator>>(istream&, masina&);
    ostream& operator<<(ostream&);
};

class autobuz : public masina
{
    int roti;
};

void citire(masina& obj){cin>>obj.an;}
istream& operator>>(istream& in, masina& obj)
    {
        in>>obj.an; return in;
    }

    ostream& masina::operator<<(ostream& out)
    {
        out<<an;
    }

int main()
{
    masina A;
///    citire(A);
    cin>>A; /// operator>>(cin,A)
///    cin>>A>>B; /// operator>>( operator>>(cin,A) , B)
    A.afis();
    A<<cout; ///A.operator<<(cout); ///cout<<A;
    autobuz B;
    cin>>B;
    B.afis();

 ///   A + B; /// A.operator+(B); operator+(A,B)
 ///   34 + A; /// operator+(int,A)
 ///   A + 67; /// A.operator+(int); operator+(A,int)
    return 0;
}

void masina::afis(){cout<<an<<"\n";}
*/

/***  accesare date membre private prin setter ****/
/*
class masina
{
    int an;
public:
    void afis();
    void set_an(int);
};

void citire(masina& obj){int x; cin>>x; obj.set_an(x);}

int main()
{
    masina A;
    citire(A);
    A.afis();
    return 0;
}

void masina::afis(){cout<<an<<"\n";}
void masina::set_an(int x){an = x;}
*/
