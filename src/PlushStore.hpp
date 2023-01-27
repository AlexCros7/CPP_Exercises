#pragma once
#include <string>
#include <vector>
#include <optional>
#include "Plush.hpp"

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
            _stock++;
            _experience++;
            _wealth -= cost;
            if (_wealth < 0)
            {
                _wealth = 0;
            }
        }
        const auto value = cost + std::max(_experience, _experience * cost / 100);
        _plushStock.emplace_back(value);
        return value;
    }
    
    std::optional<Plush> buy(int money)
    {
        if (_plushStock.empty())
        {
            return std::nullopt;
        }

        else {
            auto min = _plushStock[0];
            auto index = 0;
            if (_plushStock.size() > 1){
                for (auto i = 1u; i < _plushStock.size(); i++)
                {
                    if (_plushStock[i] < min)
                    {
                        min = _plushStock[i];
                        index = i;
                    }
                }
            }
            if (money > min)
            {
                _stock--;
                _wealth += min;
                _plushStock.erase(_plushStock.begin() + index);
                return std::optional<Plush>{min};
            }
            else
            {
                return std::nullopt;
            }
        }
    }

private:
    std::string _name;
    int _wealth = 0;
    int _stock = 0;
    int _debt = 0;
    int _experience = 0;
    std::vector<int> _plushStock;
};
