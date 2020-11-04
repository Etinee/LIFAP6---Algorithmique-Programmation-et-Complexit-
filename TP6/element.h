//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP6

#ifndef _ELEMENT
#define _ELEMENT

class element{
public:


    bool operator < (element e) const;
    bool operator > (element e) const;
    bool operator == (element e) const;

    int x;
};

#endif