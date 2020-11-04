//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP6

#include "element.h"

bool element::operator<(element e) const {
    return x<e.x;
}

bool element::operator>(element e) const {
    return x>e.x;
}

bool element::operator==(element e) const {
    return x==e.x;
}




