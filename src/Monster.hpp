#pragma once
#include "Card.hpp"
#include <string>

enum class Attribute { Dark, Divine, Earth, Fire, Light, Water, Wind };

class Monster : public Card
{
public:
    Monster(const std::string& id, const std::string& name, Attribute attribute, const std::string& monster_type, int atk, int def)
        : Card { id, CardType::Monster } 
        , _attribute { attribute } , _monster_type { monster_type }, _atk { atk }, _def { def }
    {
        set_name(name);
    }

    Attribute get_attribute() const
    {
        return _attribute;
    }

    int get_atk() const
    {
        return _atk;
    }

    int get_def() const
    {
        return _def;
    }

    std::string get_description() const
    {
        return "[" + _monster_type + "]\n" 
        + Card::get_description() + "\nATK/" 
        + std::to_string(_atk) + " DEF/" 
        + std::to_string(_def);
    }

private:
    Attribute _attribute;
    std::string _monster_type;
    int _atk;
    int _def;
};

std::string to_symbol(Attribute attribute)
{
    switch(attribute)
    {
        case Attribute::Dark : return u8"闇"; break;
        case Attribute::Divine : return u8"神"; break;
        case Attribute::Earth : return u8"地"; break;
        case Attribute::Fire : return u8"炎"; break;
        case Attribute::Light : return u8"光"; break;
        case Attribute::Water : return u8"水"; break;
        case Attribute::Wind : return u8"風"; break;
        default : return "";
    }
}
