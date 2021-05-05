#include "dialog.h"

#include <QApplication>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


class AbstractCalisan {
    virtual void ZamAlsinmi()=0;
};
class Calisan:AbstractCalisan{
public:
   string ad;
   string firma;
   int yas;
   Calisan (string Ad,string Firma,int Yas){
       ad=Ad;
       firma=Firma;
       yas=Yas;

   }
   void setAd(string Ad){
       ad=Ad;
   }
   string getAd(){
       return ad;
   }

   void OzellikEkranaYaz(){
      cout <<"Calisanin adi :"<<ad<<endl;
   }

   void ZamAlsinmi(){
       if(yas>3)
           cout<< "Zam orani yuzde 20"<<endl;
       else
           cout << "Zam orani yuzde 10"<<endl;
   }

};
class Yazilimci:Calisan{
public:
    string progLang;
    Yazilimci(string Ad,string Firma,int Yas,string proglang):Calisan(Ad,Firma,Yas){
        progLang=proglang;

    }
};

int main(int argc, char *argv[])
{
    //public , private , protected

   /* Calisan calisan1;
    calisan1.ad="Ali";
    calisan1.firma="MyComp";
    calisan1.yas=35;
    calisan1.OzellikEkranaYaz();*/


    Calisan cls1=Calisan("Ali2","MyComp2",34);
    cls1.OzellikEkranaYaz();
    cls1.setAd("Ahmet");
    string adi=cls1.getAd();
    cout<<adi;
    cls1.ZamAlsinmi();
    Yazilimci y=Yazilimci("m","yazFirma",25,"c++");










    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
