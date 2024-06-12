#include <iostream>
#include <math.h>
using namespace std;
void citire(int v[],int n)
{
    int i;
    for(i=1; i<=n; i++)
        cin>> v[i];
}
void copiere(int v[],int u[],int n)
{
    int i;
    for(i=1; i<=n; i++)
        u[i]=v[i];
}
void restabilire(int v[],int u[],int n)
{
    int i;
    for(i=1; i<=n; i++)
        v[i]=u[i];
}
void afisare(int v[],int n)
{
    int i;
    for(i=1; i<=n; i++)
        cout << v[i]<< " ";
}

int celmaimarenr(int v[],int n)
{
    int i,max=-100000000;
    for(i=1; i<=n; i++)
        if(v[i]>max)
            max=v[i];
    return max;
}
int celmaimicnr(int v[],int n)
{
    int i,min=100000000;
    for(i=1; i<=n; i++)
        if(v[i]<min)
            min=v[i];
    return min;
}
int suma(int v[],int n)
{
    int i,s=0;
    for(i=1; i<=n; i++)
        s=s+v[i];
    return s;
}
void ultimacifra(int v[],int n)
{
    int i;
    for(i=1; i<=n; i++)
        cout <<  v[i]%10<< " ";
}
int ePrim(int n)
{
    int i;
    if(n<2)
        return 0;
    for(i=2; i<=n/2; i++)
        if(n%i==0)
            return 0;
    return 1;
}
void nrPrime(int v[],int n)
{
    int i,ok=0;
    for(i=1; i<=n; i++)
        if(ePrim(v[i])==1)
            ok=1;
    if(ok==0)
        cout << "Nu exista numere prime in acest vector.";
    else
    {
        cout << "Numerele prime din acest vector sunt:";
        for(i=1; i<=n; i++)
            if(ePrim(v[i])==1)
                cout << v[i]<< " ";
    }

}
void SortarePrinInterschimbare(int v[],int n)
{
    int i,ok=1;
    while(ok)
    {
        ok=0;
        for(i=1; i<=n-1; i++)
            if(v[i]>v[i+1])
            {
                v[i]=v[i]+v[i+1];
                v[i+1]=v[i]-v[i+1];
                v[i]=v[i]-v[i+1];
                ok=1;
            }
    }
    for(i=1; i<=n; i++)
        cout << v[i]<< " ";
}
int invers(int n)
{
    int m=0;
    while(n>0)
    {
        m=m*10+n%10;
        n=n/10;
    }
    if(m/10!=0)
        return m;
}
void palindrom(int v[],int n)
{
    int i,ok=0;
    for(i=1; i<=n; i++)
        if(v[i]==invers(v[i]) && v[i]%10!=0)
            ok=1;
    if(ok==0)
        cout << "Nu exista numere palindrom in acest vector.";
    else
    {
        cout << "Numerele palindrom din acest vector sunt:";
        for(i=1; i<=n; i++)
            if(v[i]==invers(v[i]) && v[i]%10!=0)
                cout << v[i] << " ";
    }
}
void patratperfect(int v[],int n)
{
    int i,ok=0;
    for(i=1; i<=n; i++)
        if(sqrt(v[i])==(int)sqrt(v[i]) && v[i]>2 )
            ok=1;
    if(ok==0)
        cout << "Nu exista patrate perfecte in acest vector.";
    else
    {
        cout << "Numerele patrate perfecte din acest vector sunt:";
        for(i=1; i<=n; i++)
            if(sqrt(v[i])==(int)sqrt(v[i]) && v[i]>2)
                cout << v[i]<< " ";
    }
}
void SortarePrinMinim(int v[],int n)
{
    int i,min,imin,j;
    for(i=1; i<=n-1; i++)
    {
        min=v[i];
        imin=i;
        for(j=i+1; j<=n; j++)
            if(min>v[j])
            {
                min=v[j];
                imin=j;
            }
        v[imin]=v[i];
        v[i]=min;
    }
    for(i=1; i<=n; i++)
        cout << v[i]<< " ";
}
int pozitia(int v[],int n,int k)
{
    int i;
    for(i=1; i<=n; i++)
        if(v[i]==k)
            return i;
}
void stergere(int v[],int n,int k)
{
    int i;
    for(i=k; i<n; i++)
    {
        v[i]=v[i+1];
    }
    n--;
}
void div(int v[],int n,int k)
{
    int i,ok=0;
    for(i=1; i<=n; i++)
        if(v[i]%k==0)
            ok=1;
    if(ok==0)
        cout << "Nu exista numere divizibile cu aceasta valoare.";
    else
    {
        cout << "Numerele divizibile cu aceasta valoare sunt:";
        for(i=1; i<=n; i++)
            if(v[i]%k==0)
                cout << v[i]<< " ";
    }
}
int main()
{
    int v[100],n,x,p[100],s[100],pr[100];
    cout << "Introduceti dimensiunea vectorului: ";
    cin>>n;
    cout << "Cititi vectorul: ";
    citire(v,n);
    int u[100];
    copiere(v,u,n);
    cout << endl << endl;
    cout << "       Dispunem de urmatoarele prelucrari:"<<endl;
    cout << "       1.  Cel mai mic numar din vector."<<endl;
    cout << "       2.  Cel mai mare numar din vector."<<endl;
    cout << "       3.  Numerele palindrom din vector."<<endl;
    cout << "       4.  Numerele patrate perfecte din vector."<<endl;
    cout << "       5.  Numerele prime din vector."<<endl;
    cout << "       6.  Ultimele cifre ale fiecarui element din vector."<<endl;
    cout << "       7.  Suma tuturor elementelor din vector."<<endl;
    cout << "       8.  Sortarea prin interschimbare a elementelor din vector."<<endl;
    cout << "       9.  Sortarea prin selectarea minimului a elementelor din vector."<<endl;
    cout << "       10. Pozitia numarului k in vector."<< endl;
    cout << "       11. Stergerea elementului de pe pozitia k in vector."<<endl;
    cout << "       12. Numerele divizibile cu k in vector."<<endl;
    cout << "       13. Citirea unui alt vector."<<endl;
    cout << endl<< endl;
    cout << "Selectati o prelucrare:";
    cin>>x;
    cout << endl;
    while(x!=0)
    {
        switch(x)
        {
        case 1:
        {
            cout << "Cel mai mic numar din vector este:";
            cout << celmaimicnr(v,n);
            cout << endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 2:
        {
            cout << "Cel mai mare numar din vector este:";
            cout << celmaimarenr(v,n);
            cout << endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 3:
        {

            palindrom(v,n);
            cout << endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 4:
        {

            patratperfect(v,n);
            cout << endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 5:
        {
            nrPrime(v,n);
            cout << endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 6:
        {
            cout << "Ultimele cifre a tuturor elementelor din vector sunt:";
            ultimacifra(v,n);
            cout << endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 7:
        {
            cout << "Suma tuturor elementelor din vector este:";
            cout << suma(v,n);
            cout << endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 8:
        {
            cout << "Sortarea elementelor din vector prin interschimbare este urmatoarea:";
            SortarePrinInterschimbare(v,n);
            cout<< endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 9:
        {
            cout << "Sortarea elementelor din vector prin selectarea minimului este urmatoarea:";
            SortarePrinMinim(v,n);
            cout<< endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 10:
        {
            int k;
            cout << "Cititi numarul dorit:";
            cin>>k;
            cout <<pozitia(v,n,k)<< " reprezinta pozitia numarului "<< k << " din vector";
            cout<< endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 11:
        {
            int k;
            cout << "Cititi numarul dorit:";
            cin>>k;
            stergere(v,n,k);
            n=n-1;
            copiere(v,u,n);
            restabilire(v,u,n);
            cout << endl;
            cout << "Asa arata vectorul dupa prelucrare:";
            afisare(v,n);
            cout<< endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 12:
        {
            int k;
            cout << "Cititi numarul dorit:";
            cin>>k;
            div(v,n,k);
            cout<< endl;
            cout<< "Selectati orice alta prelucrare sau tasta 0 pentru a inchide programul:";
            break;
        }
        case 13:
        {
            cout << "Introduceti dimensiunea vectorului: ";
            cin>>n;
            cout << "Cititi vectorul: ";
            citire(v,n);
            cout<< endl;
            cout<< "Selectati o prelucrare:";
            break;
        }
        default:
            {
                cout<<"Va rog alegeti un numar intre 1-13!!"<<endl<<endl;
                cout<<"Selectati o prelucrare:";
                break;
            }
        }
        cin>>x;
    }

    return 0;
}
