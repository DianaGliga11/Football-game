//
// Created by Diana on 6/1/2024.
//

#include <iostream>
#include <map>
#include "UI.h"

UI::UI() {

}

UI::~UI() {

}

UI::UI(Service &se) {
    s = se;
}

void UI::menu() {
    cout<<"\n====MENIU====\n";
    cout<<"1.Adauga meci\n";
    cout<<"2.Clasamentul echipelor\n";
    cout<<"3.Simulare turneu\n";
}

void UI::add() {
    string echipa1, echipa2;
    int gol1, gol2;
    cout<<"Introduceti prima echipa: ";
    cin>>echipa1;
    cout<<"Introduceti a doua echipa: ";
    cin>>echipa2;
    cout<<"Introduceti golurile primei echipe: ";
    cin>>gol1;
    cout<<"Introduceti golurile celei de-a doua echipe: ";
    cin>>gol2;
    try{
        s.add(echipa1,echipa2,gol1,gol2);
        cout<<"Adaugat cu succes\n";
    }
    catch (invalid_argument &ex) {
        cout << "Exceptie: " << ex.what() << endl;
    }
    catch (runtime_error &ex){
        cout << "Exceptie: " << ex.what() << endl;

    }
}

void UI::run() {
    int optiune = 1;
    while(optiune !=0){
        menu();
        cout<<"Introduceti optiune: ";
        cin>>optiune;
        switch (optiune) {
            case 1:
                add();
                break;
            case 2:
                clasament();
                break;
            case 3:
                simulareTurneu();
                break;
            case 0:
                break;
        }
    }
}

void UI::clasament() {
    vector<pair<string, int>> clasamentFinal = s.clasament();
    for(auto &i:clasamentFinal){
        cout<<i.first<<" " << i.second<<endl;
    }

}

void UI::simulareTurneu() {
    vector<Meci> turneu = s.simulareTurneu();
    for(int i=0;i<turneu.size();i++)
        cout<<turneu[i].getNumeE1()<<" vs "<<turneu[i].getNumeE2() << ", scor"<<
        turneu[i].getGolE1()<<"-"<<turneu[i].getGolE2()<<endl;
    vector<pair<string,int>> winner = s.castigator();
    cout<<"Echipa câștigătoare este "<< winner[0].first << " cu punctajul " <<winner[0].second<<endl;
}
