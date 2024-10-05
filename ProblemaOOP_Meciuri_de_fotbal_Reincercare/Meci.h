//
// Created by Diana on 6/1/2024.
//

#ifndef PROBLEMAOOP_MECIURI_DE_FOTBAL_MECI_H
#define PROBLEMAOOP_MECIURI_DE_FOTBAL_MECI_H
/* Un meci se caracterizează prin numele celor două echipe participante și
 * prin numărul de goluri marcate de către fiecare în cadrul meciului.
 * O echipă primește 3 puncte dacă reușește să câștige un joc, 1 punct dacă scorul
 * a fost unul egal si 0 puncte dacă pierde meciul.
*/

#include<string>
using namespace std;

class Meci {
private:
    string numeE1, numeE2;
    int golE1, golE2;
public:
    Meci();
    ~Meci();
    Meci(string E1, string E2, int gol1, int gol2);
    Meci(const Meci& m);
    string getNumeE1();
    string getNumeE2();
    int getGolE1();
    int getGolE2();
    void setNumeE1(string e1);
    void setNumeE2(string e2);
    void setGolE1(int e1);
    void setGolE2(int e2);
    bool operator==(Meci& m);
    Meci& operator=(const Meci& m);
    friend ostream& operator<<(ostream& os, Meci& m);
};


#endif //PROBLEMAOOP_MECIURI_DE_FOTBAL_MECI_H