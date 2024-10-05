//
// Created by Diana on 6/1/2024.
//

#ifndef PROBLEMAOOP_MECIURI_DE_FOTBAL_SERVICE_H
#define PROBLEMAOOP_MECIURI_DE_FOTBAL_SERVICE_H


#include "Repo.h"
#include "Meci.h"

class Service {
private:
    Repo<Meci> repo;
public:
    Service() = default;
    ~Service() = default;
    Service( Repo<Meci> &r);
    void add(string n1, string n2, int g1, int g2);
    int punctajMeci(string nume);
    vector<pair<string,int>> clasament();
    vector<Meci> simulareTurneu();
    vector<pair<string ,int>> random();
    vector<pair<string,int>> castigator();
};

#endif //PROBLEMAOOP_MECIURI_DE_FOTBAL_SERVICE_H