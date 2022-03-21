/*Ucitati iz datoteke mobilni.txt niz struktura tipa osoba ciji elementi su:
ime, prezime, grad, telefon i starost. Ispisati na ekranu punoljetne osobe ciji
broj telefon pocinje sa 065 ili 066 i stanuju u datom gradu. Ako nema takvih
osoba ispisati odgovarajucu poruku.*/
#include<bits/stdc++.h>
using namespace std;
struct osoba{
    string ime, prezime, grad, telefon;
    unsigned starost;
};
int main(){
    struct osoba aa[10];
    ifstream citaj("mobilni.txt");
    if(citaj.is_open()){
        int i=0, br=0;
        while(!citaj.eof()){
            citaj>>aa[i].ime>>aa[i].prezime>>aa[i].grad>>aa[i].telefon>>aa[i].starost;
            i++;
        }
        string gradu;
        cout<<"Unesi grad: ";
        cin>>gradu;
        for(int j=0;j<i;j++)
            if(aa[j].starost>17 && aa[j].grad==gradu &&
            (aa[j].telefon.substr(0,3)=="065" || aa[j].telefon.substr(0,3)=="066")){
                cout<<aa[j].ime<<" "<<aa[j].prezime<<" "<<aa[j].grad<<" "<<aa[j].telefon<<" "<<aa[j].starost<<endl;
                br=1;
            }
        if(br==0)
            cout<<"Nema takvih podataka!";
        citaj.close();
    }
    else cout<<"Greska";
    return 0;
}
