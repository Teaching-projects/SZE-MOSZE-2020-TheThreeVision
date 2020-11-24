#pragma once
#include <iostream>
struct damage
{
    int physical; ///< physical damage
    int magical; ///< magical damage
    damage(int physical, int magical):physical(physical),magical(magical){}
    damage operator+(const damage& oth) {
        damage dmgToReturn(this->physical + oth.physical, this->magical + oth.magical);
        return dmgToReturn;
    }

    damage& operator+=(const damage& oth) {
        this->physical += oth.physical;
        this->magical += oth.magical;
        return *this;
    }

    damage& operator*=(const damage& oth) {
        this->physical *= oth.physical;
        this->magical *= oth.magical;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const damage& dmg) {
        out << "Physical: " << dmg.physical << ", Magical: " << dmg.magical;
        return out;
    }
};