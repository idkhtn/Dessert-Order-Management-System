#include <iostream>
#include <ctime>
using namespace std;

//Zmienne globalne
double cena = 0; //Jest to cena pojedynczego produktu

class Koszt
{
public:
	static double sumaDoZaplaty;

	static void WyswietlSuma()
	{
		cout << "Do zaplaty: " << sumaDoZaplaty << endl;
	}

	static void UstawSume()
	{
		sumaDoZaplaty = cena + sumaDoZaplaty;
	}
};
double Koszt::sumaDoZaplaty = 0; //Jest uzywana do podsumowania ceny produktow

class Pelnoletni
{
private:
    int rok = 0;
public:
    Pelnoletni()
    {
    }
    void Wiek()
    {
        cout << "Aby dodac do zamowienia podany produkt nalezy potwierdzic swoja date urodzenia!\n";
        while(true)
        {
            cout << "Prosze podac swoj rok urodzenia: ";
            cin >> rok;
        if(rok <= 2003)
        {
            cout << "Dziekujemy! Produkt zostal dodany do zamowienia!\n";
            cena = 4;
            Koszt::UstawSume();
            break;
        }
        else if(rok > 2003)
        {
            cout << "Przepraszamy! Produkt nie moze zostac dodany do zamowienia!\n";
            break;
        }
        else
            cout << "Nieprawidlowa data! Prosze wprowadzic date ponownie!\n";
        }
    }
};

