#ifndef OTHERCOMPARISIONOPERATORS_H
#define OTHERCOMPARISIONOPERATORS_H

template <typename T> class OtherComparisionOperators
{
public:

    template <typename Z>
    friend bool operator != (const T& first_type, const Z& second_type)
    {
        return !(first_type == second_type);
    }

    template <typename Z>
    friend bool operator == (const T& first_type, const Z& second_type)
    {
        return !(first_type > second_type) && !(first_type < second_type);
    }

    template <typename Z>
    friend bool operator <= (const T& first_type, const Z& second_type)
    {
        return !(first_type > second_type);
    }

    template <typename Z>
    friend bool operator >= (const T& first_type, const Z& second_type)
    {
        return !(first_type < second_type);
    }
};

#endif // OTHERCOMPARISIONOPERATORS_H
