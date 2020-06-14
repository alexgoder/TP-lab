/*2.	Volcano preparation
In contextul pregatirii pentru o posibila eruptie aprubta a vulcanului Taal din Philipine, autoritatiile s-au pregatit in caz de orice pentru o evacuare oameniilor pe o raza de 60 km.
Zona de evacuarea se defineste ca fiind aria cerculuui a carui raza este de 60.000m. Punctul de coordonata (0,0) o reprezinta vulcanul. 
Oamenii sunt inregistrati pe harta prin puncte de coordonate pe planul / sistemul XoY.
Se considera situatia in care oamenii nu pot parasii casa fara autoritatiile.

In cazul in care erupe vulcanul, statul are pregatit 10 convoaie militare care pornesc din punctul de coordonate (10.000 , 10.000). Fiecare convoi poate cara 300 de persoana la un timp anume. Convoiu se poate deplasa cu „Y” km/h. In cazul de eruptie, lava se va deplasa uniform de la punctul de origine cu o viteza de „X” km/h. 
La imbarcarea oameniilor se considera ca nu se pierde timp si se realizeaza instant.

Sa se determine un traseu adecvat pentru fiecare convoi, astfel incat sa fie salvati cat mai multi oameni.
*/
//am considerat ca cel mai eficient ar fi ca toate convoaiele sa fie simultan intr-o zona, astfel, fiecare convoi, va lua persoana cea mai apropiata de pozitia lui curenta
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct {//am declarat o structura pentru oameni sa fie mai usor sa le stim si accesam locatia
	int x;
	int y;
	int prior;//retine pentru fiecare om zona de prioritate din care face parte
	int stare;//retine pentru fiecare om starea(0-daca nu e salvat si 1-daca e salvat)
}oameni;
typedef struct {//am declarat o structura pentru convoaie fie mai usor sa le accesam si sa stim tot despre ele
	float x;
	float y;
	int capacit;//numarul de persoane care sunt in convoi
}convoi;
typedef struct {//am facut o structura si pentru lava, sa ii stim pozitia la un anumit timp
	float x;
	float y;
}lava;
lava lav[20000];
convoi con[10];
oameni om[60000];
FILE* f, * g;
int raza = 60000,n,v_lava,v_conv,nr_sec,nr_total_salvati=0;

void init_capacit_convoi(int i)//reseteaza capcitatea unui convoi
{
	con[i].capacit= 0;//initializeaza cu 0 numarul de oameni din convoi
	if (abs(con[i].x) > abs(con[i].y))//initializeza cu 60.000 coordonata mai mare in modul
		con[i].x = raza;
	else
		con[i].y = raza;
}

int distanta_convoi(int poz_om, int poz_conv)//returneaza nr de secunde in care se parcurge distanta dintre un om si un anumit convoi
{
	float i;
	i = v_conv * 1000.0 / 3600.0;
	return (float)(sqrt((om[poz_om].x - con[poz_conv].x) * (om[poz_om].x - con[poz_conv].x) + (om[poz_om].y - con[poz_conv].y) * (om[poz_om].y - con[poz_conv].y)) / i);
}

int distanta_lava(int poz_om, int poz_lav)//returneaza nr de secunde in care se parcurge distanta dintre un om si lava
{
	float i;
	i = v_lava * 1000.0 / 3600.0;
	return (float)sqrt((om[poz_om].x - lav[poz_lav].x) * (om[poz_om].x - lav[poz_lav].x) + (om[poz_om].y - lav[poz_lav].y) * (om[poz_om].y - lav[poz_lav].y))/i;
}

int distanta_iesire_conv(int poz_conv)//dupa ce un convoi este plin, calculeaza nr de secunde in care se parcurge distanta de la coordontele lui curente pana la iesirea din zona afectata de lava 
{
	float i;
	i = v_conv * 1000.0 / 3600.0;
	return (float)sqrt((raza - con[poz_conv].x) * (raza - con[poz_conv].x) + (raza - con[poz_conv].y) * (raza - con[poz_conv].y))/i;
}


int isful(int i)//functie care verifica daca un convoi e plin
{
	if (con[i].capacit >= 300)
		return 0;//daca e plin, returneaza 0
	return 1;//altfel, returneaza 1
}


int citire()
{
	int i;
	fscanf(f, "%d", &v_lava);//citeste viteza lavei
	fscanf(f, "%d", &v_conv);//citeste viteza convoaielor
	for (i = 0; i < 10; i++)
	{
		con[i].capacit = 0;//initial, convoaiele nu au salvat nici un om
		con[i].x = 10000;//initial, convoaiele pornesc de la (10.000,10.000)
		con[i].y = 10000;
	}
	i = 0;
	while (!feof(f))
	{
		fscanf(f, "%d", &om[i].x);//pentru fiecare punct, citim x si il punem in vectorul x
		fscanf(f, "%d", &om[i].y);//pentru fiecare punct, citim y si il punem in vectorul y
		if (abs(om[i].x) > abs(om[i].y))
			om[i].prior = prioritate(om[i].x);//initializeaza prioritatea pt fiecare om
		else
			om[i].prior = prioritate(om[i].y);
		om[i].stare = 0;//fiecare om are initial starea 0(nesalvat)
		i++;
	}
	return i;//returneaza numarul de oameni
}