class Deser
{
protected:
	string nazwa = "Brak";
	int rozmiar = 0;
  int czySos = 0;
  int sos = 0;
	int smak = 0;
	Pelnoletni wiek;
public:
	Deser() //Konstruktor domyślny, nie bedziemy tworzyc deseru bez rodzaju
	{
	}
	void WybierzRozmiar()
	{
		while (true) //Petla ma zapobiec blednemu podawania rozmiaru. Jesli zostanie podany poprawny, to wyjdziemy z petli
		{
			cout << "Wybierz rozmiar" << endl;
			cout << "Rozmiary do wyboru: \n1 Maly \n2 Sredni \n3 Duzy" << endl;
			cin >> rozmiar;
			cout << endl << "Wybrany rozmiar: ";
			if (rozmiar == 1)
			{
				cout << "Maly" << endl;
				break;
			}
			else if (rozmiar == 2)
			{
				cout << "Sredni" << endl;
				break;
			}
			else if (rozmiar == 3)
			{
				cout << "Duzy" << endl;
				break;
			}
			else
				cout << "blad. Prosze wybrac poprawny rozmiar" << endl;
		}
	}
	void Sosy()
	{
		while(true)
		{
			cout << "Czy chcesz dodac sos? \n1. Tak \n2. Nie" << endl;
			cin >> czySos;
			if (czySos == 1)
			{
				while (true)
				{
					cout << endl;
					cout << "Wybierz sos" << endl;
					cout << "Sosy do wyboru: \n1 Sosy owocowe \n2 Sos alkoholowy \n3 Sosy dla vegan/bez laktozy \n4 Zwykle" << endl;
					cin >> sos;
					cout << endl;
					if (sos == 1)
					{
						cout << "Wybierz jaki sos owocowy" << endl;
						cout << "1 Truskawkowy \n2 Porzeczkowy \n3 Jablkowy \n4 Wisniowy " << endl;
						cin >> smak;
						cout << "Wybrano sos: ";
						if (smak == 1)
						{
							cout << "truskawkowy" << endl;
							break;
						}
						if (smak == 2)
						{
							cout << "porzeczkowy" << endl;
							break;
						}
						if (smak == 3)
						{
							cout << "jablkowy" << endl;
							break;
						}
						if (smak == 4)
						{
							cout << "wisniowy" << endl;
							break;
						}
					}
					else if (sos == 2)
					{
						wiek.Wiek();
						break;
					}
					else if (sos == 3)
					{
						cout << "Sos dla vegan/bez laktozy" << endl;
						cout << "Wybierz jaki sos: " << endl;
						cout << "1 z agawy \n2 klonowy \n3 daktylowy" << endl;
						cin >> smak;
						cout << "Wybrano sos: ";
						if (smak == 1)
						{
							cout << "z agawy" << endl;
							break;
						}
						if (smak == 2)
						{
							cout << "klonowy" << endl;
							break;
						}
						if (smak == 3)
						{
							cout << "daktylowy" << endl;
							break;
						}
					}
					else if (sos == 4)
					{
						cout << "Wybierz jaki sos: " << endl;
						cout << "1 Czekoladowy \n2 Karmelowy \n3 Balonowy" << endl;
						cin >> smak;
						cout << "Wybrano sos: ";
						if (smak == 1)
						{
							cout << "czekoladowy" << endl;
							break;
						}
						if (smak == 2)
						{
							cout << "karmelowy" << endl;
							break;
						}
						if (smak == 3)
						{
							cout << "balonowy" << endl;
							break;
						}
					}
					else
					{
						cout << "Blad. Wpisz poprawna wartosc!" << endl;
					}
					if (sos == 1)
					{
						cena = 1.5;
						Koszt::UstawSume();
					}
					else if (sos == 3)
					{
						cena = 3;
						Koszt::UstawSume();
					}
					else if (sos == 4)
					{
						cena = 1.5;
						Koszt::UstawSume();
					}
				}
				break;
			}
			else if (czySos == 2)
			{
				cout << "Wybrano opcje bez sosow" << endl;
				break;
			}
			else
			{
			cout << "Prosze wybrac jedna z dwoch opcji" << endl;
			}
		}
	}
};
class Napoj:public Deser
{
public:
    int kubek;
    int nowyrozmiar;
    Napoj()
    {
    }
    void wybierz_rozmiar()
    {
        WybierzRozmiar();
    if(rozmiar == 3)
    {
        cout << "Za doplata mozna powiekszyc duzy kubek do rozmiaru XL i XXL! Czy chcesz skorzystac i wybrac inny rozmiar?\n";
        cout << "1. Tak, wybieram kubek XL (doplata 1.00 zl)!\n2. Tak, wybieram kubek XXL (doplata 2.00 zl)!\n";
        cout << "3. Nie, chce zostac przy duzym kubku!\n";
        cin >> nowyrozmiar;
        if(nowyrozmiar == 1)
            {
                cena = 1.00;
                Koszt::UstawSume();
                cout << "Wybrano kubek XL!\n";
            }
            else if(nowyrozmiar == 2)
            {
                cena = 2.00;
                Koszt::UstawSume();
                cout << "Wybrano kubek XXL!\n";
            }
            else
                cout << "Wybrano kubek duzy!\n";
        }
    }
  void wybierz_kubek()
  {
      while(true)
      {
          cout << "\nProsze wybrac rodzaj kubka: \n1. Plastikowy \n2. Papierowy \n3. Szklany +3.00 zl\n";
          cin >> kubek;
      if(kubek == 1)
      {
          cout << "Wybrano plastikowy kubek!\n";
          break;
      }
      else if(kubek == 2)
      {
          cout << "Wybrano papierowy kubek!\n";
          break;
      }
      else if(kubek == 3)
      {
          cout << "Wybrano szklany kubek!\n";
          cena = 3.0;
          Koszt::UstawSume();
          break;
      }
      else
          cout << "Wybrany kubek nie istnieje. Prosze dokonac ponownego wyboru!\n";
      }
  }
};
class Lody:public Deser
{
private:
    string nazwa;
    Napoj drink;
    int opak = 0;
    int rozek = 0;
    int galki = 0;
    int dodaj = 0;
    int takNie;
public:
    Lody(string n)
        :nazwa(n)
        {
          cout << endl;
		      cout << "KREATOR LODOW" << endl;
		      cout << "-------------------" << endl;
        }

