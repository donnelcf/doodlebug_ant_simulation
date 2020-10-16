//
// Created by Christopher Donnelly on 10/12/20.
//

#include <iostream>
#include "Organism.h"

using namespace std;

Organism::Organism(int new_row, int new_column, Grid *new_grid) {
    grid = new_grid;
    row = new_row;
    column = new_column;
    has_moved = false;
    breed_steps = 0;

    grid->set_in_position(row, column, this);
}

void Organism::move() {
    int move_direction = rand() % 3;
    switch (move_direction) {
        case 0:
            if ((column > 0) && (grid->is_empty(row, column - 1))) {
                grid->set_in_position(row, column - 1, grid->get_in_position(row, column));
                grid->set_in_position(row, column, nullptr);
                column--;
            }
        case 1:
            if ((row < Grid::size - 1) && (grid->is_empty(row + 1, column))) {
                grid->set_in_position(row + 1, column, grid->get_in_position(row, column));
                grid->set_in_position(row, column, nullptr);
                row++;
            }
        case 2:
            if ((column < Grid::size - 1) && (grid->is_empty(row, column + 1))) {
                grid->set_in_position(row, column + 1, grid->get_in_position(row, column));
                grid->set_in_position(row, column, nullptr);
                column++;
            }
        default:
            if ((row > 0) && (grid->is_empty(row - 1, column))) {
                grid->set_in_position(row - 1, column, grid->get_in_position(row, column));
                grid->set_in_position(row, column, nullptr);
                row--;
            }
    }
}