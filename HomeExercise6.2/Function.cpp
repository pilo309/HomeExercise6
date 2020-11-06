#include "Header.h" 

void tipsLotto(void)
{

	int Lotto[SIZE];

	srand(time(0)); //g�r de tilf�ldige tal HELT tilf�ldige

	int a = 1;		//min random v�rdi
	int b = 36;		//max random v�rdi

	for (size_t i = 0; i < SIZE; i++)  // for loop til at fylde arrray op
	{
		Lotto[i] = rand() % (b - a + 1) + a;		//sm�kker tilf�ldige tal ind i hver array plads

		if (i > 0)		//begynder f�rst at sammenligne n�r i er over 0 dvs. 1 eller over
		{

			for (size_t j = 0; j < i; j++)			//eks sammenligner 1 med 0, 2 med 1, er de lig hinanden
			{
				if (Lotto[i] == Lotto[j]) //hvis array er somme som lotto array g� en tilbage
					i--;			//g�r tallet om igen 

			}
		}
	}

	int hold;

	for (size_t pass = 1; pass < SIZE; ++pass)
	{
		for (size_t n = 0; n < (SIZE - 1); ++n)
		{
			if (Lotto[n] > Lotto[n + 1])
			{
				hold = Lotto[n];
				Lotto[n + 1] = Lotto[n];
				Lotto[n] = hold;

			}
		}
	}

	for (size_t i = 0; i < SIZE; i++)
		printf_s("%d ", Lotto[i]);

}