    void opakowanie()
    {
        cout << "Wybor opakowania do lodow: " << endl;
        cout << "1 wafelek \n2 kubeczek" << endl;
        cin >> opak;
        if(opak == 1)
        {
            cout << "Wybierz rodzaj wafelka: " << endl;
            cout << "1 Rozek tulipan \n2 Rozek twister +1.50 zl \n3 wafel kanadyjka" << endl;
            cin >> rozek;
            cout << "Wybrano: ";
            while(true)
            {
                if(rozek == 1)
                {
                    cout << "rozek tulipan" << endl;
                    break;
                }
                else if(rozek == 2)
                {
                    cout << "rozek twister \ndodatkowa oplata 1.50 zl" << endl;
                    break;
                }
                else if(rozek == 3)
                {
                    cout << "wafel kanadyjka" << endl;
                    break;
                }
            }

        }
        else if(opak == 2)
        {
            drink.wybierz_kubek();
        }
    }
    void rozmiarLody()
    {
        if(opak == 1)
        {
            WybierzRozmiar();
            cout << endl;
        }
    }
    void Galki() // tej funkcji nie wywolujemy, umieszczamy ja w funkcji iloscGalek
    {
                cout << endl;
                cout << "Wybierz smaki galek: " << endl;
                cout << "Zwykle o smaku:\n\t1 Oreo +2.00 zl\n\t2 Snickers +2.00 zl\n\t3 Waniliowe\n\t4 Smietankowe\n\t5 Czekoladowe" << endl;
                cout << "Dla vegan\n\t6 Truskawkowe\n\t7 Kokosowe\n\t8 Ananasowe\n\t9 Cytrynowe" << endl;
                cout << "Bez laktozy +1.00 zl\n\t10 Smietankowe bez laktozy\n\t11 Waniliowe bez laktozy\n\t12 Czekoladowe bez laktozy" << endl;
                cin >> galki;
                cout << endl;
                cout << "Wybrano smak: ";
                if(galki == 1)
                {
                    cout << "Oreo" << endl;
                }
                else if(galki == 2)
                {
                    cout << "Snickers" << endl;
                }
                else if(galki == 3)
                {
                    cout << "Waniliowe" << endl;
                }
                else if(galki == 4)
                {
                    cout << "Smietankowe" << endl;
                }
                else if(galki == 5)
                {
                    cout << "Czekoladowe" << endl;

                }
                else if(galki == 6)
                {
                    cout << "Truskawkowe" << endl;
                }
                else if(galki == 7)
                {
                    cout << "Kokosowe" << endl;
                }
                else if(galki == 8)
                {
                    cout << "Ananasowe" << endl;
                }
                else if(galki == 9)
                {
                    cout << "Cytrynowe" << endl;
                }
                else if(galki == 10)
                {
                    cout << "Smietankowe bez laktozy" << endl;
                }
                else if(galki == 11)
                {
                    cout << "Waniliowe bez laktozy" << endl;
                }
                else if(galki == 12)
                {
                    cout << "Czekoladowe bez laktozy" << endl;
                }
                else
                {
                    cout << "Blad. Sprobuj ponownie wybrac smak" << endl;
                }

        // ----------------Koszty-----------------------------
        //reszta galek, czyli zwykle nie maja dodatkowej ceny
                if(galki == 1 || galki == 2)
                {
                    cena = 2;
                    Koszt::UstawSume();
                }
                else if(galki >=10 || galki <=12)
                {
                    cena = 1;
                    Koszt::UstawSume();
                }
    }
    void dodatkiLody() // tej funkcji nie wywolujemy, umieszczamy ja w funkcji iloscGalek
    {
            cout << "Czy chcesz dac dodatki do lodow?\nWybierz opcje\n\t1 TAK\n\t2 NIE" << endl;
            cin >> takNie;
            if(takNie == 1)
            {
                cout << endl;
                cout << "Wybierz dodatki do lodow:" << endl;
                cout << "\t1 Posypka czekoladowa\n\t2 Posypka kolorowa\nDla vegan\n\t3 Wiorki kokosowe\n\t4 Platki migdalowe" ;
                cout << "\nBez laktozy +2 zl\n\t5 Posypka czekoladowa bez laktozy\n\t6 Posypka kolorowa bez laktozy" << endl;
                cout << "Owoce\n\t7 Jagody\n\t8 Borowki\n\t9 Truskawki" << endl;
                cin >> dodaj;
                cout << endl;
                cout << "Wybrano dodatek: ";
                if(dodaj == 1)
                {
                    cout << "Posypka czekoladowa" << endl;
                }
                else if(dodaj == 2)
                {
                    cout << "Posypka kolorowa" << endl;
                }
                else if(dodaj == 3)
                {
                    cout << "Wiorki kokosowe" << endl;
                }
                else if(dodaj == 4)
                {
                    cout << "Platki migdalowe" << endl;
                }
                else if(dodaj == 5)
                {
                    cout << "Posypka czekoladowa bez laktozy" << endl;
                }
                else if(dodaj == 6)
                {
                    cout << "Posypka kolorowa bez laktozy" << endl;
                }
                else if(dodaj == 7)
                {
                    cout << "Jagody" << endl;
                }
                else if(dodaj == 8)
                {
                    cout << "Borowki" << endl;

                }
                else if(dodaj == 9)
                {
                    cout << "Truskawki" << endl;
                }
                else
                {
                    cout << "Blad. Sprobuj ponownie wybrac smak" << endl;
                }
                //---------------------------- Koszty ----------------------
                if(dodaj >= 1 || dodaj <= 4)
                {
                    cena = 1.5;
                    Koszt::UstawSume();
                }
                else if(dodaj ==5 || dodaj ==6)
                {
                    cena = 2.5;
                    Koszt::UstawSume();
                }
                else if(dodaj >=7 || dodaj <=9)
                {
                    cena = 3;
                    Koszt::UstawSume();
                }
            }
            else
            {
                cout << "Nie wybrano dodatku" << endl;
            }
    }
    void iloscGalek() //zalezy od kubka czy wafelka //umieszczamy tu takze funkcje dodatkiLody
    {
        if(rozek == 1) //maly lodzik
            {
                cena = 4;
                Koszt::UstawSume();
                for(int i=0; i<1; i++)
                {
                    Galki();
                    dodatkiLody();
                }
            }
        else if(rozek == 2) //sredni lodzik
            {
                cena = 6;
                Koszt::UstawSume();
                for(int i=0; i<2; i++)
                {
                    Galki();
                }
                dodatkiLody();
            }
        else if(rozek == 3) // duzy lodzik
            {
                cena = 8;
                Koszt::UstawSume();
                for(int i=0; i<3; i++)
                {
                    Galki();
                }
                for(int i=0; i<2; i++)
                {
                    dodatkiLody();
                    if(takNie==2)
                    {
                      break;
                    }
                }
            }
        else if(opak == 2) //kubek zawsze pomiesci 3 galki
        {
            cena = 9;
            Koszt::UstawSume();
            for(int i=0; i<3; i++)
            {
                Galki();
            }
            for(int i=0; i<2; i++)
            {
                dodatkiLody();
                if(takNie==2)
                    {
                      break;
                    }
            }
        }
    }
    void wyborSosu()
    {
        Sosy();
    }
    void tworzLody()
    {
	  	opakowanie();
		  iloscGalek();
		  wyborSosu();
	  }
};
class Gofry:public Deser
{
protected:
    int rodzaj = 0;
    int dodatek = 0;
    int dod = 0;
    string nazwa;
    int takNie;
public:
    Gofry(string naz)
        :nazwa(naz)
    {
      cout << endl;
		  cout << "KREATOR GOFRY" << endl;
		  cout << "-------------------" << endl;
    }
    void wybierz_rozmiar()
    {
        WybierzRozmiar();
        cout << endl;
    }

