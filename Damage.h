#pragma once
#include <iostream>
/**
 * \brief damage struct
 *
 * \author radvanszkyI
 *
 * \date 2020.12.10. 9:22
 *
 * \note The damage contain two type of damage: physical and magical.
 */
struct damage
{
    int physical; ///< physical damage: the defense affect it  
    int magical; ///< magical damage: cannot be prevented with defense
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