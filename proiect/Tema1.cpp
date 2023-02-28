#include <iostream>
#include <cstring>
using namespace std;

class echipa{
string nume,jucatori[5];
int an_infiintare, meciuri_pierdute ,rezultate_de_egal, meciuri_castigate;

public:


    string operator[](int)const;
    operator int();
    bool operator>(echipa&);
    bool operator<(echipa&);
    friend istream& operator>>(istream&, echipa&);
    friend ostream& operator<<(istream&, echipa&);

    friend echipa operator+(int, echipa);
    friend echipa operator+(string, echipa);
    friend echipa operator+(echipa, string);
    friend echipa operator+(echipa, int);


    void set_nume_echipa(string);
    void set_an_infiintare(int);
    void set_meciuri_castigate(int);
    void set_meciuri_pierdute(int);
    void set_rezultate_de_egal(int);
    void set_jucatori();

    string get_nume_echipa(){ return nume;}
    int get_an_infiintare(){ return this->an_infiintare;}
    int get_meciuri_castigate(){ return this->meciuri_castigate;}
    int get_meciuri_pierdute(){ return this->meciuri_pierdute;}
    int get_rezultate_egal(){ return this->rezultate_de_egal;}
    void get_jucatori(){ for(int i=0;i<5;i++)
                                    cout<<this->jucatori[i]<<"\n";
                                                                    }
    void get_jucatori(echipa ob){for(int i=0;i<5;i++)
                                    jucatori[i] = ob.jucatori[i];}
    void comparare_punctaj_echipe(echipa);
    void citeste_echipa();
    void citeste_echipa(string);
    void afisare_echipa();

};

class futsal_euro
{
    echipa *echipe_calificate;
    int contor=0;

public:
    futsal_euro(const futsal_euro&);

    futsal_euro(){echipe_calificate = NULL;}
    ~futsal_euro(){delete[] echipe_calificate;}

    echipa operator[](int)const;

    void set_adauga_echipa();
    void set_contor(int i){this->contor = i;}
    void set_echipe_calificate();

    int get_contor_c2(){return contor;}

    void stergere_echipa(string);
    void stergere_echipa(int);
    void stergere_echipa(int , int , int);

    void afisare_echipe_calificate();
    void afisare_echipe_ordonat(string);
    void afisare_echipe_ordonat(int);

};

class echipe_fondatoare{
    string nume[3];
    public:
        echipe_fondatoare(){nume[0]="";nume[1]="";nume[2]="";}
        set_nume(string s, int i){nume[i]=s;}
        string get_nume(int i){return nume[i];}
};
void echipa::citeste_echipa(){
    string s ; int i;
    cout<<"Citeste numele echipei(Nume UNIC format doar din litere si dintr-un singur cuvant): ";
    cin>>s;
    set_nume_echipa(s);
    cout<<"Citeste anul infiintarii echipei(numar): ";
    cin>>i;
    set_an_infiintare(i);
    cout<<"Citeste numarul de meciuri castigate al echipei(numar): ";
    cin>>i;
    set_meciuri_castigate(i);
    cout<<"Citeste numarul de meciuri pierdute al echipei(numar): ";
    cin>>i;
    set_meciuri_pierdute(i);
    cout<<"Citeste numarul de meciuri in care echipa a facut egal(numar): ";
    cin>>i;
    set_rezultate_de_egal(i);
    set_jucatori();
    cout<<"\n\n";
    }

void echipa::citeste_echipa(string k){
    string s ; int i;
    set_nume_echipa(k);
    cout<<"Citeste anul infiintarii echipei(numar):";
    cin>>i;
    set_an_infiintare(i);
    cout<<"Citeste numarul de meciuri castigate al echipei(numar):";
    cin>>i;
    set_meciuri_castigate(i);
    cout<<"Citeste numarul de meciuri pierdute al echipei(numar):";
    cin>>i;
    set_meciuri_pierdute(i);
    cout<<"Citeste numarul de meciuri in care echipa a facut egal(numar):";
    cin>>i;
    set_rezultate_de_egal(i);
    set_jucatori();

    }

