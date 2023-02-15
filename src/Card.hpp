#pragma once
#include <string>

enum class CardType { Monster, Spell, Trap };

class Card
{
public:
    Card(const std::string& id, CardType type)
        : _id { id }, _type { type }
    {}

    std::string get_id() const
    {
        return _id;
    }

    CardType get_type() const
    {
        return _type;
    }

    std::string get_name() const
    {
        return _name;
    }

    std::string get_description() const
    {
        return _description;
    }

    void set_name(const std::string& name)
    {
        _name = name;
    }

    void set_description(const std::string& description)
    {
        _description = description;
    }

private:
    std::string _id;
    CardType _type;
    std::string _name;
    std::string _description;
};

std::string to_string(CardType cardtype){
    switch(cardtype)
    {
        case CardType::Monster : return "Monster"; break;
        case CardType::Spell : return "Spell"; break;
        case CardType::Trap : return "Trap"; break;
        default : return "";
    }
}
