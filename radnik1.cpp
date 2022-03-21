/*Ucitati iz datoteke posa0.txt niz struktura tipa radnik ciji elementi su:
firma, ime, prezime, radni staz, plata. Podaci o jednom radniku su smjesteni
u jednoj liniji datoteke. Ispisati na ekranu sve radnike date firme cije prezime
pocinje datim slovom i imaju preko 15 god radnog staza*/
#include<bits/stdc++.h>
using namespace std;
struct radnik{
    string firma, prezime, ime;
    unsigned staz, plata;
};
int main(){
    struct radnik osoba[10];
    ifstream citaj("posa0.txt");
    if(citaj.is_open()){
        int i=0;
        while(!citaj.eof()){
            citaj>>osoba[i].firma>>osoba[i].ime>>osoba[i].prezime>>osoba[i].staz>>osoba[i].plata;
            i++;
        }
        char c;
        cout<<"Unesi slovo: ";
        cin>>c;
        for(int j=0;j<i;j++){
            if(osoba[j].staz>15 && osoba[j].prezime[0]==c)
                cout<<osoba[j].firma<<" "<<osoba[j].ime<<" "<<osoba[j].prezime<<" "<<osoba[j].staz<<" "<<osoba[j].plata<<endl;
        }
        citaj.close();
    }
    else cout<<"Greska";
    return 0;
}
