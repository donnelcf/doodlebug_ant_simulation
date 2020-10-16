//
// Created by Christopher Donnelly on 10/12/20.
//

#include <string>
#include "Organism.h"
#include "Ant.h"

using namespace std;

OrganismType Ant::get_type() {
    return OrganismType::ANT;
}

void Ant::breed() {
    const int BREEDSTEPS = 3;

    breed_steps++;
    if (breed_steps == BREEDSTEPS) {
        if ((column > 0) && (grid->is_empty(row, column - 1))) {
            auto *new_ant = new Ant(grid, row, column - 1);
        } else if ((row < Grid::size - 1) && (grid->is_empty(row + 1, column))) {
            auto *new_ant = new Ant(grid, row + 1, column);
        } else if ((column < Grid::size - 1) && (grid->is_empty(row, column + 1))) {
            auto *new_ant = new Ant(grid, row, column + 1);
        } else if ((row > 0) && (grid->is_empty(row - 1, column))) {
            auto *new_ant = new Ant(grid, row - 1, column);
        }
        breed_steps = 0;
    }
}


