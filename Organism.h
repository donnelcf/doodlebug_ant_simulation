//
// Created by Christopher Donnelly on 10/12/20.
//

#ifndef CAD605_HW13_ORGANISM_H
#define CAD605_HW13_ORGANISM_H

#include <iostream>
#include "Grid.h"
#include "OrganismType.h"

class Grid;

class Organism
{
    friend class Grid;
public:
    Organism() : grid(nullptr), row(0), column(0), has_moved(false), breed_steps(0) {};
    Organism(int new_row, int new_column, Grid *new_grid);
    virtual ~Organism() {};
    virtual void move();
    virtual void breed() = 0;
    virtual OrganismType get_type() = 0;
protected:
    int row;
    int column;
    Grid *grid;
    bool has_moved;
    int breed_steps;
};


#endif //CAD605_HW13_ORGANISM_H