    void rodzajGofra() //rodzaj gofra czy dla vegan, zwykle lub bez laktozy, gdyz to determinuje pózniejsze wybory
    {
        while(true)
        {
            cout << endl;
            cout << "Wybierz rodzaj gofra" << endl ;
            cout << "Rodzaje do wyboru: \n1 Zwykly \n2 Dla vegan \n3 Bez laktozy" << endl;
            cin >> rodzaj;
            cout << endl << "Wybrany rodzaj: ";
            if (rodzaj == 1)
            {
                cout << "Zwykly" << endl;
                break;
            }
            else if (rodzaj == 2)
            {
                cout << "Dla vegan" << endl;
                cena = 2;
                Koszt::UstawSume();
                break;
            }
            else if (rodzaj == 3)
            {
                cout << "Bez laktozy" << endl;
                cena = 2;
                Koszt::UstawSume();
                break;
            }
            else
            {
              cout << "Blad. Wybierz ponownie rodzaj gofra" << endl;
            }
        }
    }
    void dodatkiGofry() // tej funkcji nie wywolujemy, umieszczamy ja w funkcji dodatki_rozmiar
    {
            cout << "Czy chcesz dac dodatki do gofra?\nWybierz opcje\n\t1 TAK\n\t2 NIE" << endl;
            cin >> takNie;
                if(takNie == 1)
                {
                    cout << endl;
                    cout << "wybierz rodzaj dodatkow: " << endl;
                    cout << "1 Owoce \n2 Dzemy \n3 Cukier puder \n4 Weganska bita smietana \n5 Bita smietana bez laktozy" << endl;
                    cin >> dodatek;
                    cout << endl;
                    if(dodatek == 1)
                    {
                        cout << "Wybierz jakie owoce chcesz: " << endl;
                        cout << "1 truskawki \n2 borowki \n3 mango" << endl;
                        cin >> dod;
                        cout << "Wybrano: " ;
                        if(dod == 1)
                        {
                            cout << "truskawki" << endl;

                        }
                        else if(dod == 2)
                        {
                            cout << "borowki" << endl;

                        }
                        else if(dod == 3)
                        {
                            cout << "mango" << endl;

                        }

                    }
                    else if(dodatek == 2)
                    {
                        cout << "Wybierz smak dzemow:" << endl;
                        cout << "1 Porzeczkowy \n2 Truskawkowy \n3 Sliwkowy" << endl;
                        cin >> dod;
                        cout << "Wybrano dzem: " ;
                        if(dod == 1)
                        {
                            cout << "porzeczkowy" << endl;

                        }
                        else if(dod == 2)
                        {
                            cout << "truskawkowy" << endl;

                        }
                        else if(dod == 3)
                        {
                            cout << "sliwkowy" << endl;

                        }

                    }
                    else if(dodatek == 3)
                    {
                        cout << "cukier puder" << endl;

                    }
                    else if(dodatek == 4)
                    {
                        cout << "weganska bita smietane" << endl;
                        cena = 2;
                        Koszt::UstawSume();

                    }
                    else if(dodatek == 5)
                    {
                        cout << "bita smietane bez laktozy" << endl;
                        cena = 2;
                        Koszt::UstawSume();

                    }
                }
        }
    void dodatki_rozmiar()
        {
            if(rozmiar == 1)
            {
                cena = 8;
                Koszt::UstawSume();
                for(int i=0; i<2; i++)
                {
                    dodatkiGofry();
                    if(takNie==2)
                    {
                      break;
                    }
                }
            }
            else if(rozmiar == 2)
            {
                cena = 10;
                Koszt::UstawSume();
                for(int i=0; i<3; i++)
                {
                    dodatkiGofry();
                    if(takNie==2)
                    {
                      break;
                    }
                }
            }
            else if(rozmiar == 3)
            {
                cena = 12;
                Koszt::UstawSume();
                for(int i=0; i<4; i++)
                {
                    dodatkiGofry();
                    if(takNie==2)
                    {
                      break;
                    }
                }
            }
        }
    void wyborSosu()
        {
            Sosy();
        }
    void tworzGofry()
      {
        wybierz_rozmiar();
        dodatki_rozmiar();
        wyborSosu();
      }

};
class Shake :public Napoj
{
private:
  int dodatkiShake = 0;
public:
	Shake()
	{
		cout << endl;
		cout << "KREATOR SHAKE" << endl;
		cout << "-------------------" << endl;
	}
	void Smak_Shake()
	{
    while(true)
    {
      int smakShake;
      int vegan;
      cout << "Jesli chcesz wybrac opcje weganska wybierz 1. Jesli nie wybierz 2." << endl;
      cin >> vegan;
      cout << "Wybierz smak SHAKE'A " << endl;
      cout << "----------------------" << endl;
      if (vegan == 1)
      {
        while (true)
        {
          cout << "1.Truskawka 12 zl \n2.Jablko 16 zl \n3.Morela 14 zl" << endl;
          cin >> smakShake;
          if (smakShake == 1)
          {
            cout << "Wybrano smak TRUSKAWKOWY!" << endl;
            cena = 12;
            Koszt::UstawSume();
            break;
          }
          else if (smakShake == 2)
          {
            cout << "Wybrano smak JABLKOWY!" << endl;
            cena = 16;
            Koszt::UstawSume();
            break;
          }
          else if (smakShake == 3)
          {
            cout << "Wybrano smak MORELOWY!" << endl;
            cena = 14;
            Koszt::UstawSume();
            break;
          }
          else
            cout << "Wybrano niepoprawny smak! Sprobuj ponownie!" << endl;
        }
        break;
      }
      if (vegan == 2)
      {
        while (true)
        {
          cout << "\n4.Czekolada 14 zl \n5.Wanilia 11 zl \n6.Karmel 18 zl\n";
          cin >> smakShake;
          if (smakShake == 4)
          {
            cout << "Wybrano smak CZEKOLADOWY!" << endl;
            cena = 14;
            Koszt::UstawSume();
            break;
          }
          else if (smakShake == 5)
          {
            cout << "Wybrano smak WANILIOWY!" << endl;
            cena = 11;
            Koszt::UstawSume();
            break;
          }
          else if (smakShake == 6)
          {
            cout << "Wybrano smak KARMELOWY!" << endl;
            cena = 18;
            Koszt::UstawSume();
            break;
          }
          else
            cout << "Wybrano niepoprawny smak! Sprobuj ponownie!" << endl;
        }
        break;
      }
      else
      {
        cout << "Podano niepoprawna kategorie!" << endl;
      }
    }
	}
	void Dodatki_shake()
	{
    if(dodatkiShake<3)
    {
      while(true)
      {
        int potw;
        int dodatek_do_shake;
        cout << "Czy chcesz dodac dodatek do SHAKE'A? " << endl;
        cout << "1.TAK \n2.NIE" << endl;
        cin >> potw;
        if (potw == 1)
        {
          dodatkiShake++;
          while (true)
          {
            cout << "Wybierz dodatek: " << endl;
            cout << "1. Posypka czekoladowa 4 zl \n2. Mix owocow 3 zl \n3. Orzechy 3 zl \n4. Wiorki kokosowe 1 zl" << endl;
            cin >> dodatek_do_shake;
            if (dodatek_do_shake == 1)
            {
              cout << "Wybrano dodatek POSYPKA CZEKOLADOWA!" << endl;
              cena = 4;
              Koszt::UstawSume();
              break;
            }
            else if (dodatek_do_shake == 2)
            {
              cout << "Wybrano dodatek MIX OWOCOW!" << endl;
              cena = 3;
              Koszt::UstawSume();
              break;
            }
            else if (dodatek_do_shake == 3)
            {
              cout << "Wybrano dodatek ORZECHY!" << endl;
              cena = 3;
              Koszt::UstawSume();
              break;
            }
            else if (dodatek_do_shake == 4)
            {
              cout << "Wybrano dodatek WIORKI KOKOSOWE!" << endl;
              cena = 1;
              Koszt::UstawSume();
              break;
            }
            else
              cout << "Wybrano niepoprawny dodatek! Sprobuj ponownie!" << endl;
          }
          Dodatki_shake();
          break;
        }
        if(potw==2)
          break;
        else
        {
          cout << "Podano niepoprawna wartosc!" << endl;
        }
      }
    }
	}
  void tworzyShake()
      {
        Smak_Shake();
        Dodatki_shake();
      }
};
class Smoothie :public Napoj
{
private:
  int dodatkiSmoothie = 0;
public:
  Smoothie()
  {
      cout << endl;
      cout << "KREATOR SMOOTHIE" << endl;
      cout << "-------------------" << endl;
  }
  void Czy_cukier()
  {
    while(true)
    {
      int potwierdzenie;
      cout << "Aby dodac cukier do smoothie (za doplata +1.00 zl) do smoothie wybierz 1. Jesli nie wybierz 2." << endl;
      cin >> potwierdzenie;
      if (potwierdzenie == 1)
      {
          cena = 1;
          Koszt::UstawSume();
          cout << "Cukier dodano !" << endl;
          break;
      }
      else if(potwierdzenie==2)
      {
          cout << "Cukru nie dodano !" << endl;
          break;
      }
      else
      {
        cout<<"Podano niepoprawną wartość!"<<endl;
      }
    }
  }
  void Skladniki_Smoothie()
  {
      int Ile_skladnikow;
      int smakSmoothie;
      cout << "Ile skladnikow wybierasz do Smoothie? Maksymalnie moze byc ich 3." << endl;
      cin >> Ile_skladnikow;
      if(Ile_skladnikow>3)
      {
        Ile_skladnikow=3;
        cout<<"Zmieniono wybor na maksymalny - 3"<<endl;
      }
      if(Ile_skladnikow<0)
      {
        Ile_skladnikow=1;
        cout<<"Zmieniono wybor na minimalny - 1"<<endl;
      }
      for(int i=0; i<Ile_skladnikow;i++)
      {
        while(true)
       {
          cout << "Wybierz skladniki smoothie " << endl;
          cout << "----------------------" << endl;
          cout << "1.Truskawka 4 zl \n2.Malina 6 zl \n3.Pomarancza 4 zl \n4.Kiwi 4 zl \n5.Cytryna 3 zl \n6.Ananas 7 zl\n";
          cin >> smakSmoothie;
          if (smakSmoothie == 1)
          {
              cout << "Wybrano skladnik TRUSKAWKA !" << endl;
              cena = 4;
              Koszt::UstawSume();
              break;
          }
          else if (smakSmoothie == 2)
          {
              cout << "Wybrano skladnik MALINA !" << endl;
              cena = 6;
              Koszt::UstawSume();
              break;
          }
          else if (smakSmoothie == 3)
          {
              cout << "Wybrano skladnik POMARANCZA !" << endl;
              cena = 4;
              Koszt::UstawSume();
              break;
          }
          else if (smakSmoothie == 4)
          {
              cout << "Wybrano skladnik KIWI !" << endl;
              cena = 4;
              Koszt::UstawSume();
              break;
          }
          else if (smakSmoothie == 5)
          {
              cout << "Wybrano skladnik CYTRYNA !" << endl;
              cena = 3;
              Koszt::UstawSume();
              break;
          }
          else if (smakSmoothie == 6)
          {
              cout << "Wybrano skladnik ANANAS !" << endl;
              cena = 7;
              Koszt::UstawSume();
              break;
          }
          else
          {
              cout << "Wybrano niepoprawny skladnik ! Sprobuj ponownie !" << endl;
          }
        }
        if(i<Ile_skladnikow-1)
        {
          cout << "Czy chcesz dodac kolejny skladnik do SMOOTHIE ? " << endl;
          cout << "1.TAK \n2.NIE" << endl;
          cin >> smakSmoothie;
          if(smakSmoothie==2)
            break;
        }
      }
      
    }