int comparare_an_inf(int n, int m)
    {
        if(n == m)
            return 1;
        return 0;
    }


int comparare_rezultate(int a, int b, int c, int a1, int b1, int c1)
{
    if(a==a1 && b==b1 && c==c1)
        return 1;
    return 0;
}

int comparare_nume(string n, string m)
{
    if(m==n)
        return 1;
    return 0;
}


void echipa::afisare_echipa(){
cout<<"Numele echipei:"<<get_nume_echipa()<<"\nAm infiintare echipa: "<<get_an_infiintare()<<"\n"<<"Jucatori: \n"; get_jucatori();

cout<<"Numar meciuri castigate:"<<get_meciuri_castigate()<<"\n"<<"Numar meciuri pierdute: "<<get_meciuri_pierdute()<<"\n"<<"Numar rezultate de egal: "<<get_rezultate_egal()<<"\n\n";
}

bool echipa::operator>(echipa& ob)
{
    if(meciuri_castigate*3 + meciuri_pierdute*0 + rezultate_de_egal*1 > ob.meciuri_castigate*3 + ob.meciuri_pierdute*0 + ob.rezultate_de_egal*1)
        return 1;
    return 0;
}

bool echipa::operator<(echipa& ob)
{
    if(meciuri_castigate*3 + meciuri_pierdute*0 + rezultate_de_egal*1 < ob.meciuri_castigate*3 + ob.meciuri_pierdute*0 + ob.rezultate_de_egal*1)
        return 1;
    return 0;
}

echipa operator+(int i, echipa ob)
{   echipa C = ob;

    ob.set_meciuri_castigate(ob.get_meciuri_castigate()+i);
    ob.set_meciuri_pierdute(ob.get_meciuri_pierdute()+i);
    ob.set_rezultate_de_egal(ob.get_rezultate_egal()+i);
    return ob;
}

echipa operator+(echipa ob, int i)
{   echipa C = ob;

    ob.set_meciuri_castigate(ob.get_meciuri_castigate()+i);
    ob.set_meciuri_pierdute(ob.get_meciuri_pierdute()+i);
    ob.set_rezultate_de_egal(ob.get_rezultate_egal()+i);
    return ob;
}


echipa operator+(string s, echipa ob)
{
    echipa C = ob;
    ob.set_nume_echipa(ob.get_nume_echipa() + string(s));
    return ob;
}

echipa operator+(echipa ob, string s)
{   echipa C = ob;
    ob.set_nume_echipa(ob.get_nume_echipa()+s);
    return ob;
}

string echipa::operator[](int i)const
{
    return jucatori[i];
}

echipa::operator int(){
    int s;
    s = an_infiintare + 3 * meciuri_castigate + 0 * meciuri_pierdute + 1 * rezultate_de_egal;
    return s;}


istream& operator>>(istream& in, echipa& A)
{
    string s; int i;
    cout<<"Citeste numele echipei(string):";
    cin>>s;
    A.set_nume_echipa(s);
    cout<<"Citeste anul infiintarii echipei(numar):";
    cin>>i;
    A.set_an_infiintare(i);
    cout<<"Citeste numarul de meciuri castigate al echipei(numar):";
    cin>>i;
    A.set_meciuri_castigate(i);
    cout<<"Citeste numarul de meciuri pierdute al echipei(numar):";
    cin>>i;
    A.set_meciuri_pierdute(i);
    cout<<"Citeste numarul de meciuri in care echipa a facut egal(numar):";
    cin>>i;
    A.set_rezultate_de_egal(i);
    A.set_jucatori();
    return in;
}

ostream& operator<<(ostream& out, echipa& ob)
{
cout<<"Numele echipei:"<<ob.get_nume_echipa()<<"\nAm infiintare echipa: "<<ob.get_an_infiintare()<<"\n"<<"Jucatori: \n"; ob.get_jucatori();

cout<<"Numar meciuri castigate:"<<ob.get_meciuri_castigate()<<"\n"<<"Numar meciuri pierdute: "<<ob.get_meciuri_pierdute()<<"\n"<<"Numar rezultate de egal: "<<ob.get_rezultate_egal()<<"\n\n";
return out;
}