void lava_coordonate()//genereaza coordonatele lavei in fiecare secunda
{
	int i = 2;
	lav[0].x = 0;//initial, in secunda 0, coordonatele lavei sunt (0,0)
	lav[0].y = 0;
	lav[1].x = v_lava * 1000.0 / 3600.0;//in secunda 1, coordonatele lavei sunt viteza lavei treansformata din km/h in m/s
	lav[1].y = v_lava * 1000.0 / 3600.0;
	while (i * lav[1].x < raza)//verificare pentru a vedea daca lava a iesit sau nu din raza de 60k
	{
		lav[i].x = i * lav[1].x; //+ lav[i].x;//coordonata lavei la secunda i
		lav[i].y = lav[i].x;
		i++;
	}
	nr_sec = i;//nr totl de secunde
}

int prioritate(int x)//am impartit cercul in 5 zone de prioritate
{
	if (abs(x) <= 12000)
		return 1;
	if ((abs(x) > 12000) && (abs(x) <= 24000))
		return 2;
	if ((abs(x) > 24000) && (abs(x) <= 36000))
		return 3;
	if ((abs(x) > 36000) && (abs(x) <= 48000))
		return 4;
	if ((abs(x) > 48000) && (abs(x) <= 60000))
		return 5;
}

int maxim_prioritate(int priori)//returneaza in ce secunda ajunge lava la sfarsitul unei zone
{
	int i;
	if (priori == 0)
		return 0;
	for (i = 0; i < nr_sec; i++)
		if (lav[i].x > lav[(nr_sec / 5) * priori].x)//avand in vedere ca lava curge liniar, aceasta va umple fiecare zona dupa numarul total de secunde/nr de zone
			return i;//returneaza secunda in care lava ajunge sa acopere zona
}

void rescue(int indice_om, int indice_convoi)//dupa ce un om e salvat, coordonatele omului devin noile coordonate ale convoiului
{
	con[indice_convoi].x = om[indice_om].x;//seteaza noile coordonate ale convoiului
	con[indice_convoi].y = om[indice_om].y;
}

void afisare(int i,int oameni_salvati)//afiseaza pentru fiecare convoi numarul oamenilor salvati
{
	fprintf(g, "Convoiul %d a salvat %d oameni\n", i + 1, oameni_salvati);
}

void solutie()//genereaza solutia
{//am gandit problema astfel incat fiecare convoi, pe rand, va salva cat de multi oameni posibil in intervalul de timp pana cand lava acopera total zona de prioritate
	int indice_om, indice_convoi, priorit, timp,oameni_salvati=0;
	for (indice_convoi = 0; indice_convoi < 10; indice_convoi++)//parcurge convoaiele
	{
		oameni_salvati = 0;//initia, convoaiele nu au salvat nici un om
		for (priorit = 1; priorit < 6; priorit++)//parcurge zonele de prioritate
		{
			timp = maxim_prioritate(priorit-1);//indicele pentru lava incepe dupa fiecare zona de la zona anterioara
			for (indice_om = 0; indice_om < n && timp<=maxim_prioritate(priorit); indice_om++)//parcurge oamenii, cat timp lava nu a acoperit zona 
			{
				if (isful(indice_convoi) == 0)//daca este plin convoiul
				{
					timp += distanta_iesire_conv(indice_convoi);//la timp, se adauga timpul pe care il face pe drum
					init_capacit_convoi(indice_convoi);//se initializeaza capacitatea lui cu 0 si se modifica coordonatele
				}
				else
				if (om[indice_om].prior == priorit && om[indice_om].stare == 0 && distanta_convoi(indice_om, indice_convoi) < distanta_lava(indice_om, timp) )
				{//daca omul face parte din zona de prioritate si nu este salvat, iar timpul in care ar ajuge convoiul la el e mai mic devat timpul in care ar ajunge lava la el
					con[indice_convoi].capacit++;//creste numarul de persoane din convoiul respectiv
					oameni_salvati++;//creste numarul oamenilor salvati de catre convoi
					om[indice_om].stare = 1;//omul respectiv primeste starea 1, adica salvat
					rescue(indice_om, indice_convoi);//se initializeaza noile coordonate ale convoiului
					timp += distanta_convoi(indice_om, indice_convoi);//creste timpul, respectiv, creste raspandirea lavei
					nr_total_salvati++;//creste numarul oamenilor salvati in total
				}
			}
		}
		afisare(indice_convoi, oameni_salvati);//se afiseaza pentru fiecare convoi cati oameni a salvat
	}
}

int main()
{
	int i;
	f = fopen("in.txt", "r");
	g = fopen("out.txt", "w");
	n = citire();//in n se va retine numarul de oameni
	lava_coordonate();//calculeaza coordonatele lavei in fiecare secunda
	solutie();//genereaza solutiile
	fprintf(g, "Numarul total de oameni salvati este: %d", nr_total_salvati);//afiseaza numarul total al oamenilor salvati
	fclose(f);
	fclose(g);
	return 0;
}
