/*#include <bits/stdc++.h>
#include "realni_1.h"

using namespace std;

Realni::Realni(double broj){
int a=broj;
while (true)
{
    int b=a%10;
    a=a/10;
    Prije.pushFront(b);
    if (a<1) break;
}

int c=broj;
double trenutni=broj-c;

while (true)
{


    int b=trenutni*10;
    Poslije.pushBack(b);
    trenutni=trenutni*10-b;
    if (trenutni==0) break;

}
}







Realni::Realni(string broj){

string prije_zareza='';
string poslije_zareza='';
int brojac_tacke;
try{
for(int i=0; i<broj.size();i++){
    if (broj[i]=='.') brojac_tacke++;
    if(broj[i]!='0' || broj[i]!='1' || broj[i]!='2' || broj[i]!='3' ||
       broj[i]!='4' || broj[i]!='5' || broj[i]!='6' || broj[i]!='7' ||
       broj[i]!='8' || broj[i]!='9' || brojac_tacke>1) throw(0);

}


int a=broj.size();
bool je_li_bio_zarez=false;

for (int i=0; i<a; i++){
    if (broj[i]=='.' && je_li_bio_zarez==false) {
        je_li_bio_zarez=true;
        i++;
    }
    if(!je_li_bio_zarez)poslije_zareza+=broj[i];
    if(je_li_bio_zarez)prije_zareza+=broj[i];
}

for (int i=0; i<(prije_zareza.size()); i++){
    Prije.pushFront(prije_zareza-'0');

}
for (int i=0; i<(poslije_zareza.size()); i++){
    Poslije.pushFront(poslije_zareza-'0');

}
}

catch(...){cout<<"nije broj";}}




















Realni operator+ (const Realni& lhs, const Realni& rhs){

Realni Rezultat(0);

int broj_elemenatta_iza_zareza_lhs = 0;
int broj_elemenatta_iza_zareza_rhs = 0;

Lista<int>::Iterator trenutni = lhs.Poslije.Begin();

while (trenutni != lhs.Poslije.End()){

    broj_elemenatta_iza_zareza_lhs ++;
    trenutni ++;
}



trenutni = rhs.Poslije.Begin();

while (trenutni != rhs.Poslije.End()){

    broj_elemenatta_iza_zareza_rhs ++;
    trenutni ++;
}

if(broj_elemenatta_iza_zareza_lhs>broj_elemenatta_iza_zareza_rhs){

    for (int i=0; i<(broj_elemenatta_iza_zareza_lhs-broj_elemenatta_iza_zareza_rhs,); i++){
        rhs.Poslije.pushFront(0);
    }

}
else if(broj_elemenatta_iza_zareza_lhs<broj_elemenatta_iza_zareza_rhs){

    for (int i=0; i<(broj_elemenatta_iza_zareza_rhs-broj_elemenatta_iza_zareza_lhs), i++){
        lhs.Poslije.pushFront(0);
    }


}

bool ima_li_prenosa=false;

Lista<int>:: Iterator trenutni_lhs = lhs.Poslije.Begin();

Lista<int>:: Iterator trenutni_rhs =rhs.Poslije.Begin();

while(true){


    Rezultat.Poslije.pushBack((*trenutni_lhs + *trenutni_rhs + ima_li_prenosa)%10);
    if (ima_li_prenosa) ima_li_prenosa=false;
    if((*trenutni_lhs + *trenutni_rhs + ima_li_prenosa )>9) ima_li_prenosa=true;
    trenutni_lhs ++;
    trenutni_rhs ++;
    if(trenutni_lhs == lhs.Poslije.End()) break;






}
}

Realni operator- ( Realni& lhs, Realni& rhs){

Realni Rezultat(0);

int broj_elemenatta_iza_zareza_lhs = 0;
int broj_elemenatta_iza_zareza_rhs = 0;

Lista<int>::Iterator trenutni = lhs.Poslije.Begin();

while (trenutni != lhs.Poslije.End()){

    broj_elemenatta_iza_zareza_lhs ++;
    trenutni ++;
}



trenutni = rhs.Poslije.Begin();

while (trenutni != rhs.Poslije.End()){

    broj_elemenatta_iza_zareza_rhs ++;
    trenutni ++;
}


bool oduzmi_lhs_od_rhs=true;
if (broj_elemenatta_iza_zareza_rhs>broj_elemenatta_iza_zareza_lhs) oduzmi_lhs_od_rhs=false;



if(broj_elemenatta_iza_zareza_lhs>broj_elemenatta_iza_zareza_rhs){

    for (int i=0; i<(broj_elemenatta_iza_zareza_lhs-broj_elemenatta_iza_zareza_rhs,); i++){
        rhs.Poslije.pushFront(0);
    }

}
else if(broj_elemenatta_iza_zareza_lhs<broj_elemenatta_iza_zareza_rhs){

    for (int i=0; i<(broj_elemenatta_iza_zareza_rhs-broj_elemenatta_iza_zareza_lhs), i++){
        lhs.Poslije.pushFront(0);
    }


}

bool ima_li_prenosa=false;

Lista<int>:: Iterator trenutni_lhs = lhs.Poslije.Begin();

Lista<int>:: Iterator trenutni_rhs =rhs.Poslije.Begin();

while(true){

    Rezultat.Poslije.pushBack((*trenutni_lhs - *trenutni_rhs - ima_li_prenosa)%10);
    if (ima_li_prenosa) ima_li_prenosa=false;
    if((*trenutni_lhs - *trenutni_rhs - ima_li_prenosa )<0) ima_li_prenosa=true;
    trenutni_lhs ++;
    trenutni_rhs ++;
    if(trenutni_lhs == lhs.Poslije.End()) break;

}
*/
