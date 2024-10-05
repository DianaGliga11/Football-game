#include <iostream>
#include "Repo.h"
#include "Meci.h"
#include "Service.h"
#include "UI.h"

int main() {
    Repo<Meci> r;
    Service s(r);
    UI ui(s);
    ui.run();
    return 0;
}
