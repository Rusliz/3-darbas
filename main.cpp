#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct studentas
{
    string var, pav;
    double gal, med;
};

int main()
{
    string var, pav, zodis;
    double nd_temp, egz, gal, vid, sum=0, med, viet1, viet2;
    vector <double> nd;
    studentas temp;
    vector <studentas> a;
    while(1)
    {
        cout<<"Iveskite studento varda (kai baigsite iveskite \"Baigiau\"):"<<endl;
        cin>>var;
        if(var=="Baigiau")
            break;
        cout<<"Iveskite studento pavarde:"<<endl;
        cin>>pav;
        cout<<"Iveskite studento namu darbu pazymius (kai baigsite, iveskite \"0\"):"<<endl;
        while(2)
        {
            cin>>nd_temp;
            if(nd_temp==0)
            break;
            if (nd_temp < 1 || nd_temp > 10)
        {
                cout << "Pazymis turi buti nuo 1 iki 10" << endl;
                continue;
        }
            nd.push_back(nd_temp);
        }
        cout<<"Iveskite egzamino ivertinima:"<<endl;
        while(3)
        {
        cin>>egz;
        if (egz < 1 || egz > 10)
        {
                cout << "Pazymis turi buti nuo 1 iki 10" << endl;
                continue;
        }
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
    cout<<"Jeigu norite rezultatu medianos pavidalu iveskite \"Mediana\", jei galutinio ivertinimo, iveskite \"Galutinis\""<<endl;
    while(4)
    {
        cin>>zodis;
        if (zodis == "Mediana" || zodis == "Galutinis")
            break;
        cout << "Iveskite viena zodi \"Mediana\" arba \"Vidurkis\"" << endl;
    }
    if(zodis=="Mediana")
    {
    cout<<setw(12)<<left<<"Vardas"<<setw(12)<<"Pavarde"<<"Galutinis (Med.)"<<endl;
    cout<<setfill('-')<<setw(40)<<"-"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<setprecision(2)<<setfill(' ')<<left<<setw(12)<<a[i].var<<setw(12)<<a[i].pav<<right<<setw(16)<<a[i].med<<endl;
    }
    }
    else
    {
    cout<<setw(12)<<left<<"Vardas"<<setw(12)<<"Pavarde"<<"Galutinis (Vid.)"<<endl;
    cout<<setfill('-')<<setw(40)<<"-"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<setprecision(2)<<setfill(' ')<<left<<setw(12)<<a[i].var<<setw(12)<<a[i].pav<<setw(16)<<right<<a[i].gal<<endl;
    }
    }
}
