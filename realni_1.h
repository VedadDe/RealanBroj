#ifndef REALNI_INCLUDED
#define REALNI_INCLUDED

#include <bits/stdc++.h>
#include "lista.h"

class Realni {
public:
    Realni(double broj);
    Realni(string broj);

    // Realni& operator+= (Realni& rhs);
    // Realni& operator-= (Realni& rhs);
    // Realni& operator*= (Realni& rhs);
    Realni& operator-()
    {
        Realni Rezultat;
        Rezultat.Prije = Prije;
        Rezultat.Poslije = Poslije;
        Rezultat.je_li_pozitivan = !je_li_pozitivan;
        return Rezultat;
    }

    //  Realni& operator*= (const int& scaleFactor);
    friend Realni operator+(Realni& lhs, Realni& rhs);
    friend Realni operator*(Realni& lhs, Realni& rhs);
    friend Realni operator-(Realni& lhs, Realni& rhs);
    friend Realni operator^(Realni& lhs, int a);
    friend ostream& operator<<(ostream& out, Realni& Rezultat);
    friend istream& operator >>(istream& in, Realni& Rezultat);

private:
    Lista<int> Prije;
    Lista<int> Poslije;
    bool je_li_pozitivan;

    Realni() {}
};

Realni::Realni(double broj)
{
    if (broj >= 0)
        je_li_pozitivan = true;
    else
        je_li_pozitivan = false;

    int a = broj;
    while (true) {
        int b = a % 10;
        a = a / 10;
        Prije.pushBack(b);
        if (a < 1)
            break;
    }

    int c = broj;
    double trenutni = broj - c;
    if (trenutni == 0)
        return;
    while (true) {
        int b = trenutni * 10;
        Poslije.pushFront(b);
        trenutni = trenutni * 10 - b;
        if (trenutni == 0)
            break;
    }
}

Realni::Realni(string broj)
{
    string prije_zareza = "";
    string poslije_zareza = "";
    int brojac_tacke = 0;
    for (int i = 0; i < broj.size(); i++) {
        if (broj[i] == '.')
            brojac_tacke++;
        else if (broj[i] < '0' || broj[i] > '9' || brojac_tacke > 1)
            throw("");
    }

    int a = broj.size();
    bool je_li_bio_zarez = false;

    for (int i = 0; i < a; i++) {
        if (broj[i] == '.' && je_li_bio_zarez == false) {
            je_li_bio_zarez = true;
            i++;
        }
        if (!je_li_bio_zarez)
            prije_zareza += broj[i];
        if (je_li_bio_zarez)
            poslije_zareza += broj[i];
    }

    for (int i = 0; i < (prije_zareza.size()); i++) {
        Prije.pushFront(prije_zareza[i] - '0');
    }
    for (int i = 0; i < (poslije_zareza.size()); i++) {
        Poslije.pushFront(poslije_zareza[i] - '0');
    }
}

/*Realni::Realni& operator-= ( Realni& rhs){
    *this=*this-rhs;
    return *this;
  }

Realni:: Realni& operator+= ( Realni& rhs){
    *this=*this+rhs;
    return *this;
  }
Realni:: Realni& operator*= ( Realni& rhs){
    *this=*this*rhs;
    return *this;
  }     */

ostream& operator<<(ostream& out, Realni& Rezultat)
{
    /// if (!je_li_pozitivan) out<<'-';
    for (auto it = Rezultat.Prije.End(); it != Rezultat.Prije.Begin();) {
        it--;
        out << *it;
    }

    out << '.';

    for (auto it1 = Rezultat.Poslije.End(); it1 != Rezultat.Poslije.Begin();) {
        it1--;
        out << *it1;
    }
    return out;
}


