//
// Created by Christopher Donnelly on 10/12/20.
//

#include <string>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"

using namespace std;

void Doodlebug::move() {
    if ((column > 0) && !(grid->is_empty(row, column - 1)) &&
        (grid->get_type_in_position(row, column - 1) == OrganismType::ANT)) {
        delete (grid->grid[row][column - 1]);
        grid->grid[row][column - 1] = this;
        grid->set_in_position(row, column, nullptr);
        starve_steps = 0;
        column--;
        return;
    } else if ((row < Grid::size - 1) && !(grid->is_empty(row + 1, column)) &&
               (grid->get_type_in_position(row + 1, column) == OrganismType::ANT)) {
        delete (grid->grid[row + 1][column]);
        grid->grid[row + 1][column] = this;
        grid->set_in_position(row, column, nullptr);
        starve_steps = 0;
        row++;
        return;
    } else if ((column < Grid::size - 1) && !(grid->is_empty(row, column + 1)) &&
               (grid->get_type_in_position(row, column + 1) == OrganismType::ANT)) {
        delete (grid->grid[row][column + 1]);
        grid->grid[row][column + 1] = this;
        grid->set_in_position(row, column, nullptr);
        starve_steps = 0;
        column++;
        return;
    } else if ((row > 0) && !(grid->is_empty(row - 1, column)) &&
               (grid->get_type_in_position(row - 1, column) == OrganismType::ANT)) {
        delete (grid->grid[row - 1][column]);
        grid->grid[row - 1][column] = this;
        grid->set_in_position(row, column, nullptr);
        starve_steps = 0;
        row--;
        return;
    }

    starve_steps++;
    if (has_starved()) {
        delete (grid->grid[row][column]);
        grid->grid[row][column] = nullptr;
    } else {
        Organism::move();
    }
}

OrganismType Doodlebug::get_type() {
    return OrganismType::DOODLEBUG;
}

void Doodlebug::breed() {
    const int BREEDSTEPS = 8;
    breed_steps++;

    if (breed_steps == BREEDSTEPS) {
        if ((column > 0) && (grid->is_empty(row, column - 1))) {
            auto *new_doodlebug = new Doodlebug(grid, row, column - 1);
        } else if ((row < Grid::size - 1) && (grid->is_empty(row + 1, column))) {
            auto *new_doodlebug = new Doodlebug(grid, row + 1, column);
        } else if ((column < Grid::size - 1) && (grid->is_empty(row, column + 1))) {
            auto *new_doodlebug = new Doodlebug(grid, row, column + 1);
        } else if ((row > 0) && (grid->is_empty(row - 1, column))) {
            auto *new_doodlebug = new Doodlebug(grid, row - 1, column);
        }
        breed_steps = 0;
    }
}

bool Doodlebug::has_starved() {
    const int STARVESTEPS = 3;

    if (starve_steps > STARVESTEPS) {
        return true;
    } else {
        return false;
    }
}