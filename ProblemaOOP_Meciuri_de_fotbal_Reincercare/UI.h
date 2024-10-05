//
// Created by Diana on 6/1/2024.
//

#ifndef PROBLEMAOOP_MECIURI_DE_FOTBAL_REINCERCARE_UI_H
#define PROBLEMAOOP_MECIURI_DE_FOTBAL_REINCERCARE_UI_H


#include "Service.h"

class UI {
private:
    Service s;
public:
    UI();
    ~UI();
    UI(Service& se);
    void menu();
    void add();
    void run();
    void clasament();
    void simulareTurneu();
};


#endif //PROBLEMAOOP_MECIURI_DE_FOTBAL_REINCERCARE_UI_H
