#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;
template <typename Tip>
class Lista {

  struct Cvor {
     Tip element;
     Cvor *prethodni,*sljedeci;
     Cvor(Tip element, Cvor *prethodni = nullptr, Cvor *sljedeci = nullptr)
     :element(element),prethodni(prethodni),sljedeci(sljedeci) {}
  };

  int broj_elemenata;
  Cvor *glava,*rep;

  public:

  class Const_Iterator {
     protected:
     Cvor *pok;
     public:
     Const_Iterator(Cvor *cvor = nullptr):pok(cvor) {}
     const Tip& operator*() { return pok->element; }
     Const_Iterator operator++(int) { Const_Iterator za_vracanje(*this); pok = pok->sljedeci; return za_vracanje; }
     Const_Iterator& operator++() { pok = pok->sljedeci; return *this; }
     Const_Iterator operator--(int) { Const_Iterator za_vracanje(*this); pok = pok->prethodni; return za_vracanje; }
     Const_Iterator& operator--() { pok = pok->prethodni; return *this; }
     bool friend operator==(Const_Iterator it1, Const_Iterator it2) { return it1.pok == it2.pok;}
     bool friend operator!=(Const_Iterator it1, Const_Iterator it2) { return !(it1==it2); }
     friend class Lista<Tip>;
  };

  class Iterator: public Const_Iterator {
    public:
    Iterator(Cvor *cvor = nullptr) { this->pok = cvor; }
    Tip& operator*() { return this->pok->element; }
    Iterator operator++(int) { Iterator za_vracanje(*this); this->pok = this->pok->sljedeci; return za_vracanje; }
    Iterator& operator++() { this->pok = this->pok->sljedeci; return *this; }
    Iterator operator--(int) { Iterator za_vracanje(*this); this->pok = this->pok->prethodni; return za_vracanje; }
    Iterator& operator--() { this->pok = this->pok->prethodni; return *this; }
  };

  void init();
  Lista() { init(); }
  Lista(int n, Tip vrijednost) { init(); while(n-- != 0) pushBack(vrijednost);}
  Lista(const Lista<Tip> &kopija);
  Lista<Tip>& operator=(const Lista<Tip> &rhs);
  ~Lista();
  Lista(Lista<Tip> &&kopija);
  Lista<Tip>& operator=(Lista<Tip> &&rhs);

  Iterator Insert(Iterator it, Tip vrijednost);
  Iterator pushFront(Tip vrijednost) { return Insert(Begin(),vrijednost); }
  Iterator pushBack(Tip vrijednost) { return Insert(End(),vrijednost); }
  Iterator Erase(Iterator it);
  void PopFront() { Erase(Begin()); }
  void PopBack() { Erase(--End()); }
  Iterator Begin() { return glava->sljedeci; }
  Const_Iterator Begin() const { return glava->sljedeci; }
  Iterator End() { return rep; }
  Const_Iterator End() const { return rep; }
  bool Empty() const { return broj_elemenata==0; }
  void Clear() { while(!Empty()) PopFront(); }
};

#include "lista.cpp"

#endif // LISTA_H
