//
// Created by Kubak on 17.04.2024.
//

#ifndef BUGS_BOARD_CA2_CRAWLER_H
#define BUGS_BOARD_CA2_CRAWLER_H

#include "../Bug.h"

class Crawler : public Bug
{
public:
    Crawler(int id, std::pair<int, int> position, int direction, int size); // == using Bug::Bug;
    void move();
};


#endif //BUGS_BOARD_CA2_CRAWLER_H