  void Dodatki_Smoothie()
  {
    if(dodatkiSmoothie<3)
    {
      while(true)
        {
          int potw;
          int dodatek_do_smoothie;
          cout << "Czy chcesz dodac dodatek do SMOOTHIE?" << endl;
          cout << "1.TAK \n2.NIE" << endl;
          cin >> potw;
          if (potw == 1)
          {
            dodatkiSmoothie++;
            while(true)
            {
              cout << "Wybierz dodatek: " << endl;
              cout << "1. Mieta 1 zl \n2. Mix owocow 3 zl \n3. Orzechy 3 zl \n4. Wiorki kokosowe 1 zl \n5. Platki owsiane 1 zl \n6. Nasiona Chia 1 zl \n7. Lod 1 zl" << endl;
              cin >> dodatek_do_smoothie;
              if (dodatek_do_smoothie == 1)
              {
                  cout << "Wybrano dodatek MIETA !" << endl;
                  cena = 1;
                  Koszt::UstawSume();
                  break;
              }
              else if (dodatek_do_smoothie == 2)
              {
                  cout << "Wybrano dodatek MIX OWOCOW !" << endl;
                  cena = 3;
                  Koszt::UstawSume();
                  break;
              }
              else if (dodatek_do_smoothie == 3)
              {
                  cout << "Wybrano dodatek ORZECHY !" << endl;
                  cena = 3;
                  Koszt::UstawSume();
                  break;
              }
              else if (dodatek_do_smoothie == 4)
              {
                  cout << "Wybrano dodatek WIORKI KOKOSOWE !" << endl;
                  cena = 1;
                  Koszt::UstawSume();
                  break;
              }
              else if (dodatek_do_smoothie == 5)
              {
                  cout << "Wybrano dodatek PLATKI OWSIANE !" << endl;
                  cena = 1;
                  Koszt::UstawSume();
                  break;
              }
              else if (dodatek_do_smoothie == 6)
              {
                  cout << "Wybrano dodatek NASIONA CHIA !" << endl;
                  cena = 1;
                  Koszt::UstawSume();
                  break;
              }
              else if (dodatek_do_smoothie == 7)
              {
                  cout << "Wybrano dodatek LOD !" << endl;
                  cena = 1;
                  Koszt::UstawSume();
                  break;
              }
              else
              {
                cout << "Wybrano niepoprawny dodatek! Sprobuj ponownie !" << endl;
              }
            }
            Dodatki_Smoothie();
            break;
          }
          if(potw==2)
            break;
          else
          {
            cout << "Podano niepoprawna wartosc!" << endl;
          }
        }
    }
  }
  void Kubek_Smoothie()
  {
      void wybierz_kubek();
  }
  void tworzSmoothie()
  {
      Kubek_Smoothie();
      Czy_cukier();
      Skladniki_Smoothie();
      Dodatki_Smoothie();
  }
};

