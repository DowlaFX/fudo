/*Iz datoteke auta.txt citaj strukturu automobil koja sadrzi marku, boju,
godinu proizvodnje i predjene km. Napisati program koji sadrzi niz struktura
tipa automobil i ispisuje na ekranu podatke o automobilima koji su mladji od
10 god, bijele boje i presli manje od 70.000 km. Automobili trebaju biti sortirani
po predjenim km.*/
#include<bits/stdc++.h>
using namespace std;
struct automobil{
    string marka, boja;
    unsigned god, km;
};
int main(){
    struct automobil car[5], car1[5];
    ifstream citaj("auta.txt");
    if(citaj.is_open()){
        int i=0;
        while(!citaj.eof()){
            citaj>>car[i].marka>>car[i].boja>>car[i].god>>car[i].km;
            i++;
        }
        int n=i, x=0;
        for(int i=0;i<n;i++)
            if(car[i].boja=="bijela" && car[i].km<70000 && 2022-car[i].god<10){
                car1[x]=car[i];
                x++;
            }
        for(int i=0;i<x-1;i++)
            for(int j=1;j<x;j++)
                if(car[i].km>car[j].km)
                    swap(car[i],car[j]);
        for(int i=0;i<x;i++)
            cout<<car[i].marka<<" "<<car[i].boja<<" "<<car[i].god<<" "<<car[i].km<<endl;
        citaj.close();
    }
    else cout<<"Greska";
    return 0;
}
