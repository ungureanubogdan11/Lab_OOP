// Lab 2 campionat de fotbal
// not tested

#include <iostream>
#include <vector>

enum pozitie {
    PORTAR,
    FUNDAS,
    MIJLOCAS,
    ATACANT
};

class Jucator {
    std::string nume;
    int numarTricou, valoare;
    pozitie rol;

    public: 
    Jucator(const std::string nume, const int numarTricou, const int valoare, pozitie rol) {
        this -> nume = nume;
        this -> numarTricou = numarTricou;
        this -> valoare = valoare;
        this -> rol = rol;
    };
    int getValoare() const {
        
        return this -> valoare;
    }
    pozitie getRol() const {
        return this -> rol;
    }

    ~Jucator() = default;
};

class EchipaFotbal {
    std::string nume, manager;
    std::vector<Jucator> jucatori;
    std::vector<std::string> antrenori;
    int valoare;

    public:
    EchipaFotbal(const std::string nume, const std::string manager, const std::vector<Jucator> jucatori, const std::vector<std::string> antrenori) {
        this -> nume = nume;
        this -> manager = manager;
        this -> jucatori = jucatori;
        this -> antrenori = antrenori;
    };  

    bool validareEchipa(const EchipaFotbal & echipa) {
        int fr[4] = {0};
        for(const Jucator & jucator : this -> jucatori) {
            if(jucator.getRol() == PORTAR) fr[0] = 1;
            if(jucator.getRol() == FUNDAS) fr[1] = 1;
            if(jucator.getRol() == MIJLOCAS) fr[2] = 1;
            if(jucator.getRol() == ATACANT) fr[3] = 1;
        }
        return (fr[0] == 1 && fr[1] == 1 && fr[2] == 1 && fr[3] == 1);
    }

    void calcuaeazaValoare() {
        this -> valoare = 0;
        for(auto jucator : jucatori) {
            this -> valoare += jucator.getValoare();
        }
    }

    void adaugareJucator(const Jucator& j) {
        this -> jucatori.push_back(j);
        calcuaeazaValoare();
    }

    ~EchipaFotbal() = default;
};

class Campionat {
    std::vector<EchipaFotbal> echipe;
    std::vector<std::pair<EchipaFotbal, EchipaFotbal>> meciuri;

    public: 
    Campionat(const std::vector<EchipaFotbal> echipe, std::vector<std::pair<EchipaFotbal, EchipaFotbal>> meciuri) {
        this -> echipe = echipe;
        this -> meciuri = meciuri;
    };

    void AdaugaEchipa(const EchipaFotbal& echipa) {
        this -> echipe.push_back(echipa);
    }

    void simMeci() {
        if(this -> echipe.size() < 2) {return;}
        int e1 = rand() % this -> echipe.size();
        int e2 = e1;
        do {
            e2 = rand() % this -> echipe.size();
        } while(e1 == e2);
        int s1 = rand() % 10;
        int s2 = rand() % 10;
        if(s1 == s2) {std::cout << "Egalitate\n";}
        else if(s1 > s2) {std::cout << "Echipa 1\n";}
        else {std::cout << "Echipa2 \n";}
        this -> meciuri.push_back({this -> echipe[e1], this -> echipe[e2]});
    }

    ~Campionat() = default;

};

int main()
{

}