class Zaplac :public Koszt
{
public:
	static double kwota;
	static int rodzaj;

	static void RodzajPlatnosci()
	{
		cout << "Podaj rodzaj platnosci:" << endl;
		cout << "1 Karta \n2 Gotowka" << endl;
		cin >> rodzaj;
	}

	static double Reszta(double kwota)
	{
		double reszta;
		reszta = kwota - sumaDoZaplaty;
		return reszta;
	}

	static void Zaplata()
	{
		RodzajPlatnosci();
		if (rodzaj == 1)
		{
			cout << "Wybrano platnosc karta" << endl;
			WyswietlSuma();
			cout << "Zbliz karte do terminala" << endl;
		}
		else if (rodzaj == 2)
		{
      while(true)
      {
        cout << "Wybrano platnosc gotowka" << endl;
        WyswietlSuma();
        cout << "Wybierz wplacana kwote" << endl;
        cin >> kwota;
        if(kwota<sumaDoZaplaty)
        {
          cout<<"Prosze wprowadzic wieksza kwote."<<endl;
          cout<<"Brakuje: "<<Reszta(kwota)*(-1)<<" zl"<<endl;
        }
        else
          break;
      }
			cout << "Wplacono: " << kwota << " zl" << endl;
			cout << "Reszta: " << Reszta(kwota) << " zl" << endl;
		}
		else
		{
			cout << "Blad w wyborze platnosci" << endl;
			Zaplata();
		}
	}
};

