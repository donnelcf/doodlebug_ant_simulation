//
// Created by Christopher Donnelly on 10/12/20.
//

#ifndef CAD605_HW13_DOODLEBUG_H
#define CAD605_HW13_DOODLEBUG_H

#include <iostream>
#include "Organism.h"


class Doodlebug : public Organism
{
    friend class Grid;
public:
    Doodlebug() { starve_steps = 0;};
    Doodlebug(Grid *grid, int row, int column) : Organism(row, column, grid) { starve_steps = 0;}; // invoke base class constructor
    void breed();
    void move();
    bool has_starved();
    OrganismType get_type();
protected:
    int starve_steps;
};


#endif //CAD605_HW13_DOODLEBUG_H
