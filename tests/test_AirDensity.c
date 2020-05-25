#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/AirDensity.h"


static void test_AirDensity()
{
    assert_float_equal(AirDensity(500.0), 1.1672, 0.005);
}

static void test_AirDensityRatio()
{
    assert_float_equal(AirDensityRatio(500.0), 1.0244, 0.005);
}


int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test_AirDensity),
        cmocka_unit_test(test_AirDensityRatio),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
