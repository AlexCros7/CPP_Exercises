#pragma once
#include "Card.hpp"
#include <string>

enum class SpellType { Normal, Equip, Continuous, QuickPlay, Field };

class Spell : public Card
{
public:
    Spell(const std::string& id, const std::string& name, SpellType spellType)
        : Card { id, CardType::Spell }
        , _spellType { spellType }
    {
        set_name(name);
    }

    SpellType get_spell_type() const
    {
        return _spellType;
    }

private:
    SpellType _spellType;
};

std::string to_string(SpellType spellType)
{
   switch(spellType)
    {
        case SpellType::Normal : return "Normal"; break;
        case SpellType::Equip : return "Equip"; break;
        case SpellType::Continuous : return "Continuous"; break;
        case SpellType::QuickPlay : return "Quick-Play"; break;
        case SpellType::Field : return "Field"; break;
        default : return "";
    } 
}