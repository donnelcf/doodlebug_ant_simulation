//
// Created by Christopher Donnelly on 10/13/20.
//

#ifndef CAD605_HW13_GRID_H
#define CAD605_HW13_GRID_H

#include <iostream>
#include "Organism.h"
#include "OrganismType.h"

class Organism;

class Grid
{
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
public:
    Grid();
    ~Grid();
    static const int size = 20;
    void fill_grid(int ant_count, int doodlebug_count);
    void show_grid();
    void time_step();
    void reset_grid();
    Organism* get_in_position(int row, int column);
    void set_in_position(int row, int column, Organism *organism);
    OrganismType get_type_in_position(int row, int column);
    bool is_empty(int row, int column);
private:
    Organism* grid[size][size];
};

#endif //CAD605_HW13_GRID_H
