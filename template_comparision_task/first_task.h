#ifndef FIRST_TASK_H
#define FIRST_TASK_H

#include "OtherComparisionOperators.h"


class NewA : public OtherComparisionOperators <NewA>
{
public:
    NewA(int a, int b) : m_a(a), m_b(b){}

    // Операторы сравнения с NewA
    bool operator<(const NewA& other) const
    {
        return (m_a < other.m_a) && (m_b < other.m_b);
    }

    bool operator>(const NewA& other) const
    {
        return (m_a > other.m_a) && (m_b > other.m_b);
    }

    // Операторы сравнения с int
    bool operator<(const int other) const
    {
        return m_a < other;
    }

    bool operator>(const int other) const
    {
        return m_a > other;
    }

    // Операторы сравнения с double
    bool operator<(const double other) const
    {
        return d_a < other;
    }

    bool operator>(const double other) const
    {
        return d_a > other;
    }

private:
    int m_a = 0;
    int m_b = 0;

    double d_a = 0;
    double d_b = 0;
};

class NewB : public OtherComparisionOperators <NewB>
{
public:
    NewB(double a, double b) : d_a(a), d_b(b){}

    // Операторы сравнения с NewB
    bool operator<(const NewB& other) const
    {
        return (d_a < other.d_a) && (d_b < other.d_b);
    }

    bool operator>(const NewB& other) const
    {
        return (d_a > other.d_a) && (d_b > other.d_b);
    }

    // Операторы сравнения с double
    bool operator<(const int other) const
    {
        return d_a < other;
    }

    bool operator>(const int other) const
    {
        return d_a > other;
    }


private:
    double d_a = 0;
    double d_b = 0;
};



#endif // FIRST_TASK_H
