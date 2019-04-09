#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

struct studentas
{
    string var, pav;
    double gal, med;
};

bool rusiavimas(studentas a, studentas b)
{
    return a.var<b.var;
}

int main()
{
    string var, pav;
    double nd_temp, egz, gal, vid, sum=0, med, viet1, viet2;
    vector <double> nd;
    ifstream stud;
    ofstream rez;
    stud.open("kursiokai.txt");
    rez.open("rezultatai.txt");
    studentas temp;
    vector <studentas> a;
    while(1)
    {
        stud>>var;
        if(var=="Baigiau")
            break;
        stud>>pav;
        while(2)
        {
            stud>>nd_temp;
            if(nd_temp==0)
            break;
            nd.push_back(nd_temp);
        }
        while(3)
        {
        stud>>egz;
        break;
        }
            for(int i=0;i<nd.size();i++)
                sum+=nd[i];
        vid=sum/nd.size();
        sort(nd.begin(),nd.end());
        if(nd.size()%2==0)
        {
            viet1=nd.size()/2-1;
            viet2=nd.size()/2;
            med=(nd[viet1]+nd[viet2])/2;
        }
        else
        {
            viet1=nd.size()/2;
            med=nd[viet1];
        }
        gal=0.4*vid+0.6*egz;
        temp.var=var;
        temp.pav=pav;
        temp.gal=gal;
        temp.med=med;
        a.push_back(temp);
        nd.clear();
        sum=0;
    }
    sort(a.begin(), a.end(), rusiavimas);
    rez<<left<<setw(12)<<"Vardas"<<setw(12)<<"Pavarde"<<setw(15)<<right<<"Galutinis(Vid.)"<<setw(18)<<right<<"Galutinis(Med.)"<<endl;
    rez<<setfill('-')<<setw(57)<<"-"<<endl;
    for(int i=0;i<a.size();i++)
    {
        rez<<setfill(' ')<<left<<setw(12)<<a[i].var<<setw(12)<<a[i].pav<<setw(15)<<right<<a[i].gal<<setw(18)<<right<<a[i].med<<endl;
    }
}
