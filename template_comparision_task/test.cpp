#include "test.h"
#include "test_runner.h"

#include "first_task.h"

#include "second_task.h"

void Test_first_task()
{
    NewA a1(1, 2);
    NewA a2(2, 3);

    NewB b1(1.5,2.6);

    //cравнения с NewA
    ASSERT (!(a1 >= a2));
    ASSERT (a1 <= a2);
    ASSERT (!(a1 == a2));
    ASSERT (a1 != a2);

    //сравнение с int
    ASSERT (!(a1 >= 4));
    ASSERT (a1 <= 4);
    ASSERT (!(a1 == 4));
    ASSERT (a1 != 4);

    //сравнение с double
    ASSERT (!(a1 >= 4.0));
    ASSERT (a1 <= 4.0);
    ASSERT (!(a1 == 4.0));
    ASSERT (a1 != 4.0);

    //сравнение с double через NewB
    ASSERT (!(b1 >= 4.0));
    ASSERT (b1 <= 4.0);
    ASSERT (!(b1 == 4.0));
    ASSERT (b1 != 4.0);
}

void Test_second_task()
{
    A a1(5, 6);
    B b1 (10, 15);

    //cравнения A c B
    ASSERT (!(a1 >= b1));
    ASSERT (a1 <= b1);
    ASSERT (!(a1 == b1));
    ASSERT (a1 != b1);
}