//error: ISO C++ forbids comparison between pointer and integer [-fpermissive]| za >>
/*
istream& operator >>(istream& in, Realni& upisi)
{
    //Realni upisi;

        while(in.peek()==' ')
            in.get();

        if(in.peek() == '-')
        {
            upisi.je_li_pozitivan = false;
            in.get();
        }

        while(in.peek() != '.' || in.peek() != '\n' || in.peek() != ' ')
        {
            if (in.peek() < '0' || in.peek() > '9')
                return in;
            upisi.Prije.pushBack(in.get() - '0');
        }

        if (in.peek() == '.')
        {
            in.get();
            while(in.peek() != '\n' || in.peek() != " ")
            {
                //cout << char(tok.peek()) << endl;
                if (in.peek() < '0' || in.peek() > '9')
                    return in;
                upisi.Poslije.pushBack(in.get() - '0');
            }
        }

        return in;
     }

/*
Realni stepenuj(Realni prvi, int drugi)
{
    Realni trenutni;
    if(drugi == 0)
        return 1;
    trenutni = stepenuj(prvi, drugi / 2);
    if (drugi.Poslije.PopBack() % 2 == 0)
        return trenutni * trenutni;
    else
    {
        if(drugi > 0)
            return prvi * trenutni * trenutni;
        else
            return (trenutni * trenutni)* stepenuj(prvi,-1);  //ili / prvi;
    }
}

int izjednaci(string &a, string &b)
{
    int d1 = a.size();
    int d2 = b.size();
    if (d1 < d2)
    {
        for (int i = 0 ; i < d2 - d1 ; i++)
            a = '0' + a;
        return d2;
    }
    else if (d1 > d2)
    {
        for (int i = 0 ; i < d1 - d2 ; i++)
            b = '0' + b;
    }
    return d1;
}

int mnozi_bazni(string a, string b){
    return (a[0] - '0')*(b[0] - '0');  }


long int mnozi(string X, string Y)
{
    int n = izjednaci(X,Y);

    if (n == 0) return 0;
    if (n == 1) return mnozi_bazni(X, Y);

    int fh = n/2;
    int sh = (n-fh);


    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    long int P1 = mnozi(Xl, Yl);
    long int P2 = mnozi(Xr, Yr);
    long int P3 = mnozi(dodaj_stringove_po_bitima(Xl, Xr),
dodaj_stringove_po_bitima(Yl, Yr));

    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;

}

string uBinarni(int n)
{

    string vrati="";

    int i = 0;
    while (n > 0) {


        vrati[i] = n % 2;
        n = n / 2;
        i++;
    }
    return vrati;
    }

string dodaj_stringove_po_bitima( string prvi, string drugi )
{
    string rezultat;
    int duzina = prvi.size();
    int carry = 0;

    for (int i = duzina-1 ; i >= 0 ; i--)
    {
        int prvi_bit = prvi.at(i) - '0';
        int drugi_bit = drugi.at(i) - '0';
        int suma = (prvi_bit ^ drugi_bit ^ carry)+'0';
        rezultat = (char)suma + rezultat;
        carry = (prvi_bit&drugi_bit) | (drugi_bit&carry) | (prvi_bit&carry);
    }
    if (carry)  rezultat = '1' + rezultat;
    return rezultat;}




Realni operator* (Realni& lhs, Realni& rhs){
    if ((!rhs.je_li_pozitivan && !lhs.je_li_pozitivan) || (rhs.je_li_pozitivan
&& lhs.je_li_pozitivan))   return lhs*rhs;

    if ((!rhs.je_li_pozitivan && lhs.je_li_pozitivan) || (rhs.je_li_pozitivan &&
!lhs.je_li_pozitivan))   return -(lhs*rhs);

    Realni Rezultat;
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
        for (int i=0;
i<(broj_elemenatta_iza_zareza_lhs-broj_elemenatta_iza_zareza_rhs); i++){
            rhs.Poslije.pushFront(0);
        }
    }
    else if(broj_elemenatta_iza_zareza_lhs<broj_elemenatta_iza_zareza_rhs){
        for (int i=0;
i<(broj_elemenatta_iza_zareza_rhs-broj_elemenatta_iza_zareza_lhs); i++){
            lhs.Poslije.pushFront(0);
        }
    }


//    cout<<lhs<<endl;
//    cout<<rhs<<endl;
    int broj_elemenatta_iza_zareza = broj_elemenatta_iza_zareza_lhs +
broj_elemenatta_iza_zareza_rhs;


    //Lista<int>:: Iterator trenutni_lhs = lhs.Poslije.Begin();

    //Lista<int>:: Iterator trenutni_rhs = rhs.Poslije.Begin();
    // pretvori u string
    string broj_lhs, broj_rhs;
    broj_rhs="";
    broj_lhs="";
    //uraimo prvo izazareza tj dodajmo cifre iza zareza na string
    for(auto it = lhs.Poslije.Begin();it!=lhs.Poslije.End();){
        broj_lhs = broj_lhs + uBinarni(to_string(*it));
        it++;
    }
    for(auto it = lhs.Prije.Begin();it!=lhs.Prije.End();){
        broj_rhs = broj_rhs + uBinarni(to_string(*it));
        it ++;
    }
     for(auto it = rhs.Poslije.Begin();it!=rhs.Poslije.End();){
        broj_rhs = broj_rhs + uBinarni(to_string(*it));
        it ++;
    }
    for(auto it = rhs.Prije.Begin();it!=rhs.Prije.End();){
        broj_rhs = broj_rhs + uBinarni(to_string(*it));
        it ++;
    }
//    int duzina1 = broj_lhs.size();
  //  int duzina2 = broj_rhs.size();
    long int broj_rezultat (broj_lhs, broj_rhs);

    Realni Rezultat_mnozenja;

    for (int i=0; i<broj_elemenatta_iza_zareza; i++ ){
        Rezultat_mnozenja.Prije.pushBack(broj_rezultat%10);
        broj_rezultat=broj_rezultat/10;
    }
    while (broj_rezultat>1){
        Rezultat_mnozenja.Poslije.pushBack(broj_rezultat%10);
        broj_rezultat=broj_rezultat/10;
    }


return Rezultat_mnozenja;
}  */