class Paragon:public Zaplac
{
public:
    /* Pobiera date i godzine systemowa */
    time_t teraz = time(0);
    char* dt = ctime(&teraz);

    void wyswietl_paragon()
    {
    cout << "\n==========================================\n";
    cout << "\t   PARAGON FISKALNY\n";
    cout << "\nPotwierdzenie zlozenia zamowienia.\n";
    cout << "------------------------------------------\n";
    cout << "Data i godzina: " << dt;
    cout << "------------------------------------------\n";
    if(rodzaj == 1)
    {
    cout << "Zamowienie oplacone karta platnicza.\n";
    cout << "------------------------------------------\n";
    cout << "Kwota do zaplaty: \t" << sumaDoZaplaty << " zl" << endl;
    }
    else if(rodzaj == 2)
    {
    cout << "Zamowienie oplacone gotowka.\n";
    cout << "------------------------------------------\n";
    cout << "Kwota do zaplaty:    \t" << sumaDoZaplaty << " zl" << endl;
    cout << "Wplacono:      \t\t" << kwota << " zl" << endl;
    cout << "Wydano reszty:   \t" << Reszta(kwota) << " zl" << endl;
    }
    cout << "------------------------------------------\n";
    cout << "Dziekujemy i zapraszamy ponownie!" << endl;
    cout << "\n==========================================" << endl;
    }
};
double Zaplac::kwota = 0;
int Zaplac::rodzaj = 0;

int main() 
{
	Paragon paragonik;
  int jakiDeser;
	while (true) //Petla bedzie powtarzac sie do wybrania poprawnego deseru
	{
		cout << "Dzien dobry!" << endl;
		cout << "Na co masz ochote?" << endl;
		cout << "1 Lody \n2 Gofry \n3 Shake \n4 Smoothie" << endl;
		cin >> jakiDeser;
		if (jakiDeser == 1)
		{
			cout << "Wybrales lody" << endl;
			Lody lody1("Lody");
      lody1.tworzLody();
			break;
		}
		else if (jakiDeser == 2)
		{
			cout << "Wybrales gofry" << endl;
			Gofry gofry1("Gofry");
      gofry1.tworzGofry();
			break;
		}
		else if (jakiDeser == 3)
		{
			cout << "Wybrales shake" << endl;
			Shake shake1;
      shake1.tworzyShake();
			break;
		}
		else if (jakiDeser == 4)
		{
			cout << "Wybrales smoothie" << endl;
			Smoothie smoothie1;
      smoothie1.tworzSmoothie();
			break;
		}
		else
			cout << "Nie posiadam takiego deseru." << endl;
	}


	Zaplac::Zaplata();
	paragonik.wyswietl_paragon();

  
}