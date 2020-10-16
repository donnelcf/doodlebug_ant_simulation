//
// Created by Christopher Donnelly on 10/13/20.
//

#include <iostream>
#include "Grid.h"
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "OrganismType.h"

using namespace std;

Grid::Grid() {
    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = 0; second_index < size; second_index++) {
            grid[first_index][second_index] = nullptr;
        }
    }
}

Grid::~Grid() {
    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = 0; second_index < size; second_index++) {
            if (!is_empty(first_index, second_index)) {
                delete (grid[first_index][second_index]);
            }
        }
    }
}

Organism *Grid::get_in_position(int row, int column) {
    return grid[row][column];
}

OrganismType Grid::get_type_in_position(int row, int column) {
    return get_in_position(row, column)->get_type();
}

bool Grid::is_empty(int row, int column) {
    return get_in_position(row, column) == nullptr;
}

void Grid::set_in_position(int row, int column, Organism *organism) {
    grid[row][column] = organism;
}

void Grid::fill_grid(int starting_ants, int starting_doodlebugs) {
    int current_ant_count = 0;
    while (current_ant_count < starting_ants) {
        int row = rand() % Grid::size;
        int column = rand() % Grid::size;

        if (is_empty(row, column)) {
            auto *new_ant = new Ant(this, row, column);
            current_ant_count++;
        }
    }

    int current_doodlebug_count = 0;
    while (current_doodlebug_count < starting_doodlebugs) {
        int row = rand() % Grid::size;
        int column = rand() % Grid::size;

        if (is_empty(row, column)) {
            auto *new_doodlebug = new Doodlebug(this, row, column);
            current_doodlebug_count++;
        }
    }
}

void Grid::show_grid() {
    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = 0; second_index < size; second_index++) {
            if (is_empty(first_index, second_index)) {
                cout << '-';
            } else if (grid[first_index][second_index]->get_type() == OrganismType::DOODLEBUG) {
                cout << 'X';
            } else cout << 'o';
        }
        cout << endl;
    }
}

void Grid::reset_grid() {
    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = 0; second_index < size; second_index++) {
            if (!is_empty(first_index, second_index)) {
                grid[first_index][second_index]->has_moved = false;
            }
        }
    }
}

void Grid::time_step() {

    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = 0; second_index < size; second_index++) {
            if (!is_empty(first_index, second_index) &&
                (grid[first_index][second_index]->get_type() == OrganismType::DOODLEBUG) &&
                !(grid[first_index][second_index]->has_moved)) {
                grid[first_index][second_index]->has_moved = true;
                grid[first_index][second_index]->move();
            }
        }
    }

    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = 0; second_index < size; second_index++) {
            if ((!is_empty(first_index, second_index)) &&
                (grid[first_index][second_index]->get_type() == OrganismType::ANT) &&
                !(grid[first_index][second_index]->has_moved)) {
                grid[first_index][second_index]->has_moved = true;
                grid[first_index][second_index]->move();
            }
        }
    }

    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = 0; second_index < size; second_index++) {
            if ((!is_empty(first_index, second_index)) && (grid[first_index][second_index]->has_moved)) {
                grid[first_index][second_index]->breed();
            }
        }
    }

}