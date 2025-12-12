/* Eleanor Mahshie */

int atoi(char *t){
  char *s;
  s = t;
    
  int total;
  total = 0;
  
    while (*s >= '0' && *s <= '9'){
      total = 10 * total + (*s - '0');
      s++;
    }
  return total;
}
