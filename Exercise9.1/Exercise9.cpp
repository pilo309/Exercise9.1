#include "Header.h"

/*

Exercise 9
Bilalarm

I denne opgave skal du udvikle koden til en bilalarm. 
Du skal anvende disse komponenter p� din Raspberry Pi:

� En key. Den skal fungere som �fjernbetjening�. N�r der trykkes p� knappen
skal �bilen l�ses� og alarmen skal aktiveres. N�r der trykkes p� knappen igen
skal �bilen l�ses op� og alarmen skal deaktiveres. Der skiftes tilstand hver
gang der trykkes p� knappen.

� Den r�de LED. Dette er dioden der sidder inde i �bilen�. Den skal blinke, n�r
alarmen er aktiveret og v�re slukket n�r alarmen er deaktiveret. N�r der er
registreret indbrud skla den lyse konstant.

� Gr�nne LED�er. Disse skal simulere �bilens� blinklys. Blinklyset skal med en
blinksekvens markere at alarmen aktiveres og med en anden blinksekvens
markere at alarmen deaktiveres. En tredje blinksekvens skal fungere som
alarmsignal (i stadet for et lydsignal). Du v�lger selv dine blinksekvenser.
Alternativt kan du v�lge nogle af de gr�nne LED�er til blinklys (on/off-signaler) og nogle andre gr�nne LED�er til alarmsignal.

� Switchen. Denne skal fungerer som bilens d�rkontakt. N�r switchen er ON
er �d�ren l�st�, n�r switchen er OFF er �d�ren �ben�. Hvis �d�ren� brydes op
(�bnes) mens alarmen er aktiveret, skal alarmsignalet s�ttes i gang.

� Fotoresistoren. Denne skal fungerer som �bev�gelsesf�ler� inde i bilen.
Hvis der detekteres bev�gelse inde i bilen (lyset p� fotoresistoren brydes)
mens alarmen er aktiveret, skal alarmsignalet s�ttes i gang.

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

	int key = 1; //STARTER BILEN TIL AT V�RE OPL�ST

		do   //lave uendeligt while loop
		{

				do
				{
					unlocked(5);						//viser at bilen er opl�st

					cout << "Car is unlocked" << endl;	//udskriver bilen er opl�st
					while (key == 1)					//er inde i dette loop indtil der trykkes p� P1
					{

						if (keyPressed(1))				//hvis der trykkes p� P1
						{
							key = 0;					//hvis der trykkes p� P1 �ndres key til 0 og 
						}
						Wait(70);
					}

				} while (key == 1);						//gentag det hvis key er lig 1

				do
				{
					locked(4);							//l�se bilen 2 blink p� gr�n led 4
					cout << "Car is locked" << endl;

					while (key == 0)
					{
						alarm(6);						//r�d led blinker

						if (getIntensity() <= 50 || keyPressed(2))		// indbrud hvis der er bev�gelse eller d�r
						{
							key = 3;					//g�r over p� key 3 tilstand
						}

						if (keyPressed(1))				//bilen opl�ses
						{
							key = 1;					//g�r i opl�st tilstand
						}
						Wait(70);
					}

				} while (key == 0);						

				while (key == 3)		//g�r kun og kun igang hvis der er indbrud
				{
					breakIn(6);			//r�d led lyser konstant

					cout << "CAR HAS BEEN HIJACKED!!!" << endl;		//fort�ller indbrud 
					
					
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
			

		} while (1);		// ud af loop n�r der trykkes p� tastatur

	return 0;
}