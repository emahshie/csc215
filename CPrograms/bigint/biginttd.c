#include "BIGINT.H"
#include "BDSCTEST.H"

main() {
    START_TESTING("BIGINTTD.C");

    TEST_CASE("Read and write bigint 1234567") {
        struct bigint bi;
        set_bigint("1234567", &bi);
        ASSERT_STR(get_bigint(bi), "1234567");
    }

    TEST_CASE("Add bigints") {
        struct bigint bi1, bi2, bi3;
        set_bigint("157", &bi1);
        set_bigint("218", &bi2);
        add_bigints(&bi1, &bi2, &bi3);
        ASSERT_STR(get_bigint(&bi3), "375");
    }

    TEST_CASE("Subtract bigints") {
        struct bigint bi1, bi2, bi3;
        set_bigint("157", &bi1);
        set_bigint("218", &bi2);
        sub_bigints(&bi1, &bi2, &bi3);
        ASSERT_STR(get_bigint(&bi3), "-61");

        struct bigint bi1, bi2, bi3;
        set_bigint("157", &bi1);
        set_bigint("218", &bi2);
        sub_bigints(&bi2, &bi1, &bi3);
        ASSERT_STR(get_bigint(&bi3), "61");

        struct bigint bi1, bi2, bi3;
        set_bigint("-157", &bi1);
        set_bigint("218", &bi2);
        sub_bigints(&bi1, &bi2, &bi3);
        ASSERT_STR(get_bigint(&bi3), "-375");
    }

    END_TESTING();
}