void echipa::comparare_punctaj_echipe(echipa ob2)
{
    int suma1, suma2;

    suma1 = this->meciuri_castigate*3 + this->meciuri_pierdute*0 + this->rezultate_de_egal*1;
    suma2 = ob2.meciuri_castigate*3 + ob2.meciuri_pierdute*0 + ob2.rezultate_de_egal*1;

    if(suma1>suma2)
        cout<<"Echipa "<<this->nume<<" are cu "<<suma1-suma2<<" mai multe puncte decat echipa "<<ob2.nume;
    else
        if(suma1<suma2)
            cout<<"Echipa "<<ob2.nume<<" are cu "<<suma2-suma1<<" mai multe puncte decat echipa "<<this->nume;
        else
            cout<<"Echipele "<<this->nume<<" si"<<ob2.nume<<" sunt la egalitate de puncte cu "<<suma1<<" puncte fiecare.";

}



echipa futsal_euro::operator[](int i)const
{
    return echipe_calificate[i];
}

void futsal_euro::set_adauga_echipa(){
    echipa ob;
    if(contor==0)
        {
        ob.citeste_echipa();
        echipe_calificate = new echipa [1];
        echipe_calificate[0] = ob;
        }
    else
    {echipa c[contor];
    ob.citeste_echipa();
    for(int i=0;i<contor;i++)
        c[i] = echipe_calificate[i];
    this->echipe_calificate = new echipa [contor+1];

    for(int i=0;i<contor;i++)
        echipe_calificate[i] = c[i];

    echipe_calificate[contor] = ob;}
}

void futsal_euro::set_echipe_calificate()
{
    echipa x;
    echipe_calificate = new echipa [this->contor];
    for(int j=0;j<this->contor;j++)
        {
         cout<<"Citeste datele pentru echipa cu numarul "<<j+1<<":\n";
         echipe_calificate[j].citeste_echipa();
        }
}

void futsal_euro::stergere_echipa(string sir)
{
    int ok=0;
    for(int i=0;i<contor;i++)
        if(comparare_nume(sir, echipe_calificate[i].get_nume_echipa()) != 0)
        {
            for(int j=i;j<contor-1;j++)
                echipe_calificate[j] = echipe_calificate[j+1];
            ok = 1;
            break;
        }
    if(ok==1)
        {contor--;
         cout<<"Stergere efectuata cu succes\n\n";
         }
    else
        cout<<"Nu exista nicio echipa cu numele citit si astfel nu s-a efectuat nicio stergere";

}

void futsal_euro::stergere_echipa(int an_inf)
{   int ok = 0;
    for(int i=0;i<contor;i++)
        if(comparare_an_inf(an_inf, echipe_calificate[i].get_an_infiintare()))
        {
            for(int j=i;j<contor-1;j++)
                echipe_calificate[j] = echipe_calificate[j+1];
            ok = 1;
            contor--;
        }
    if(ok==0)
        cout<<"Nu exista nicio echipa cu numele citit si astfel nu s-a efectuat nicio stergere";
    else
        cout<<"Stergere efectuata cu succes\n\n";
}

void futsal_euro::stergere_echipa(int m_c, int m_p, int m_e)
{   int ok = 0;
    for(int i=0;i<contor;i++)
        if(comparare_rezultate(m_c, m_p, m_e, echipe_calificate[i].get_meciuri_castigate(), echipe_calificate[i].get_meciuri_pierdute(), echipe_calificate[i].get_rezultate_egal()) !=0)
        {
            for(int j=i;j<contor-1;j++)
                echipe_calificate[j] = echipe_calificate[j+1];
            ok = 1;
            contor--;
        }
    if(ok==0)
        cout<<"Nu exista nicio echipa cu numele citit si astfel nu s-a efectuat nicio stergere";
    else
        cout<<"Stergere efectuata cu succes\n\n";
}


void futsal_euro::afisare_echipe_calificate(){
for(int i=0;i<contor;i++)
    echipe_calificate[i].afisare_echipa();
}