Realni operator+(Realni& lhs, Realni& rhs)
{
    /*if (!rhs.je_li_pozitivan && lhs.je_li_pozitivan)
        return lhs - rhs;

    if (!lhs.je_li_pozitivan && rhs.je_li_pozitivan)
        return lhs - rhs;

    if (!rhs.je_li_pozitivan && !lhs.je_li_pozitivan)
        return -(lhs + rhs);*/

    Realni Rezultat;
    int broj_elemenatta_iza_zareza_lhs = 0;
    int broj_elemenatta_iza_zareza_rhs = 0;
    Lista<int>::Iterator trenutni = lhs.Poslije.Begin();
    while (trenutni != lhs.Poslije.End()) {
        broj_elemenatta_iza_zareza_lhs++;
        trenutni++;
    }
    trenutni = rhs.Poslije.Begin();
    while (trenutni != rhs.Poslije.End()) {
        broj_elemenatta_iza_zareza_rhs++;
        trenutni++;
    }
    if (broj_elemenatta_iza_zareza_lhs > broj_elemenatta_iza_zareza_rhs) {
        for (int i = 0;
             i < (broj_elemenatta_iza_zareza_lhs - broj_elemenatta_iza_zareza_rhs);
             i++) {
            rhs.Poslije.pushFront(0);
        }
    }
    else if (broj_elemenatta_iza_zareza_lhs < broj_elemenatta_iza_zareza_rhs) {
        for (int i = 0;
             i < (broj_elemenatta_iza_zareza_rhs - broj_elemenatta_iza_zareza_lhs);
             i++) {
            lhs.Poslije.pushFront(0);
        }
    }
    cout << lhs << endl;
    cout << rhs << endl;
    bool ima_li_prenosa = false;

    Lista<int>::Iterator trenutni_lhs = lhs.Poslije.Begin();

    Lista<int>::Iterator trenutni_rhs = rhs.Poslije.Begin();
    while (true) {
        Rezultat.Poslije.pushBack((*trenutni_lhs + *trenutni_rhs + ima_li_prenosa) % 10);
        if (ima_li_prenosa)
            ima_li_prenosa = false;
        if ((*trenutni_lhs + *trenutni_rhs + ima_li_prenosa) > 9)
            ima_li_prenosa = true;
        trenutni_lhs++;
        trenutni_rhs++;
        if (trenutni_lhs == lhs.Poslije.End())
            break;
    }

    trenutni_lhs = lhs.Prije.Begin();
    trenutni_rhs = rhs.Prije.Begin();
    while (true) {
        Rezultat.Prije.pushBack((*trenutni_lhs + *trenutni_rhs + ima_li_prenosa) % 10);
        if (ima_li_prenosa)
            ima_li_prenosa = false;
        if ((*trenutni_lhs + *trenutni_rhs + ima_li_prenosa) > 9)
            ima_li_prenosa = true;
        trenutni_lhs++;
        trenutni_rhs++;
        if (trenutni_lhs == lhs.Prije.End())
            break;
    }
    return Rezultat;
}

/*Realni operator^ (Realni& lhs, int a){
    return stepenuj(lhs, a);


}


bool VeciPoApsolutnoj(Realni& rhs, Realni& lhs){

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

        if (broj_elemenatta_iza_zareza_rhs>broj_elemenatta_iza_zareza_lhs)
return false;

        if (broj_elemenatta_iza_zareza_rhs<broj_elemenatta_iza_zareza_lhs)
return true;

        auto it_rhs=rhs.Prije.End()-1;
        auto it_lhs=lhs.Prije.End()-1;

        while (it_lhs != lhs.Prije.Begin()-1){
            if(it_lhs>it_rhs) return true;
            if(it_lhs<it_rhs) return false;

            it_lhs --;
            it_rhs --;

        }
        it_rhs=rhs.Poslije.End()-1;
        it_lhs=lhs.Poslije.End()-1;

        while(it_lhs != lhs.Poslije.Begin()-1 && it_rhs !=
rhs.Poslije.Begin()-1){
            if(it_lhs>it_rhs) return true;
            if(it_lhs<it_rhs) return false;

            it_lhs --;
            it_rhs --;


        }

        ///if(it_lhs != lhs.Poslije.End()) return true;
        return false;
}


  */

