#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct car
{
  int year;
  char model[50];
};
 
static void print_cars(const struct car *cars, size_t n)
{
  int i;
 
  for(i = 0; i < n; i++)
  {
    printf("%4d: %s\n", cars[i].year, cars[i].model);
  }
}
 
static int compar(const void *l, const void *r)
{
  const struct car *left = l;
  const struct car *right = r;
 
  /* sort by model */
  return strcmp(left->model, right->model);
  /* or sort by year */
  return left->year < right->year ? -1 : 1;
}
 
int main (void)
{
  struct car cars[] =
  {
    95, "Toyota",
    200, "Ford",
    2009, "BMW",
    2010, "Mercedes",
    1990, "Delorian"
  };
  size_t n = sizeof cars / sizeof *cars;
 
  puts("Before:");
  print_cars(cars, n);
  qsort(cars, n, sizeof *cars, compar);
  puts("After:");
  print_cars(cars, n);
 
  return 0;
}