void futsal_euro::afisare_echipe_ordonat(string ordonare)
{
    string nume[contor], aux;
    int i,j;
    for(i=0;i<contor;i++)
        nume[i]=echipe_calificate[i].get_nume_echipa();

    for(i=0;i<contor-1;i++)
        for(j=i+1;j<contor;j++)
            if(nume[i] > nume[j])
            {
                aux=nume[i];
                nume[i]=nume[j];
                nume[j]=aux;
            }

    if(ordonare=="crescator")
        {cout<<"Echipele vor fi afisate in ordine "<<ordonare<<" in functie de numele echipei.\n";
            for(i=0;i<contor;i++)
                for(j=0;j<contor;j++)
                    if(comparare_nume(nume[i], echipe_calificate[i].get_nume_echipa()) != 0)
                    {
                        echipe_calificate[i].afisare_echipa();
                        cout<<"\n\n";
                        break;
                    }
        }
    else
        if(ordonare=="descrescator")
            {cout<<"Echipele vor fi afisate in ordine "<<ordonare<<" in functie de numele echipei.\n";
             for(i=contor-1;i>=0;i--)
                for(j=0;j<contor;j++)
                    if(comparare_nume(nume[i], echipe_calificate[j].get_nume_echipa()) != 0)
                    {
                        echipe_calificate[i].afisare_echipa();
                        cout<<"\n\n";
                        break;
                    }
            }
        else
            cout<<"Nu se poate face ordonarea dupa criteriul dat.";
}

void futsal_euro::afisare_echipe_ordonat(int k)
{
    string nume[contor], aux;
    int arr_an_inf[contor], c;
    int i,j;
    for(i=0;i<contor;i++)
        nume[i]=echipe_calificate[i].get_nume_echipa();

    for(i=0;i<contor;i++)
        arr_an_inf[i]=echipe_calificate[i].get_an_infiintare();

    for(i=0;i<contor-1;i++)
        for(j=i+1;j<contor;j++)
            if(arr_an_inf[i]>arr_an_inf[j])
                {
                c=arr_an_inf[i];
                arr_an_inf[i]=arr_an_inf[j];
                arr_an_inf[j]=c;

                aux=nume[i];
                nume[i]=nume[j];
                nume[j]=aux;
                }

    if(k == 1)
        {
        cout<<"Echipele vor fi afisate in ordine crescatore in functie de anul infiintarii echipei.\n";
        for(i=0;i<contor;i++)
            for(j=0;j<contor;j++)
                if(comparare_nume(nume[i], echipe_calificate[j].get_nume_echipa()) != 0)
                {
                    echipe_calificate[i].afisare_echipa();
                    cout<<"\n\n";
                    break;
                }
        }
    else
        if(k == -1)
        {
            cout<<"Echipele vor fi afisate in ordine descrescatoare in functie de anul infiintarii echipei.\n";
            for(i=contor-1;i>=0;i--)
                for(j=0;j<contor;j++)
                    if(comparare_nume(nume[i], echipe_calificate[j].get_nume_echipa()) != 0)
                    {
                        echipe_calificate[i].afisare_echipa();
                        cout<<"\n\n";
                        break;
                    }
        }
        else
            cout<<"Nu se poate face ordonarea dupa criteriul dat.";
}

void echipa::set_nume_echipa(string s){ nume=s;}
void echipa::set_an_infiintare(int i){this->an_infiintare=i;}
void echipa::set_meciuri_castigate(int i){this->meciuri_castigate=i;}
void echipa::set_meciuri_pierdute(int i){this->meciuri_pierdute=i;}
void echipa::set_rezultate_de_egal(int i){this->rezultate_de_egal=i;}
void echipa::set_jucatori(){
    cout<<"Citeste cei 5 jucatori ai echipei(Nume format doar din litere si dintr-un singur cuvant);\n";
    for(int i=0;i<5;i++)
        cin>>this->jucatori[i];

}

