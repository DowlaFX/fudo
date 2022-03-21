/*Ucitati iz datoteke klubovi.txt niz struktura tipa fudbaler
ciji elementi su: ime, prezime, klub, godina rodjenja. Ispisati
na ekranu podatke o najmladjem fudbaleru. Za dati klub ispisati
sve one koji su stariji od 19, a mladji od 23 poredjane po abecedi.*/
#include<bits/stdc++.h>
using namespace std;
struct fudbaler{
    string ime, prezime, klub;
    unsigned god;
};
int main(){
    struct fudbaler f[5], f1[5], najmladji;
    ifstream citaj("klubovi.txt");
    if(citaj.is_open()){
        int i=0, najm=100;
        while(!citaj.eof()){
            citaj>>f[i].ime>>f[i].prezime>>f[i].klub>>f[i].god;
            if(najm>f[i].god){
                najmladji=f[i];
                najm=f[i].god;
            }
            i++;
        }
        cout<<"Najmladji je: "<<najmladji.ime<<" "<<najmladji.prezime<<" "<<najmladji.klub<<" "<<najmladji.god<<endl;
        int n=i, x=0;
        for(int i=0;i<n;i++){
            if(f[i].god>19 && f[i].god<23){
                f1[x]=f[i];
                x++;
            }
        }
        for(int i=0;i<x-1;i++){
            for(int j=1;j<x;j++)
                if(f1[i].ime>f1[j].ime)
                    swap(f1[i],f1[j]);
        }
        for(int i=0;i<x;i++)
            cout<<f1[i].ime<<" "<<f1[i].prezime<<" "<<f1[i].klub<<" "<<f1[i].god<<endl;
        citaj.close();
    }
    else cout<<"Greska";
    return 0;
}
