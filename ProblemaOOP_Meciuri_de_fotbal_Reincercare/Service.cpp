//
// Created by Diana on 6/1/2024.
//

#include <stdexcept>
#include<cstdlib>
#include<map>
using namespace std;
#include "Service.h"
#include<algorithm>

Service::Service( Repo<Meci> &r):repo(r) {
}

void Service::add(string n1, string n2, int g1, int g2) {
    if(g1<0 or g2<0)
        throw invalid_argument("Golul trebuie sa fie un numar pozitiv");
      if(n1==n2)
          throw runtime_error("Echipele trbuie sa fie diferite");
    Meci m(n1,n2,g1,g2);
    repo.addEntity(m);
}

int Service::punctajMeci(string nume) {
    int punctaj = 0;
    vector<Meci> meciuri = repo.getAll();
    for(auto & i : meciuri){
        if(nume == i.getNumeE1()){
            if(i.getGolE1() > i.getGolE2())
                punctaj += 3;
            else if(i.getGolE1() == i.getGolE2() && i.getGolE1() !=0)
                punctaj+=1;
        }
        else if(nume == i.getNumeE2()){
            if(i.getGolE2() > i.getGolE1())
                punctaj += 3;
            else if(i.getGolE2() == i.getGolE1() && i.getGolE2() !=0)
                punctaj+=1;
        }
    }
    return punctaj;
}

vector<pair<string,int>> Service::clasament() {
    vector<Meci> meciuri = repo.getAll();
    map<string, int> echipaPunctaj;
    for( auto& meci : meciuri){
        if(echipaPunctaj.find(meci.getNumeE1()) == echipaPunctaj.end())
            echipaPunctaj[meci.getNumeE1()] = 0;
        if(echipaPunctaj.find(meci.getNumeE2()) == echipaPunctaj.end())
            echipaPunctaj[meci.getNumeE2()] = 0;

        if(meci.getGolE1() > meci.getGolE2()){
            echipaPunctaj[meci.getNumeE1()] += 3;
        } else if(meci.getGolE1() < meci.getGolE2()){
            echipaPunctaj[meci.getNumeE2()] += 3;
        } else if(meci.getGolE1() == meci.getGolE2() && meci.getGolE1() != 0){
            echipaPunctaj[meci.getNumeE1()] += 1;
            echipaPunctaj[meci.getNumeE2()] += 1;
        }
    }
    vector<pair<string, int>> echipeSortate(echipaPunctaj.begin(), echipaPunctaj.end());
    std::sort(echipeSortate.begin(), echipeSortate.end(), [](pair<string, int> &a , pair<string, int>& b){
        return a.second > b.second;
    });
    return echipeSortate;
}

vector<Meci> Service::simulareTurneu() {
    vector<pair<string,int>> echipeGoluri = random();
    vector<Meci> rez;
    for(int i=0;i<echipeGoluri.size()/2;i++){
        Meci save(echipeGoluri[i].first, echipeGoluri[echipeGoluri.size()-i-1].first,
                  echipeGoluri[i].second, echipeGoluri[echipeGoluri.size()-i-1].second);
        rez.push_back(save);
    }
//    if (echipeGoluri.size() % 2 == 1) {
//        rez[rez.size()/2].setNumeE2(rez[rez.size()-1].getNumeE1());
//        rez[rez.size()/2].setGolE2(rez[rez.size()-1].getGolE1());
//    }

    return rez;
}

vector<pair<string, int>> Service::random() {
    vector<Meci> meciuri = repo.getAll();
    map<string, int> echipe;
    for(auto& meci:meciuri){
        if(echipe.find(meci.getNumeE1()) == echipe.end()){
            meci.setGolE1(rand()%6);
            echipe[meci.getNumeE1()] = meci.getGolE1();
        }
        if(echipe.find(meci.getNumeE2()) == echipe.end()){
            meci.setGolE2(rand()%6);
            echipe[meci.getNumeE2()] = meci.getGolE2();
        }
    }
    vector<pair<string,int>> echipeGoluri(echipe.begin(), echipe.end());
    return echipeGoluri;
}

vector<pair<string, int>> Service::castigator() {
    vector<Meci> rez = simulareTurneu();
    int max = 0;
    string winner;
    for(int i=0;i<rez.size();i++){
        if(punctajMeci(rez[i].getNumeE1()) > max){
            max = punctajMeci(rez[i].getNumeE1());
            winner = rez[i].getNumeE1();
        }
        if(punctajMeci(rez[i].getNumeE2()) > max){
            max = punctajMeci(rez[i].getNumeE2());
            winner = rez[i].getNumeE2();
        }
    }
    vector<pair<string, int>> win;
    win[0].first = winner;
    win[0].second = max;
    return win;
}




