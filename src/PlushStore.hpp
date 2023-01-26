#include <string>

class PlushStore
{
public:
    PlushStore(const std::string& name)
        : _name { name }
    {}

    std::string get_name() const
    {
        return _name;
    }

    int get_wealth_amount() const
    {
        return _wealth;
    }

    int get_stock_size() const
    {
        return _stock;
    }

    int get_debt_amount() const
    {
        return _debt;
    }

    int get_experience() const
    {
        return _experience;
    }

    void loan(int money)
    {
        _wealth += money;
        _debt += money + (money * 10) / 100;
    }

    int make_plush(int cost)
    {
        if (_wealth != 0)
        {
            _stock += 1;
            _experience += 1;
        }
        if (_wealth - cost < 0)
        {
            _wealth = 0;
            return cost - _wealth + std::max(_experience, _experience * cost / 100);
        }
        else
        {
            _wealth -= cost;
            return cost + std::max(_experience, _experience * cost / 100);
        }
    }

private:
    std::string _name;
    int _wealth = 0;
    int _stock = 0;
    int _debt = 0;
    int _experience = 0;
};
