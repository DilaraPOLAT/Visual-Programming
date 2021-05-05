#include <iostream>

using namespace std;

class Calisan{
public:
    string ad;
    int yas;
    Calisan(string ad,int yas)
    {
        this->ad=ad;
        this->yas=yas;
    }
    void BilgileriYazdir()
    {
        cout << "Ad: "<<ad<<" Yas: "<<yas<<endl;
    }
    virtual void YapilanIs()//virtual ekleyerek bu metot soyut diger classlarla overlied islemi yapilabilir.
    //bir bak bu metot overlied yapilmis olabilir
    {
        cout<<ad<<" mailleri cevaplar ve telefonlara bakar."<<endl;
    }
};

class Yazilimci:public Calisan
{
public:
    string kd;
    Yazilimci(string ad,int yas,string kd)
        :Calisan(ad,yas)
    {
        this->kd=kd;
    }
    void HatayiCoz()
    {
        cout<<ad<<" hatalari "<<kd<<" Kullanarak cozer."<<endl;
    }
    /*void YapilanIs()
    {
        cout<<ad<<" "<<kd<<" dilini kullanarak kodlama yapar"<<endl;
    }*/

};
class Egitmen:public Calisan
{
public:
    string ve;//ve=verilen egitmen
    Egitmen(string ad,int yas,string ve):
      Calisan(ad,yas)
    {
        this->ve=ve;
    }
    void EgitmenHazirlan()
    {
        cout<<ad<<" verecegi "<<ve<<" egitimine hazirlanir. "<<endl;
    }
    void YapilanIs()
    {
        cout<<ad<<" "<<ve<<" egitimini verir."<<endl;
    }
};

int main()
{
    Calisan c = Calisan("Ali",30);
    //c.BilgileriYazdir();
    Yazilimci y=Yazilimci("Ayse",35,"C++");
    //y.HatayiCoz();
   // y.BilgileriYazdir();
    Egitmen e=Egitmen("Seda",28,"ilk yardim");
   // e.EgitmenHazirlan();
   /* c.YapilanIs();
    y.YapilanIs();
    e.YapilanIs();*/
    Calisan *c1=&y; //calisan sinifi y sinifini gosteriyor.
    Calisan *c2=&e;

    c1->YapilanIs();//pointer oldugu icin ok isaretiyle
    c2->YapilanIs();
}











