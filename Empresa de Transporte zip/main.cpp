#include <iostream>
#include "app.h"
#include "consola.h"
using namespace std;

int main()
{
    initConsola();
    App app;
    app.run();
    return 0;
}