Realni operator-(Realni& lhs, Realni& rhs)
{
    if (!rhs.je_li_pozitivan)
        return lhs + rhs;

    if (!lhs.je_li_pozitivan)
        return -(lhs + rhs);

    Realni Rezultat;

    int broj_elemenatta_iza_zareza_lhs = 0;
    int broj_elemenatta_iza_zareza_rhs = 0;

    Lista<int>::Iterator trenutni = lhs.Poslije.Begin();

    while (trenutni != lhs.Poslije.End()) {
        broj_elemenatta_iza_zareza_lhs++;
        trenutni++;
    }

    trenutni = rhs.Poslije.Begin();

    while (trenutni != rhs.Poslije.End()) {
        broj_elemenatta_iza_zareza_rhs++;
        trenutni++;
    }

    if (broj_elemenatta_iza_zareza_lhs > broj_elemenatta_iza_zareza_rhs) {
        for (int i = 0;
             i < (broj_elemenatta_iza_zareza_lhs - broj_elemenatta_iza_zareza_rhs);
             i++) {
            rhs.Poslije.pushFront(0);
        }
    }
    else if (broj_elemenatta_iza_zareza_lhs < broj_elemenatta_iza_zareza_rhs) {
        for (int i = 0;
             i < (broj_elemenatta_iza_zareza_rhs - broj_elemenatta_iza_zareza_lhs);
             i++) {
            lhs.Poslije.pushFront(0);
        }
    }
    cout << " " << rhs << endl;
    cout << '-' << endl;
    cout << " " << lhs << endl;
    bool ima_li_prenosa = false;

    Lista<int>::Iterator trenutni_veci = lhs.Poslije.Begin();

    Lista<int>::Iterator trenutni_manji = rhs.Poslije.Begin();

    if (lhs.je_li_pozitivan && rhs.je_li_pozitivan)
        Rezultat.je_li_pozitivan = true;
    else
        Rezultat.je_li_pozitivan = false;

    // napomena: dvije linije ispod - postavljanje trenutnog najmanjeg i najveceg
    // ne mora da vrijedi ovako. Ovo je samo uzeto radi testa i prikaza
    // funkcionalnisti koda. Ispravno uzimanje veceg i manjeg sa mogucim obrtanjem
    // se nalazi u komentaru ispod ali zbog pojave greske u fji VeciPoApsolutnoj
    // ovaj dio dovodi do greske u kompajliranju.

    trenutni_veci = rhs.Poslije.Begin();
    trenutni_manji = lhs.Poslije.Begin();

    /* if (!VeciPoApsolutnoj(lhs, rhs)){
      trenutni_veci = rhs.Poslije.Begin();
      trenutni_manji = lhs.Poslije.Begin();

      if (lhs.je_li_pozitivan && rhs.je_li_pozitivan )
  Rezultat.je_li_pozitivan=false;
      else Rezultat.je_li_pozitivan=true;
  }*/

    while (true) {
        Rezultat.Poslije.pushBack(
            (*trenutni_veci - *trenutni_manji - ima_li_prenosa + 10) % 10);
        if (ima_li_prenosa)
            ima_li_prenosa = false;
        if ((*trenutni_veci - *trenutni_manji - ima_li_prenosa) < 0)
            ima_li_prenosa = true;
        trenutni_veci++;
        trenutni_manji++;
        if (trenutni_veci == lhs.Poslije.End() || trenutni_veci == rhs.Poslije.End())
            break;
    }
    trenutni_veci = rhs.Prije.Begin();
    trenutni_manji = lhs.Prije.Begin();
    while (true) {
        Rezultat.Prije.pushBack(
            (*trenutni_veci - *trenutni_manji - ima_li_prenosa + 10) % 10);
        if (ima_li_prenosa)
            ima_li_prenosa = false;
        if ((*trenutni_veci - *trenutni_manji - ima_li_prenosa) < 0)
            ima_li_prenosa = true;
        trenutni_veci++;
        trenutni_manji++;
        if (trenutni_veci == lhs.Prije.End() || trenutni_veci == rhs.Prije.End())
            break;
    }
    return Rezultat;
}
#endif
