/* Eleanor Mahshie */
char *itoa(int n, int t){
  char *s;
  char sign;

  if (n < 0){
    sign = -1;
    n = -n;
  }
  while ((n /=10) > 0) {
    *s = n % 10 + '0';
    s++;
    }
  if (sign == -1){
    *s = '-';
    s++;
      }
  s = '\0';
  reverse(s);
}