int main()
{
int i1, i2;
echipe_fondatoare F;
futsal_euro C;

int choice=1;

while(choice)
{   cout<<"************************************************************************************************************************\n";
    cout<<"Alege o optiune: \n\n";
    cout<<"1 - Citeste numele celor 3 echipe fondatoare\n";
    cout<<"2 - Citeste informatiile despre echipele calificate la UEFA Futsal Championship\n";
    cout<<"3 - Adauga o echipa la UEFA Futsal Championship\n";
    cout<<"4 - Sterge o/echipe din UEFA Futsal Championship\n";
    cout<<"5 - Compara punctajele a doua echipe din UEFA Futsal Championship\n";
    cout<<"6 - Modifica informatiile despre o echipa\n";
    cout<<"7 - Afiseaza o echipa din UEFA Futsal Championship\n";
    cout<<"8 - Afiseaza numele echipelor fondatoare\n";
    cout<<"9 - Paraseste programul\n\n";

    cout<<"Citeste numarul asociat optiunii dorite: ";
    cin>>choice;
    cout<<"\n\n";
    cout<<"************************************************************************************************************************\n\n";

    if(choice==1)
    {   cout<<"Optiunea 1:\n\n";

        for(int i=0;i<3;i++)
        {
            string n1;
            cout<<"Citeste numele echipei fondatoare cu numarul "<<i+1<<"(Nume UNIC format doar din litere si dintr-un singur cuvant): ";
            cin>>n1;
            F.set_nume(n1, i);
            cout<<"\n";
        }
    }

    if(choice==2)
    {
        int nr;
        cout<<"Optiunea 2:\n\n";
        cout<<"Citeste numarul echipelor calificate(numar):";
        cin>>nr;
        C.set_contor(nr);
        C.set_echipe_calificate();

    }

    if(choice==3)
        {
        cout<<"Optiunea 3:\n\n";
        if(C.get_contor_c2()==0)
            cout<<"Nu se poate adauga o echipa intrucat nu s-a citit pana acum nicio echipa calificata!\n";
        else
            {
            cout<<"Optiunea 3:\n\n";
            cout<<"Citeste datele despre echipa pe care vrei sa o adaugi:\n";
            C.set_adauga_echipa();
            C.set_contor(C.get_contor_c2()+1);
            }
        }

    if(choice==4)
    {
        cout<<"Optiunea 4:\n\n";
        int select=1;

        if(int(C.get_contor_c2()) != 0)
        {
        while(select)
        {
            cout<<"--------------------------------------------------------------------------------------------------------------------\n";
            cout<<"Alege metoda de stergere a unei/unor echipe:\n\n";
            cout<<"1 - Sterge o echipa dupa numele echipei\n";
            cout<<"2 - Sterge o echipa dupa data infiintarii echipei(se va sterge prima echipa care are anul infiintarii precizat)\n";
            cout<<"3 - Sterge o echipa dupa numarul de meciuri castigate/pierdute/egalitate(se va sterge prima echipa care are rezultatele respective)\n";
            cout<<"4 - Inapoi\n";

            cout<<"Citeste numarul asociat optiunii dorite: ";
            cin>>select;
            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------------------------------------------------------\n\n";

            if(select==1)
            {   string s1;
                cout<<"Optiunea 1:\n\n";
                cout<<"Citeste numele echipei pe care vrei sa o stergi(Nume UNIC format doar din litere si dintr-un singur cuvant):";
                cin>>s1;
                C.stergere_echipa(s1);

            }
            if(select==2)
            {
                int c1;
                cout<<"Optiunea 2:\n\n";
                cout<<"Citeste anul infiintarii echipei/echipelor pe care vrei sa o/le stergi(Numar):";
                cin>>c1;
                C.stergere_echipa(c1);
            }
            if(select==3)
            {
                int m1, m2, m3;
                cout<<"Optiunea 2:\n\n";
                cout<<"Citeste numarul de meciuri castigate/pierdute/egal al echipei/echipelor pe care vrei sa o/le stergi)\n";
                cout<<"Numarul de meciuri castigate:";
                cin>>m1;
                cout<<"\n";
                cout<<"Numarul de meciuri pierdute:";
                cin>>m2;
                cout<<"\n";
                cout<<"Numarul de meciuri in care rezultatul a fost la egalitate:";
                cin>>m3;
                C.stergere_echipa(m1,m2,m3);
            }
            if(select==4)
                break;
            if(select!=1 && select!=2 && select!=3 && select!=4)
                {
                    cout<<"Numarul introdus nu corespunde niciunei optiuni!\n";
                    break;
                }


        }
        }
        else
            cout<<"In prezent nu este nicio echipa calificata in UEFA Futsal Championship, deci nu se poate utiliza optiunea de stergere\n";


    }

    if(choice==5)
    {   int select2=1;
        cout<<"Optiunea 5:\n\n";

        while(select2)
        {
        cout<<"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";
        cout<<"Alege o optiune: \n\n";
        cout<<"1 - Compara doua echipe noi\n";
        cout<<"2 - Compara doua echipe dintre echipele calificate la UEFA Futsal Championship\n";
        cout<<"3 - Inapoi\n";

        cout<<"Citeste numarul asociat optiunii dorite: \n";
        cin>>select2;
        cout<<"\n\n";
        cout<<"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";

        if(select2==1)
        {
            cout<<"Optiunea 1:\n\n";
            echipa A, B;

            cout<<"Citeste datele pentru cele 2 echipe create:\n\n";
            A.citeste_echipa();
            B.citeste_echipa();
            A.comparare_punctaj_echipe(B);
        }

        if(select2==2)
        {   cout<<"Optiunea 2:\n\n";

            if(C.get_contor_c2()>1)
            {
           cout<<"Citeste cei doi indici ai echipelor calificate la UEFA Futsal Championship";
           int ok=1;
            while(ok)
                {cout<<"Citeste primul indice:";
                 cin>>i1;
                 if(i1>=C.get_contor_c2())
                    cout<<"Indicele nu corespunde niciunei echipe!\n";
                 else
                    ok=0;
                    }
            ok=1;
            while(ok)
                {cout<<"Citeste al doilea indice:";
                 cin>>i2;
                 if(i2>=C.get_contor_c2() && i2==i1)
                    cout<<"Indicele nu corespunde niciunei echipe sau a fost deja selectat!\n";
                 else
                    ok=0;
                    }
            C[i1].comparare_punctaj_echipe(C[i2]);
            }
            else
                cout<<"In prezent nu sunt destule echipa calificate in UEFA Futsal Championship, deci nu se poate utiliza optiunea de comparare\n";
        }
        if(select2==3)
            {
                select2=0;
                break;
            }
        if(select2!=1 && select2!=2 && select2!=3)
            {
                cout<<"Numarul introdus nu corespunde niciunei optiuni!\n";
                break;
            }
    }
    }

    if(choice==6)
    {
        cout<<"Optiunea 6:\n\n";
        int select3=1;

        while(select3)
        {
        cout<<"==============================================================================================================================\n\n";
        cout<<"Alege o optiune: \n\n";
        cout<<"1 - Modifica informatiile despre o echipa noua\n";
        cout<<"2 - Modifica informatiile despre o echipa calificata la UEFA Futsal Championship\n";
        cout<<"3 - Inapoi\n";

        cout<<"Citeste numarul asociat optiunii dorite: \n";
        cin>>select3;
        cout<<"\n\n";
        cout<<"==============================================================================================================================\n\n";

        if(select3==1)
        {
            cout<<"Optiunea 1:\n\n";
            echipa A;
            cout<<"Citeste datele despre noua echipa pe care vrei sa o modifici\n\n";
            cin>>A;

            int select4=1;
            while(select4)
            {   cout<<"#######################################################################################################################\n\n";
                cout<<"Alege o optiune: \n\n";
                cout<<"1 - Concateneaza un sir la sfarsitul numelui unei echipe noi\n";
                cout<<"2 - Adauga un numar la meciurile castigate/pierdute/egal al echipei noi\n";
                cout<<"3 - Afiseaza echipa modificata\n";
                cout<<"4 - Inapoi\n";

                cout<<"Citeste numarul asociat optiunii dorite: \n";
                cin>>select4;
                cout<<"\n\n";
                cout<<"#######################################################################################################################\n\n";

                if(select4 == 1)
                {
                    string p1;
                    cout<<"Citeste sirul dorit(sir format doar din litere, respectiv un singur cuvant): \n";
                    cin>>p1;
                    A = A + p1;
                    cout<<"Echipa modificata: \n\n";
                    A.afisare_echipa();
                }

                if(select4==2)
                {
                int s1;
                cout<<"Citeste numarul pe care vrei sa l adaugi la meciurile castigate/pierdute/egal al echipei noi\n";
                cin>>s1;
                A = A + s1;
                cout<<"Echipa modificata: \n\n";
                A.afisare_echipa();

                }

                if(select4 ==3)
                    cout<<A;

                if(select4==4)
                break;

            }

        }

        if(select3==2)
        {
            cout<<"Optiunea 2:\n\n";
            if(C.get_contor_c2()!=0)
            {
            int i11;
            int select5=1;
            while(select5)
            {
                cout<<"Citeste indicele corespunzator echipei: \n";
                cin>>i11;
                if(i11>=C.get_contor_c2())
                    cout<<"Indicele nu corespunde niciunei echipe\n";
                else
                    break;}


            int select4=1;
            while(select4)
            {   cout<<"#######################################################################################################################\n\n";
                cout<<"Alege o optiune: \n\n";
                cout<<"1 - Concateneaza un sir la sfarsitul numelui echipei alese\n";
                cout<<"2 - Adauga un numar la meciurile castigate/pierdute/egal al echipei alese\n";
                cout<<"3 - Inapoi\n";

                cout<<"Citeste numarul asociat optiunii dorite: \n";
                cin>>select4;
                cout<<"\n\n";
                cout<<"#######################################################################################################################\n\n";

                if(select4 == 1)
                {
                    string p1;
                    cout<<"Citeste sirul dorit(sir format doar din litere, respectiv un singur cuvant): \n";
                    cin>>p1;
                    C[i11] = C[i11] + p1;
                    cout<<"Echipa modificata: \n\n";
                    C[i11].afisare_echipa();
                }

                if(select4==2)
                {
                int s1;
                cout<<"Citeste numarul pe care vrei sa l adaugi la meciurile castigate/pierdute/egal al echipei alese\n";
                cin>>s1;
                C[i11] = C[i11] + s1;
                cout<<"Echipa modificata: \n\n";
                C[i11].afisare_echipa();

                }
                if(select4==3)
                break;

            }
            }
            else
                cout<<"In prezent nu este nicio echipa calificata la UEFA Futsal Championship, deci nu se poate efectua aceasta optiune\n";




        }
        if(select3==3)
            break;


        }

    }

    if(choice==7)
    {
    cout<<"Optiunea 7:\n\n";
    int select7 = 1;

    while(select7)
    {
    cout<<"************************************************************************************************************************\n";
    cout<<"1 - Afiseaza informatiile despre o echipa calificata la UEFA Futsal Championship\n";
    cout<<"2 - Inapoi\n";

    cout<<"Citeste numarul asociat optiunii dorite: ";
    cin>>select7;
    cout<<"\n\n";
    cout<<"************************************************************************************************************************\n\n";

    if(select7==1)
        if(C.get_contor_c2()!=0)
        {int i11;
        int select5=1;
        while(select5)
        {
            cout<<"Citeste indicele corespunzator echipei: \n";
            cin>>i11;
            if(i11>=C.get_contor_c2())
                cout<<"Indicele nu corespunde niciunei echipe\n";
            else
                break;}
        C[i11].afisare_echipa();
        }

        else
            cout<<"In prezent nu este nicio echipa calificata la UEFA Futsal Championship, deci nu se poate efectua aceasta optiune\n";

    if(select7==2)
        break;

    }
    }

    if(choice==8)
    {
        cout<<"Optiunea 8:\n\n";
        if(F.get_nume(0) == "" && F.get_nume(1) == "" && F.get_nume(2) == "")
            cout<<"Nu s-au citit numele echipelor fondatoare!\n";
        else
        {cout<<"Numele echipelor fondatoare sunt:\n\n";
            for(int i=0;i<3;i++)
                cout<<F.get_nume(i)<<"\n";

        }
    }

    if(choice==9)
        break;
    }



return 0;
}
