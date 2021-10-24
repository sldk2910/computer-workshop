#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <math.h>

int main()
{
   setlocale(LC_ALL, "Russian");
   srand((unsigned int)time(NULL));

   return 0;
}
