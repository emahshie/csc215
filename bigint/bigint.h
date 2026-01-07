struct bigint {
    char negative;
    char numdigits;
    char* digits;
};

void set_bigint();
char* get_bigint();
struct bigint add_bigint(struct bigint *num1, struct bigint *num2);
