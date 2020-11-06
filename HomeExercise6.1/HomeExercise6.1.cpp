#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define SIZE 7

/*Home ex. 6.1:
Lav dit program fra Home exercise 5.4 om, således at arrayet sorteres inden tallene
udskrives(se afsnit 6.8 i bogen).
Herved bliver Lotto - rækken pænt udskrevet.
*/

/*
Home ex. 5.3:

Skriv et lille program(main) hvor i du gør følgende :

1. Opret et array til hele tal med 7 pladser

2. Læg 7 tilfældige tal mellem 1 og 36 ind i arrayet(jvf.afsnit 5.10 i bogen).

3. Udskriv derefter tallene fra arrayet på én linje med space mellem hvert tal.


Home ex. 5.4:

Kan du ændre dit program fra Home exercise 5.3, således, at det sikres, at der
lægges 7 forskellige tal ind i arrayet?

Hvis det lykkes, så har du lavet et program der genererer en tilfældig Lotto-række 

Hint: For hvert nyt tal (undtaget det første) skal du undersøge om dette tal allerede
findes i arrayet (brug en for-loop).

Hvis det findes skal tælleren tælles en ned (for at sikre at du stadig får gemt 7 tal)
ellers skal tallet gemmes på næste plads i arrayet.

*/

int main(void)
{
	int Lotto[SIZE];

	srand(time(0)); //gør de tilfældige tal HELT tilfældige

	int a = 1;		//min random værdi
	int b = 36;		//max random værdi

	for (size_t i = 0; i < SIZE; i++)  // for loop til at fylde arrray op
	{
		Lotto[i] = rand() % (b - a + 1) + a;		//smækker tilfældige tal ind i hver array plads

		if (i > 0)		//begynder først at sammenligne når i er over 0 dvs. 1 eller over
		{

			for (size_t j = 0; j < i; j++)			//eks sammenligner 1 med 0, 2 med 1, er de lig hinanden
			{
				if (Lotto[i] == Lotto[j]) //hvis array er somme som lotto array gå en tilbage
					i--;			//gør tallet om igen 

			}
		}
	}

	int hold;

	for (size_t pass = 1; pass <SIZE; ++pass)
	{
		for (size_t n = 0; n < (SIZE-1); ++n)
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
		printf_s("%d ", Lotto[i]);			//udskriver hele vores array



	return 0;
}