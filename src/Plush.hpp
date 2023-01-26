class Plush 
{
public:
    Plush()
    {}

    Plush(int cost) 
        : _cost { cost }
    {}

    int get_cost() const
    {
        return _cost;
    }

    void set_cost(int newCost)
    {
        _cost = newCost;
    }

private:
    int _cost = 10;
};
