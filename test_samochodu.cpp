#include <iostream>
#include <string>

using namespace std;

class Samochod {
    private:
        string typ;
        string model;
        int predkosc;
        int rok_produkcji;
        double aktualna_predkosc;
        
    protected:
        void setAktualnaPredkosc(double aktualna_predkosc){
            if((aktualna_predkosc<=0)&& (aktualna_predkosc<=100)) 
                this->aktualna_predkosc=aktualna_predkosc;
        };
    public:
        Samochod(string typ, string model, int rok_produkcji){
            this->model=model;
            this->predkosc=predkosc;
            this->rok_produkcji=rok_produkcji;
            aktualna_predkosc=0;
        
        }
        double getAktualnaPredkosc(){
            return aktualna_predkosc;
        }
        void Przyspieszenie(){
            setAktualnaPredkosc(getAktualnaPredkosc()+10);
        };  
        void Hamowanie(){
            setAktualnaPredkosc(getAktualnaPredkosc()-10);
        }   
    };


class SamochodTest{
    private:
        Samochod* samochod;
    public:
        SamochodTest(){
            samochod = new Samochod("Fiat", "Panda", 2010);
        }
        void SprawdzeniePredkosciMaksymalnej(){
            for(int n= 0; n<200; n++) samochod->Przyspieszenie();

            if((samochod->getAktualnaPredkosc()>200)||(samochod->getAktualnaPredkosc()<0))
            cout << "Predkosc Maksymalna OK!" << endl;
            else
                cout << " Predkosc Maksymalna ERROR!" << endl;
        }
        void SprawdzeniePredkosciMinimalnej(){
            for(int n= 0; n<200; n++) samochod->Hamowanie();

            if((samochod->getAktualnaPredkosc()>200)||(samochod->getAktualnaPredkosc()<0))
            cout << "Predkosc Minimalna OK!" << endl;
            else
                cout << " Predkosc Minimalna ERROR!" << endl;
        }
        ~SamochodTest(){
            delete samochod;
        }

    };
        
    

    int main(){
        SamochodTest samochodTest;
        samochodTest.SprawdzeniePredkosciMaksymalnej();
        samochodTest.SprawdzeniePredkosciMinimalnej();
    
    return 0;
}