#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"

using namespace std;

int main() {
    int starting_ants, starting_doodlebugs;
    Grid grid;

    cout << "Enter the starting number of ants: " << endl;
    cin >> starting_ants;
    cout << "Enter the starting number of doodlebugs: " << endl;
    cin >> starting_doodlebugs;

    srand(time(nullptr));
    grid.fill_grid(starting_ants, starting_doodlebugs);

    for(;;) {
        grid.show_grid();
        grid.time_step();
        grid.reset_grid();

        cout << endl;
        cout << "Please press enter to move to the next step:" << endl;
        cin.ignore();
    }

    return 0;
}