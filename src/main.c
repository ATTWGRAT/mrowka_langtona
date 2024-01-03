#include <stdio.h>

int main(int argc, char** argv)
{
#ifdef TEST
#include "test.h"
    test();
#endif
    /* Plik ma zawierać jedynie wywołania funkcji potrzebne do odpalenia programu*/
	return 0;
}
