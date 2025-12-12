/* Eleanor Mahshie */

int atoi(char *t){
  char *s;
  s = t;
  int sign;
  sign = 1;
  
  int total;
  total = 0;

  if (*s == '-' || *s == '+'){
    if (*s == '-')
            sign = -1;
        s++;
    }
    
  
    while (*s >= '0' && *s <= '9'){
      total = 10 * total + (*s - '0');
      s++;
    }
  return (sign * total);
}
