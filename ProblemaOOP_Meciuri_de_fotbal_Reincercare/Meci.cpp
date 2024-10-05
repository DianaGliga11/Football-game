//
// Created by Diana on 6/1/2024.
//

#include <iostream>
#include "Meci.h"

Meci::Meci(): numeE1(""), numeE2(""), golE1(0), golE2(0) {}

Meci::~Meci() {
    numeE1 = "";
    numeE2 = "";
    golE1 = 0;
    golE2 = 0;
}

Meci::Meci(string E1, string E2, int gol1, int gol2): numeE1(E1), numeE2(E2),
                                                      golE1(gol1), golE2(gol2){}

Meci::Meci(const Meci &m):numeE1(m.numeE1), numeE2(m.numeE2), golE1(m.golE1),
                          golE2(m.golE2){}

string Meci::getNumeE1() {
    return numeE1;
}

string Meci::getNumeE2() {
    return numeE2;
}

int Meci::getGolE1() {
    return golE1;
}

int Meci::getGolE2() {
    return golE2;
}

void Meci::setNumeE1(string e1) {
    numeE1 = e1;
}

void Meci::setNumeE2(string e2) {
    numeE2 =e2;
}

void Meci::setGolE1(int e1) {
    golE1 = e1;
}

void Meci::setGolE2(int e2) {
    golE2 = e2;
}

bool Meci::operator==(Meci &m) {
    return ((numeE1 == m.numeE1) && (numeE2 == m.numeE2) && (golE1 == m.golE1) &&
            (golE2 == m.golE2));
}

Meci &Meci::operator=(const Meci &m) {
    if(this == &m)
        return *this;
    numeE1 = m.numeE1;
    numeE2 = m.numeE2;
    golE1 = m.golE1;
    golE2 = m.golE2;
    return *this;
}

ostream &operator<<(ostream &os, Meci &m) {
    os<<m.numeE1<<" vs "<<m.numeE2<<", scor: "<<m.golE1<<"-"<<m.golE2<<endl;
    return os;
}