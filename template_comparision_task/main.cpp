#include <iostream>

#include "test_runner.h"

#include "first_task.h"
#include "test.h"

#include "second_task.h"

using namespace std;

int main()
{
    TestRunner tr;

    RUN_TEST(tr, Test_first_task);

    RUN_TEST(tr, Test_second_task);

    return 0;
}
