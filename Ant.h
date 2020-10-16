//
// Created by Christopher Donnelly on 10/12/20.
//

#ifndef CAD605_HW13_ANT_H
#define CAD605_HW13_ANT_H

#include <iostream>
#include "Organism.h"
#include "Grid.h"

class Ant : public Organism
{
    friend class Grid;
public:
    Ant() {};
    Ant(Grid *grid, int row, int column) : Organism(row, column, grid) {}; // invoke base class constructor
    OrganismType get_type();
    void breed();
};


#endif //CAD605_HW13_ANT_H
