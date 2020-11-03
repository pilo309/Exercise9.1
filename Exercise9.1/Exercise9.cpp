#include "Header.h"

/*

Exercise 9
Bilalarm

I denne opgave skal du udvikle koden til en bilalarm. 
Du skal anvende disse komponenter på din Raspberry Pi:

• En key. Den skal fungere som ”fjernbetjening”. Når der trykkes på knappen
skal ”bilen låses” og alarmen skal aktiveres. Når der trykkes på knappen igen
skal ”bilen låses op” og alarmen skal deaktiveres. Der skiftes tilstand hver
gang der trykkes på knappen.

• Den røde LED. Dette er dioden der sidder inde i ”bilen”. Den skal blinke, når
alarmen er aktiveret og være slukket når alarmen er deaktiveret. Når der er
registreret indbrud skla den lyse konstant.

• Grønne LED’er. Disse skal simulere ”bilens” blinklys. Blinklyset skal med en
blinksekvens markere at alarmen aktiveres og med en anden blinksekvens
markere at alarmen deaktiveres. En tredje blinksekvens skal fungere som
alarmsignal (i stadet for et lydsignal). Du vælger selv dine blinksekvenser.
Alternativt kan du vælge nogle af de grønne LED’er til blinklys (on/off-signaler) og nogle andre grønne LED’er til alarmsignal.

• Switchen. Denne skal fungerer som bilens dørkontakt. Når switchen er ON
er ”døren låst”, når switchen er OFF er ”døren åben”. Hvis ”døren” brydes op
(åbnes) mens alarmen er aktiveret, skal alarmsignalet sættes i gang.

• Fotoresistoren. Denne skal fungerer som ”bevægelsesføler” inde i bilen.
Hvis der detekteres bevægelse inde i bilen (lyset på fotoresistoren brydes)
mens alarmen er aktiveret, skal alarmsignalet sættes i gang.

*/

int main(void)
{

	using namespace std;

	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	// To do your code

	int key = 1; //STARTER BILEN TIL AT VÆRE OPLÅST

		do   //lave uendeligt while loop
		{

				do
				{
					unlocked(5);						//viser at bilen er oplåst

					cout << "Car is unlocked" << endl;	//udskriver bilen er oplåst
					while (key == 1)					//er inde i dette loop indtil der trykkes på P1
					{

						if (keyPressed(1))				//hvis der trykkes på P1
						{
							key = 0;					//hvis der trykkes på P1 ændres key til 0 og 
						}
						Wait(70);
					}

				} while (key == 1);						//gentag det hvis key er lig 1

				do
				{
					locked(4);							//låse bilen 2 blink på grøn led 4
					cout << "Car is locked" << endl;

					while (key == 0)
					{
						alarm(6);						//rød led blinker

						if (getIntensity() <= 50 || keyPressed(2))		// indbrud hvis der er bevægelse eller dør
						{
							key = 3;					//går over på key 3 tilstand
						}

						if (keyPressed(1))				//bilen oplåses
						{
							key = 1;					//går i oplåst tilstand
						}
						Wait(70);
					}

				} while (key == 0);						

				while (key == 3)		//går kun og kun igang hvis der er indbrud
				{
					breakIn(6);			//rød led lyser konstant

					cout << "CAR HAS BEEN HIJACKED!!!" << endl;		//fortæller indbrud 
					
					
					while (key == 3)
					{
						if (keyPressed(1))
						{
							ledOff(6);
							key = 1;
						}
						Wait(70);
					}

				}
			

		} while (1);		// ud af loop når der trykkes på tastatur

	return 0;
}