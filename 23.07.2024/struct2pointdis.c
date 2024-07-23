#include <stdio.h>
#include <math.h>
struct Dis {
  int feet;
  float inches;
};
struct Dis distance(int x1, int y1, int x2, int y2) {
  struct Dis d;
  d.inches = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  d.feet = d.inches / 12;
  d.inches = d.inches - d.feet * 12;
  return d;
}
int main() {
  int x1, y1, x2, y2;
  printf("Enter x1: ");
  scanf("%d", &x1);
  printf("Enter y1: ");
  scanf("%d", &y1);
  printf("Enter x2: ");
  scanf("%d", &x2);
  printf("Enter y2: ");
  scanf("%d", &y2);
  struct Dis d = distance(x1, y1, x2, y2);
  printf("The distance between the points is %d feet and %.2f inches\n", d.feet, d.inches);
  return 0;
}

