#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "parametry.h"
#include <cstdlib>
#include <sstream>
#include <ctime>
//#include "funkcje.h"

 
using namespace std;


// DATA PLIKU
//------------------------------------------------------------------------------
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y.%m.%d  %X", &tstruct);

    return buf;
}


// GODZINA PLIKU
//------------------------------------------------------------------------------
const string currentDateTimeGodzina() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}


// DATA FOLDERU
//------------------------------------------------------------------------------
const string currentDateTimeFolder() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y.%m.%d", &tstruct);

    return buf;
}


// PAUZA: 1 + CZAS_PAUZY_1
//------------------------------------------------------------------------------
void pauza_1_1(int max_czynnosci) {
                 
int pauza = 1;

while( pauza <= max_czynnosci )
{
    pauza++; 
	Sleep (CZAS_PAUZY_1);
}

}


void SetNumLockState( bool bState )
{
    BYTE keysState[ 256 ];
   
    GetKeyboardState(( LPBYTE ) & keysState );
    if(( bState && !( keysState[ VK_NUMLOCK ] & 1 ) ) ||( !bState &&( keysState[ VK_NUMLOCK ] & 1 ) ) ) //
     //sprawdzenie czy stan klawisza nie odpowiada argumentowi bState, \
     //tj. czy np. nie chcemy wy³¹czyæ Caps Locka podczas gdy jest on ju¿ wy³¹czony.
    {
        keybd_event( VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY, 0 ); //symuluje naciœniêcie klawisza
        keybd_event( VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0 ); //symuluje zwolnienie klawisza
    }
}


int main ()
{       
 
//WY£¥CZANIE - NUM LOCK
//-------------------------------------------------------------------------------- 
  
SetNumLockState( false ); //wy³¹czamy Caps Locka. 
           
       
setlocale( LC_ALL, "Polish" ); 
   
string x;   
int max_czynnosci;   
int a;
int b;
int c;
int os_x;
int os_y;
int max_bompos = 1;
int licznik;

string linia;
string indeks_rodzaj;  
string indeks_nowy;
string indeks_nazwa;
string dokument_nazwa;
string dokument_nazwa_poprzedni_indeks;
string dokument_nazwa_porownanie;
string dokument_rodzaj;
string dokument_wersja;
string dokument_wersja_poprzednia;
string dokument_wersja_poprzedni_indeks;
string tworzenie_dokumentu;
string przypisanie_do_materialu;
string przypisanie_do_specyfikacji;

string folder_pliku = "C:\\Users\\kjelinski\\Documents\\-- DOKUMENTACJA DO ZALOZENIA --\\"; 
string rozszerzenie_pliku = ".pdf";
string sciezka_pliku;

string enter;

string data_start = currentDateTime();

int rozdzielczosc_ekranu;
string rozdzielczosc;
string skalowanie;

int height;
int width;

int height_virtual;
int width_virtual;


do {
    
    
//ROZPOZNAWANIE ROZDZIELCZOŒCI EKRANU
//==============================================================================          
do {

HDC hdc = GetDC(NULL); // get the desktop device context
HDC hDest = CreateCompatibleDC(hdc); // create a device context to use yourself

// get the height && width of the screen
height_virtual = GetSystemMetrics(SM_CYSCREEN); //(SM_CYVIRTUALSCREEN);
width_virtual = GetSystemMetrics(SM_CXSCREEN);  //(SM_CXVIRTUALSCREEN)

height = GetSystemMetrics(SM_CYSCREEN);
width = GetSystemMetrics(SM_CXSCREEN);


if (height_virtual == 864) {
 
skalowanie = "125%";     

height = height_virtual * 125 / 100;
width = width_virtual * 125 / 100;      
          
}

if (height_virtual == 1080) {
 
skalowanie = "100%";  

height = height_virtual * 100 / 100;
width = width_virtual * 125 / 100;          
          
}


} while (height_virtual == 0);
//==============================================================================  
//ROZPOZNAWANIE ROZDZIELCZOŒCI EKRANU


//SPRAWDZANIE PO£O¯ENIA OKNA SAP 
//==============================================================================  
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = PASEK_POLA_GLOWNEGO_OS_X;
os_y = PASEK_POLA_GLOWNEGO_OS_Y;


do {
          

    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
system( "cls" );

cout<<"TWORZENIE I DODAWANIE DOKUMENTACJI: SPRAWDZANIE PO£O¯ENIA OKNA SAP"<<endl;
cout<<"==========================================================================="<<endl;   
cout << a <<" " << b << " " << c << endl;


Sleep (1000);
    

if (KOLOR_NIEBIESKI_2_RGB_2) {    
         
cout<<"==========================================================================="<<endl;
cout<<"PRAWID£OWO PO£O¯ENE OKNA SAP. POTWIERD (t): ";
cin>>enter;

}


}   while (KOLOR_NIEBIESKI_2_RGB_1); 
//==============================================================================
//SPRAWDZANIE PO£O¯ENIA OKNA SAP 
    

system( "cls" ); 






cout<<"TWORZENIE I DODAWANIE DOKUMENTACJI: "<<width<<"x"<<height<<" - "<<width_virtual<<"x"<<height_virtual<<" - "<<skalowanie<<endl;
cout<<"==========================================================================="<<endl;


// WPROWADZANIE DANYCH DO KONSOLI
//------------------------------------------------------------------------------

cout<<"1. Wgraj dokumenty do folderu:"<<endl;
cout<<"   C:\\Users\\kjelinski\\Documents\\-- DOKUMENTACJA DO ZALOZENIA --\\NVW02.pdf"<<endl;


string tworzenie_pliku;
cout<<"2. Tworzenie pliku: PLIK.TXT (t/n): ";
cin>>tworzenie_pliku;

while (tworzenie_pliku != "t" and tworzenie_pliku != "n") {
cout<<"2. Niepoprawny znak. Wpisz ponownie: "; 
cin>>tworzenie_pliku;
} 


// OTWIERANIE PLIKU Z DANYMI
//------------------------------------------------------------------------------
if (tworzenie_pliku == "t") {
          

cout<<"==========================================================================="<<endl;
          
          
// OTWIERANIE PLIKU Z DANYMI
//------------------------------------------------------------------------------
fstream przechwyt_indeks; //obiekt typu fstream (uchwyt do pliku)
przechwyt_indeks.open("indeksy.txt"); //otwieramy plik: plik.txt (plik - nazwa pliku, txt - rozszerzenie)       


fstream plik1; 

string plik1_caly = "plik.txt";
plik1.open(plik1_caly.c_str(), ios::out);


getline(przechwyt_indeks, linia);


licznik = 1;


do {


getline(przechwyt_indeks, linia);


if (linia != "") {


int dlugosc_wiersza = 0;
int xx;
int licznik_znakow;
int licznik_znakow_tab;
string znak;

for( xx = 0; xx < linia.length(); xx++ )
{

dlugosc_wiersza++;

}

//cout<<"DLUGOSC WIERSZA: "<<dlugosc_wiersza<<endl;


//TWORZENIE ZMIENNEJ - RODZAJ MATERIA£U
//==============================================================================
znak = "a";

licznik_znakow = 0;

do {
          
znak = linia.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	");

 
//cout<<i<<endl;
  

string indeks_rodzaj_poczatek = linia;
indeks_rodzaj_poczatek.erase (licznik_znakow,dlugosc_wiersza);

indeks_rodzaj = indeks_rodzaj_poczatek;
  
//cout<<"RODZAJ MATERIALU: "<<indeks_rodzaj<<endl;  
//==============================================================================
  

//TWORZENIE ZMIENNEJ - INDEKS NOWY
//==============================================================================
string indeks_nowy_poczatek = linia;  

licznik_znakow_tab = licznik_znakow +1;

indeks_nowy_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_nowy_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  
string indeks_nowy_koniec = indeks_nowy_poczatek;
indeks_nowy_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_nowy = indeks_nowy_koniec;
  
//cout<<"INDEKS NOWY: "<<indeks_nowy<<endl;  
//==============================================================================
  
  
//TWORZENIE ZMIENNEJ - INDEKS NAZWA
//==============================================================================
string indeks_nazwa_poczatek = indeks_nowy_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

indeks_nazwa_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = indeks_nazwa_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string indeks_nazwa_koniec = indeks_nazwa_poczatek; 
indeks_nazwa_koniec.erase (licznik_znakow,dlugosc_wiersza);

indeks_nazwa = indeks_nazwa_koniec;
  
//cout<<"INDEKS NAZWA: "<<indeks_nazwa<<endl;  
//==============================================================================  
  
  
//TWORZENIE ZMIENNEJ - DOKUMENT NAZWA
//==============================================================================
string dokument_nazwa_poczatek = indeks_nazwa_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

dokument_nazwa_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = dokument_nazwa_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string dokument_nazwa_koniec = dokument_nazwa_poczatek; 
dokument_nazwa_koniec.erase (licznik_znakow,dlugosc_wiersza);

dokument_nazwa = dokument_nazwa_koniec;
  
//cout<<"DOKUMENT NAZWA: "<<dokument_nazwa<<endl;  
//==============================================================================    
  
  
//TWORZENIE ZMIENNEJ - DOKUMENT RODZAJ
//==============================================================================
string dokument_rodzaj_poczatek = dokument_nazwa_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

dokument_rodzaj_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = dokument_rodzaj_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string dokument_rodzaj_koniec = dokument_rodzaj_poczatek; 
dokument_rodzaj_koniec.erase (licznik_znakow,dlugosc_wiersza);

dokument_rodzaj = dokument_rodzaj_koniec;
  
//cout<<"DOKUMENT RODZAJ: "<<dokument_rodzaj<<endl;  
//==============================================================================  

 
//TWORZENIE ZMIENNEJ - DOKUMENT WERSJA
//==============================================================================
string dokument_wersja_poczatek = dokument_rodzaj_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

dokument_wersja_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = dokument_wersja_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string dokument_wersja_koniec = dokument_wersja_poczatek; 
dokument_wersja_koniec.erase (licznik_znakow,dlugosc_wiersza);

if (dokument_nazwa_poprzedni_indeks != dokument_nazwa) { 

dokument_wersja = dokument_wersja_koniec;

}

else {
 
dokument_wersja = dokument_wersja_poprzedni_indeks;  
    
} 
  
//cout<<"DOKUMENT WERSJA: "<<dokument_wersja<<endl;  
//==============================================================================  

 
  

//TWORZENIE ZMIENNEJ - TWORZENIE DOKUEMNTU
//==============================================================================
string tworzenie_dokumentu_poczatek = dokument_wersja_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

tworzenie_dokumentu_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = tworzenie_dokumentu_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string tworzenie_dokumentu_koniec = tworzenie_dokumentu_poczatek; 
tworzenie_dokumentu_koniec.erase (licznik_znakow,dlugosc_wiersza);

tworzenie_dokumentu = tworzenie_dokumentu_koniec;
  
//cout<<"TWORZENIE DOKUEMNTU: "<<tworzenie_dokumentu<<endl;  
//==============================================================================   
  
  
//TWORZENIE ZMIENNEJ - PRZYPISANIE DO MATERIALU
//==============================================================================
string przypisanie_do_materialu_poczatek = tworzenie_dokumentu_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

przypisanie_do_materialu_poczatek.erase (0,licznik_znakow_tab); 
 

znak = "a";

licznik_znakow = 0;

do {
          
znak = przypisanie_do_materialu_poczatek.at(licznik_znakow);

if (znak != "	") {
    
//cout << znak<<endl;
licznik_znakow++;

}

    
} while (znak != "	"); 
  

string przypisanie_do_materialu_koniec = przypisanie_do_materialu_poczatek; 
przypisanie_do_materialu_koniec.erase (licznik_znakow,dlugosc_wiersza);

przypisanie_do_materialu = przypisanie_do_materialu_koniec;
  
//cout<<"PRZYPISANIE DO MATERIALU: "<<przypisanie_do_materialu<<endl;  
//==============================================================================    


//TWORZENIE ZMIENNEJ - PRZYPISANIE DO SPECYFIKACJI
//==============================================================================
string przypisanie_do_specyfikacji_poczatek = przypisanie_do_materialu_poczatek;  

licznik_znakow_tab = licznik_znakow +1;

przypisanie_do_specyfikacji_poczatek.erase (0,licznik_znakow_tab); 

string przypisanie_do_specyfikacji_koniec = przypisanie_do_specyfikacji_poczatek; 
//il_okrzywo_koniec.erase (licznik_znakow,dlugosc_wiersza);

przypisanie_do_specyfikacji = przypisanie_do_specyfikacji_koniec;
  
//cout<<"IL_OKRZYWO: "<<il_okrzywo<<endl;  
//============================================================================== 


plik1 <<"==========================================================================="<<endl;
plik1 <<"INDEKS RODZAJ: "<<indeks_rodzaj<<endl;
plik1 <<"INDEKS NOWY: "<<indeks_nowy<<endl;
plik1 <<"INDEKS NAZWA: "<<indeks_nazwa<<endl;
plik1 <<"DOKUMENT NAZWA: "<<dokument_nazwa<<endl;
plik1 <<"DOKUMENT RODZAJ: "<<dokument_rodzaj<<endl;
plik1 <<"DOKUMENT WERSJA: "<<dokument_wersja<<endl;
plik1 <<"TWORZENIE DOKUMENTU: "<<tworzenie_dokumentu<<endl;
plik1 <<"PRZYPISANIE DO MATERIALU: "<<przypisanie_do_materialu<<endl;
plik1 <<"PRZYPISANIE DO SPECYFIKACJI: "<<przypisanie_do_specyfikacji<<endl;


cout<<licznik++ << ". INDEKS: " <<indeks_nowy<< " - INDEKS NAZWA: "<<indeks_nazwa<< " - DOKUMENT: "<<dokument_nazwa<<endl;

}


}

while (linia != ""); //przerwij je¿eli linia bêdzie pusta (dane w pliku siê skoñcz¹) UWAGA: Pamiêtaj, ¿eby w pliku zostawiæ ostatni¹ linijkê pust¹
przechwyt_indeks.close(); //zamykamy plik


//plik1.close();


cout<<"==========================================================================="<<endl;


}


// OTWIERANIE PLIKU Z DANYMI
//------------------------------------------------------------------------------
    fstream przechwyt; //obiekt typu fstream (uchwyt do pliku)
    przechwyt.open("plik.txt"); //otwieramy plik: plik.txt (plik - nazwa pliku, txt - rozszerzenie)   


// WPROWADZANIE DANYCH DO KONSOLI
//------------------------------------------------------------------------------


cout<<"---------------------------------------------------------------------------"<<endl;
cout<<"A. Czas przerwy miêdzy czynnoœciami (1 = 0,1 sek.- zalecane: 5 (1-9)): ";
cin>>max_czynnosci;


licznik--;


//TWORZENIE FOLDERU
//------------------------------------------------------------------------------
string folder = currentDateTimeFolder();


if (CreateDirectory(folder.c_str(), NULL))
{
    // Directory created
}
else if (ERROR_ALREADY_EXISTS == GetLastError())
{
    // Directory already exists
}
else
{
    // Failed for some other reason
}





int licznik_dokumentacja = 0; 

do {


if (tworzenie_dokumentu != "BRAK") {


licznik_dokumentacja++;   


}      
    
    
    
          
getline(przechwyt, linia);


if (linia != "") {


//POBIERANIE DANYCH Z PLIKU: PLIK.TXT
//------------------------------------------------------------------------------
cout<<"==========================================================================="<<endl;
cout<<"ILOŒÆ INDEKSÓW DO KOÑCA: "<<licznik<<endl;
cout<<"==========================================================================="<<endl;


// TWORZENIE PLIKU: LOG_*.TXT
//------------------------------------------------------------------------------
fstream plik;

string plik_start_tekst = "log_";
string plik_koniec_tekst = ".txt";
string plik_caly = folder + "/" + plik_start_tekst + indeks_nowy + "_" + indeks_nazwa + plik_koniec_tekst;
plik.open(plik_caly.c_str(), ios::out);
  

plik<<"<<<POCZ¥TEK>>"<< endl; 
plik<<" "<< endl; 
plik<<"Data rozpoczêcia: "<<currentDateTime()<<endl;
plik<<"==========================================================================="<< endl;  

//------------------------------------------------------------------------------

getline(przechwyt, indeks_rodzaj);
indeks_rodzaj.erase (0,15);
plik<<"INDEKS RODZAJ: "<<indeks_rodzaj<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, indeks_nowy);
indeks_nowy.erase (0,13);
plik<<"INDEKS NOWY: "<<indeks_nowy<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, indeks_nazwa);
indeks_nazwa.erase (0,14);
plik<<"INDEKS NAZWA: "<<indeks_nazwa<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, dokument_nazwa);
dokument_nazwa.erase (0,16);
plik<<"DOKUMENT NAZWA: "<<dokument_nazwa<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, dokument_rodzaj);
dokument_rodzaj.erase (0,17);
plik<<"DOKUMENT RODZAJ: "<<dokument_rodzaj<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, dokument_wersja);
dokument_wersja.erase (0,17);
//plik<<"DOKUMENT WERSJA: "<<dokument_wersja<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, tworzenie_dokumentu);
tworzenie_dokumentu.erase (0,21);
plik<<"TWORZENIE DOKUMENTU: "<<tworzenie_dokumentu<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, przypisanie_do_materialu);
przypisanie_do_materialu.erase (0,26);
plik<<"PRZYPISANIE DO MATERIALU: "<<przypisanie_do_materialu<<endl;

//------------------------------------------------------------------------------

getline(przechwyt, przypisanie_do_specyfikacji);
przypisanie_do_specyfikacji.erase (0,29);
plik<<"PRZYPISANIE DO SPECYFIKACJI: "<<przypisanie_do_specyfikacji<<endl;

//------------------------------------------------------------------------------


cout<<"INDEKS RODZAJ: "<<indeks_rodzaj<<endl;
cout<<"INDEKS NOWY: "<<indeks_nowy<<endl;
cout<<"INDEKS NAZWA: "<<indeks_nazwa<<endl;
cout<<"DOKUMENT NAZWA: "<<dokument_nazwa<<endl;
cout<<"DOKUMENT RODZAJ: "<<dokument_rodzaj<<endl;
cout<<"DOKUMENT WERSJA: "<<dokument_wersja<<endl;
cout<<"TWORZENIE DOKUMENTU: "<<tworzenie_dokumentu<<endl;
cout<<"PRZYPISANIE DO MATERIALU: "<<przypisanie_do_materialu<<endl;
cout<<"PRZYPISANIE DO SPECYFIKACJI: "<<przypisanie_do_specyfikacji<<endl;


// TWORZENIE PLIKU: WSZYSTKIE_INDEKSY.TXT
//------------------------------------------------------------------------------
ofstream wszystkie_indeksy;

string wszystkie_indeksy_tekst = "wszystkie_indeksy.txt";

string wszystkie_indeksy_caly = folder + "/" + wszystkie_indeksy_tekst;
wszystkie_indeksy.open(wszystkie_indeksy_caly.c_str(), ios::app);
  
  
wszystkie_indeksy <<indeks_nowy<<"	"<<indeks_nazwa<<"	"<<dokument_nazwa<<endl; 


const char* indeks_nowy_tekst = indeks_nowy.c_str();
const char* indeks_nazwa_tekst = indeks_nazwa.c_str();
const char* dokument_nazwa_tekst = dokument_nazwa.c_str();
const char* dokument_nazwa_porownanie_tekst = dokument_nazwa_porownanie.c_str();
const char* dokument_rodzaj_tekst = dokument_rodzaj.c_str();
const char* dokument_wersja_tekst = dokument_wersja.c_str();
const char* dokument_wersja_poprzednia_tekst = dokument_wersja_poprzednia.c_str();
const char* tworzenie_dokumentu_tekst = tworzenie_dokumentu.c_str();
const char* przypisanie_do_materialu_tekst = przypisanie_do_materialu.c_str();
const char* przypisanie_do_specyfikacji_tekst = przypisanie_do_specyfikacji.c_str();


//------------------------------------------------------------------------------
SetCursorPos( PUSTE_POLE_SAP_2 );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);


//TWORZENIE DOUMENTACJI
//===============================================================================================================================================================================

if (tworzenie_dokumentu != "BRAK") {

cout<<"---------------------------------------------------------------------------"<<endl;
cout<<"1. Tworzenie dokumentacji:"<<endl;


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
   
         
do
{     
          
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);
    
    a = rr;
    b = gg;
    c = bb;
   
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//KLIKANIE W OKNO POLECEÑ SAP
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0xBF, 0, 0, 0); // /            
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0); // /


pauza_1_1(max_czynnosci);	


//WCISKANIE - MM01 (TWORZENIE MATERIA£U)
//------------------------------------------------------------------------------
keybd_event(0x43, 0, 0, 0); // C	       
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C
keybd_event(0x56, 0, 0, 0); // V	       
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 
keybd_event(0x30, 0, 0, 0); // 0	       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x31, 0, 0, 0); // 1	       
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1 
keybd_event(0x4E, 0, 0, 0); // N	       
keybd_event(0x4E, 0, KEYEVENTF_KEYUP, 0); // N
    
    
pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------    
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER   


pauza_1_1(max_czynnosci);
    
    
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_2); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_nazwa_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_nazwa_tekst) + 1); //text size + \0 character
    memcpy(dokument_nazwa_zmienna,dokument_nazwa_tekst,strlen(dokument_nazwa_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_nazwa_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);	


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_rodzaj_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_rodzaj_tekst) + 1); //text size + \0 character
    memcpy(dokument_rodzaj_zmienna,dokument_rodzaj_tekst,strlen(dokument_rodzaj_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_rodzaj_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  


pauza_1_1(max_czynnosci);

    
//WCISKANIE - 000
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_wersja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_wersja_tekst) + 1); //text size + \0 character
    memcpy(dokument_wersja_zmienna,dokument_wersja_tekst,strlen(dokument_wersja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_wersja_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER    


pauza_1_1(max_czynnosci*4);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_NOWA_WERSJA_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_NOWA_WERSJA_OS_Y;


    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


if (KOLOR_NIEBIESKI_1_RGB_2) {
          
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  
    
}


pauza_1_1(max_czynnosci*2);  

 
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_WYBOR_OBIEKTU_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_WYBOR_OBIEKTU_OS_Y;


    HDC hdc1 = GetDC(NULL);
    DWORD color1 = GetPixel(hdc1, os_x, os_y);
    unsigned int rr1 = GetRValue(color1);
    unsigned int gg1 = GetGValue(color1);
    unsigned int bb1 = GetBValue(color1);

    a = rr1;
    b = gg1;
    c = bb1;
    
    
pauza_1_1(max_czynnosci);


//cout<<a<<endl;
//cout<<b<<endl;
//cout<<c<<endl;

//cout<<os_x<<endl;
//cout<<os_y<<endl;


if (KOLOR_NIEBIESKI_1_RGB_2) {
                  
     
//WCISKANIE - SHIFT+F9
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x78, 0, 0, 0); // F9       
keybd_event(0x78, 0, KEYEVENTF_KEYUP, 0); // F9
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT       
     
         
pauza_1_1(max_czynnosci);   
  
          
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  
  
}
          

//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_6_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE CTRL+ALT
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	
keybd_event(0x12, 0, 0, 0); // ALT


//WCISKANIE - STRZA£KA W LEWO
//------------------------------------------------------------------------------
keybd_event(0x25, 0, 0, 0); // STRZA£KA W LEWO           
keybd_event(0x25, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W LEWO 
keybd_event(0x25, 0, 0, 0); // STRZA£KA W LEWO           
keybd_event(0x25, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W LEWO
keybd_event(0x25, 0, 0, 0); // STRZA£KA W LEWO           
keybd_event(0x25, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W LEWO


//PUSZCZANIE CTRL+ALT
//------------------------------------------------------------------------------
keybd_event(0x12, 0, KEYEVENTF_KEYUP, 0); // ALT	
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL 


pauza_1_1(max_czynnosci);


//WCISKANIE - LEWY SHIFT+STRZA£KA W PRAWO (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0xA1, 0, 0, 0); // LEWY SHIFT 

pauza_1_1(max_czynnosci);

keybd_event(0x27, 0, 0, 0); // STRZA£KA W PRAWO          
keybd_event(0x27, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W PRAWO
keybd_event(0x27, 0, 0, 0); // STRZA£KA W PRAWO          
keybd_event(0x27, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W PRAWO    

pauza_1_1(max_czynnosci);

keybd_event(0xA1, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT



pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_1_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            dokument_wersja = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


//DOKUMENT WERSJA POPRZEDNIA
//------------------------------------------------------------------------------
plik<<"DOKUMENT WERSJA NOWA: "<<dokument_wersja<<endl;
cout<<"   DOKUMENT WERSJA NOWA: "<<dokument_wersja<<endl;

int dokument_wersja_poprzednia_int;

//ZMIANA STRING NA INT
//------------------------------------------------------------------------------

dokument_wersja_poprzednia_int = atoi(dokument_wersja.c_str());    

if (dokument_wersja_poprzednia_int != 0) {

dokument_wersja_poprzednia_int = dokument_wersja_poprzednia_int - 1;

}

//cout<<"DOKUMENT - WERSJA POPRZEDNIA - INT: "<<dokument_wersja_poprzednia_int<<endl;

//------------------------------------------------------------------------------

ostringstream dokument_wersja_poprzednia_int_2;
dokument_wersja_poprzednia_int_2 << dokument_wersja_poprzednia_int;
string dokument_wersja_poprzednia_string = dokument_wersja_poprzednia_int_2.str();

dokument_wersja_poprzednia = dokument_wersja_poprzednia_string;


if (dokument_wersja_poprzednia == "0" or dokument_wersja_poprzednia == "1" or dokument_wersja_poprzednia == "2" or dokument_wersja_poprzednia == "3" or
    dokument_wersja_poprzednia == "4" or dokument_wersja_poprzednia == "5" or dokument_wersja_poprzednia == "6" or dokument_wersja_poprzednia == "7" or
    dokument_wersja_poprzednia == "8" or dokument_wersja_poprzednia == "9") {

dokument_wersja_poprzednia = "0" + dokument_wersja_poprzednia;                    
                    
}


plik<<"DOKUMENT WERSJA POPRZEDNIA: "<<dokument_wersja_poprzednia<<endl;
cout<<"   DOKUMENT WERSJA POPRZEDNIA: "<<dokument_wersja_poprzednia<<endl;

//------------------------------------------------------------------------------
//DOKUMENT WERSJA POPRZEDNIA


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_nazwa_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_nazwa_tekst) + 1); //text size + \0 character
    memcpy(dokument_nazwa_zmienna,dokument_nazwa_tekst,strlen(dokument_nazwa_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_nazwa_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_DANE_PODSTAWOWE_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_DANE_PODSTAWOWE_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


if (dokument_wersja != "00") {
 
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_1_1(max_czynnosci);     


//WCISKANIE - PAGE DOWN
//------------------------------------------------------------------------------
keybd_event(0x22, 0, 0, 0); // PAGE DOWN
keybd_event(0x22, 0, KEYEVENTF_KEYUP, 0); // PAGE DOWN  


pauza_1_1(max_czynnosci);


keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB               
          

pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_USUWANIE_DOKUMENTACJI_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_USUWANIE_DOKUMENTACJI_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_USUWANIE_DOKUMENTACJI_INFORMACJA_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_USUWANIE_DOKUMENTACJI_INFORMACJA_OS_Y;


    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci*4);


if (KOLOR_NIEBIESKI_1_RGB_2) {
          
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  
    
}


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB


}


else {
          
          
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


}


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_OTWIERANIE_PLIKU_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_OTWIERANIE_PLIKU_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------

sciezka_pliku = folder_pliku + dokument_nazwa + rozszerzenie_pliku;

cout << "   " + sciezka_pliku << endl;

const char* sciezka_pliku_tekst = sciezka_pliku.c_str();


pauza_1_1(max_czynnosci*2);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL sciezka_pliku_zmienna = GlobalAlloc(GMEM_FIXED,strlen(sciezka_pliku_tekst) + 1); //text size + \0 character
    memcpy(sciezka_pliku_zmienna,sciezka_pliku_tekst,strlen(sciezka_pliku_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,sciezka_pliku_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci*2);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_6_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_DODANIE_PLIKU_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_DODANIE_PLIKU_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_7_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - LEWY SHIFT+F2 (ARCHIWIZACJA ORYGINA£U)
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x75, 0, 0, 0); // F6       
keybd_event(0x75, 0, KEYEVENTF_KEYUP, 0); // F6
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT 


pauza_1_1(max_czynnosci);


SetCursorPos( TWORZENIE_DOKUMENTACJI_POTWIEDZENIE_ARCHIWIZACJI );


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_ARCHIWUM_ORYGINALU_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_ARCHIWUM_ORYGINALU_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


cout<<"   DODANO NOWY DOKUMENT"<<dokument_wersja<<endl;


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+S (ZAPISANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x53, 0, 0, 0); // S	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S    


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = ZNACZEK_POLA_GLOWNEGO_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_ZIELONY_1_RGB_1); 	
//------------------------------------------------------------------------------

//TWORZENIE DOUMENTACJI
//===============================================================================================================================================================================


pauza_1_1(max_czynnosci*2);


//ZMIANA DOUMENTACJI - FR
//===============================================================================================================================================================================

//WCISKANIE - CTRL+F4 (ZMIANA DOKUMENTU)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x73, 0, 0, 0); // F4	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x73, 0, KEYEVENTF_KEYUP, 0); // F4   
          

pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_DOKUMENTACJI_EKRAN_POCZATKOWY_OS_X;
os_y = ZMIANA_DOKUMENTACJI_EKRAN_POCZATKOWY_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_3_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_DOKUMENTACJI_OS_X;
os_y = ZMIANA_DOKUMENTACJI_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_6_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_1_1(max_czynnosci);


//WCISKANIE - FR
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x46, 0, 0, 0); // F
keybd_event(0x46, 0, KEYEVENTF_KEYUP, 0); //F 
keybd_event(0x52, 0, 0, 0); // R
keybd_event(0x52, 0, KEYEVENTF_KEYUP, 0); //R 
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT  


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_DOKUMENTACJI_DANE_PODSTAWOWE_OS_X;
os_y = TWORZENIE_DOKUMENTACJI_DANE_PODSTAWOWE_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = ZNACZEK_POLA_GLOWNEGO_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_ZIELONY_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci*4);


//WCISKANIE - CTRL+S (ZAPISANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x53, 0, 0, 0); // S	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S    


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = ZNACZEK_POLA_GLOWNEGO_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_ZIELONY_1_RGB_1); 	
//------------------------------------------------------------------------------

//ZMIANA DOUMENTACJI - FR
//===============================================================================================================================================================================


pauza_1_1(max_czynnosci*2);


//ZMIANA DOKUMENTU - ZABLOKOWANIE WERSJI POPRZEDNIEJ
//===============================================================================================================================================================================

if (dokument_wersja != "00") {
                    
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB      
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  


pauza_1_1(max_czynnosci);


const char* dokument_wersja_poprzednia_tekst = dokument_wersja_poprzednia.c_str();

//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_wersja_poprzednia_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_wersja_poprzednia_tekst) + 1); //text size + \0 character
    memcpy(dokument_wersja_poprzednia_zmienna,dokument_wersja_poprzednia_tekst,strlen(dokument_wersja_poprzednia_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_wersja_poprzednia_zmienna);
        CloseClipboard();
    }
}


//cout<<"   DOKUMENT WERSJA POPRZEDNIA: "<<dokument_wersja_poprzednia<<endl;


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_DOKUMENTACJI_OS_X;
os_y = ZMIANA_DOKUMENTACJI_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_6_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - FR
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x5A, 0, 0, 0); // Z
keybd_event(0x5A, 0, KEYEVENTF_KEYUP, 0); // Z 
keybd_event(0x42, 0, 0, 0); // B
keybd_event(0x42, 0, KEYEVENTF_KEYUP, 0); // B
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT  


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = ZNACZEK_POLA_GLOWNEGO_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_ZIELONY_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci*4);


//WCISKANIE - CTRL+S (ZAPISANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x53, 0, 0, 0); // S	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S    


pauza_1_1(max_czynnosci);
    
               
}


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = ZNACZEK_POLA_GLOWNEGO_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_ZIELONY_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);


//WCISKANIE - F3 (POWRACANIE)
//------------------------------------------------------------------------------
keybd_event(0x72, 0, 0, 0); // F3
keybd_event(0x72, 0, KEYEVENTF_KEYUP, 0); // F3


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
   
         
do
{     
          
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);
    
    a = rr;
    b = gg;
    c = bb;
   
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_1); 	
//------------------------------------------------------------------------------

}

//ZMIANA DOKUMENTU - ZABLOKOWANIE WERSJI POPRZEDNIEJ
//===============================================================================================================================================================================


//PRZYPISANIE DOKUMENTACJI DO MATERIA£U
//===============================================================================================================================================================================

if (przypisanie_do_materialu != "BRAK") {
          

//KLIKANIE W OKNO POLECEÑ SAP
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0xBF, 0, 0, 0); // /            
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0); // /


pauza_1_1(max_czynnosci);	


//WCISKANIE - MM01 (TWORZENIE MATERIA£U)
//------------------------------------------------------------------------------
keybd_event(0x4D, 0, 0, 0); // M	       
keybd_event(0x4D, 0, KEYEVENTF_KEYUP, 0); // M
keybd_event(0x4D, 0, 0, 0); // M	       
keybd_event(0x4D, 0, KEYEVENTF_KEYUP, 0); // M  
keybd_event(0x30, 0, 0, 0); // 0	       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x32, 0, 0, 0); // 2	       
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2 
    
    
pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------    
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER   
    
    
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
         
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_2); 	
//------------------------------------------------------------------------------ 
          

pauza_1_1(max_czynnosci);      
       
       
//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_nowy_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_nowy_tekst) + 1); //text size + \0 character
    memcpy(indeks_nowy_zmienna,indeks_nowy_tekst,strlen(indeks_nowy_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_nowy_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);
       
       
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER         
 
 
pauza_1_1(max_czynnosci);


//ZMIANA MATERIA£U - WYBÓR WGL¥DÓW
//------------------------------------------------------------------------------

//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_MATERIALU_WYBOR_WGLADOW_OS_X;
os_y = TWORZENIE_MATERIALU_WYBOR_WGLADOW_OS_Y;
       
         
do
{           
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);


    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------
    
    
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 


pauza_1_1(max_czynnosci);         
       
       
//ZMIANA MATERIA£U - POZIOMY ORGANIZACYJNE
//------------------------------------------------------------------------------

//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_MATERIALU_POZIOMY_ORGANIZACYJNE_OS_X;
os_y = TWORZENIE_MATERIALU_POZIOMY_ORGANIZACYJNE_OS_Y;
   
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


//WCISKANIE - Y001
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x59, 0, 0, 0); // Y       
keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0); // Y
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT  
keybd_event(0x30, 0, 0, 0); // 0       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x31, 0, 0, 0); // 1       
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1  


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB


pauza_1_1(max_czynnosci);     
       
       
//WCISKANIE - BACKSPACE
//------------------------------------------------------------------------------
keybd_event(0x08, 0, 0, 0); // BACKSPACE            
keybd_event(0x08, 0, KEYEVENTF_KEYUP, 0); // BACKSPACE        
       
       
pauza_1_1(max_czynnosci);  


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER        
       
       
pauza_1_1(max_czynnosci);	

//ZMIANA MATERIA£U - DANE PODSTAWOWE_1	
//------------------------------------------------------------------------------

//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = TWORZENIE_MATERIALU_DANE_PODSTAWOWE_1_OS_X;
os_y = TWORZENIE_MATERIALU_DANE_PODSTAWOWE_1_OS_Y;
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_NIEBIESKI_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);	


//WCISKANIE - CTRL+F6 (PRZEJŒCIE DO: DANE DODATKOWE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL
keybd_event(0x75, 0, 0, 0); // F6	  
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x75, 0, KEYEVENTF_KEYUP, 0); // F6 


pauza_1_1(max_czynnosci);       
       
       
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_MATERIALU_DANE_DODATKOWE_OS_X;
os_y = ZMIANA_MATERIALU_DANE_DODATKOWE_OS_Y;
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_4_RGB_1); 	
//------------------------------------------------------------------------------       
       

pauza_1_1(max_czynnosci);   

       
//WCISKANIE - F8 (PRZEJŒCIE DO: DANE DOKUMENTU)
//------------------------------------------------------------------------------
keybd_event(0x77, 0, 0, 0); // F8	    
keybd_event(0x77, 0, KEYEVENTF_KEYUP, 0); // F8        
       
       
pauza_1_1(max_czynnosci);         
       
       
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_MATERIALU_DANE_DODATKOWE_DANE_DOKUMENTU_OS_X;
os_y = ZMIANA_MATERIALU_DANE_DODATKOWE_DANE_DOKUMENTU_OS_Y;
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);

    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_4_RGB_1); 	
//------------------------------------------------------------------------------            
       
       
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+TAB
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------    
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_rodzaj_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_rodzaj_tekst) + 1); //text size + \0 character
    memcpy(dokument_rodzaj_zmienna,dokument_rodzaj_tekst,strlen(dokument_rodzaj_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_rodzaj_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);         
       
       
//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_nazwa_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_nazwa_tekst) + 1); //text size + \0 character
    memcpy(dokument_nazwa_zmienna,dokument_nazwa_tekst,strlen(dokument_nazwa_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_nazwa_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);        
       
       
//WCISKANIE - 000
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);               
       
       
//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_wersja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_wersja_tekst) + 1); //text size + \0 character
    memcpy(dokument_wersja_zmienna,dokument_wersja_tekst,strlen(dokument_wersja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_wersja_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);              
       
       
//WCISKANIE - ENTER
//------------------------------------------------------------------------------    
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);       


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_MATERIALU_DANE_DODATKOWE_DANE_DOKUMENTU_ZAPIS_OS_X;
os_y = ZMIANA_MATERIALU_DANE_DODATKOWE_DANE_DOKUMENTU_ZAPIS_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_CZERWONY_1_RGB_1); 	
//------------------------------------------------------------------------------  
       
       
pauza_1_1(max_czynnosci); 


//WCISKANIE - CTRL+S (ZAPISANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x53, 0, 0, 0); // S	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S    


pauza_1_1(max_czynnosci);        
       
       
//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = ZNACZEK_POLA_GLOWNEGO_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_ZIELONY_1_RGB_1); 	
//------------------------------------------------------------------------------


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - F3 (POWRACANIE)
//------------------------------------------------------------------------------
keybd_event(0x72, 0, 0, 0); // F3
keybd_event(0x72, 0, KEYEVENTF_KEYUP, 0); // F3


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
   
         
do
{     
          
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);
    
    a = rr;
    b = gg;
    c = bb;
   
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_1); 	
//------------------------------------------------------------------------------         
          
}
//PRZYPISANIE DOKUMENTACJI DO MATERIA£U
//===============================================================================================================================================================================


pauza_1_1(max_czynnosci);


//PRZYPISANIE DOKUMENTACJI DO MATERIA£U
//===============================================================================================================================================================================

if (przypisanie_do_specyfikacji != "BRAK") {
 
//KLIKANIE W OKNO POLECEÑ SAP
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0xBF, 0, 0, 0); // /            
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0); // /
    
    
pauza_1_1(max_czynnosci);    


//WCISKANIE - CS02
//------------------------------------------------------------------------------
keybd_event(0x43, 0, 0, 0); // C	       
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 
keybd_event(0x53, 0, 0, 0); // S	       
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S 
keybd_event(0x30, 0, 0, 0); // 0	       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x32, 0, 0, 0); // 2	       
keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0); // 2 
    
    
pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
    
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
    
    a = rr;
    b = gg;
    c = bb;
  
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_2); 	
//------------------------------------------------------------------------------


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL indeks_nowy_zmienna = GlobalAlloc(GMEM_FIXED,strlen(indeks_nowy_tekst) + 1); //text size + \0 character
    memcpy(indeks_nowy_zmienna,indeks_nowy_tekst,strlen(indeks_nowy_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,indeks_nowy_zmienna);
        CloseClipboard();
    }
}

    
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V   

	
pauza_1_1(max_czynnosci);


//WCISKANIE - TAB   
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_1_1(max_czynnosci);	
 
 
//WCISKANIE - Y001
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x59, 0, 0, 0); // Y	       
keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0); // Y
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT  
keybd_event(0x30, 0, 0, 0); // 0	       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	       
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x31, 0, 0, 0); // 1	       
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1 


pauza_1_1(max_czynnosci);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 

	
pauza_1_1(max_czynnosci);
	

if (indeks_rodzaj != "50") {

//WCISKANIE - 1
//------------------------------------------------------------------------------	
keybd_event(0x31, 0, 0, 0); // 1	       
keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0); // 1 	

}

else {
          
//WCISKANIE - 3
//------------------------------------------------------------------------------	
keybd_event(0x33, 0, 0, 0); // 3	       
keybd_event(0x33, 0, KEYEVENTF_KEYUP, 0); // 3           
          
}

	
pauza_1_1(max_czynnosci);
 
 
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER 
 

pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_X;
os_y = ZMIANA_SPECYFIKACJI_MATERIALOWEJ_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_4_RGB_1); 	
//------------------------------------------------------------------------------ 


pauza_1_1(max_czynnosci);


//KLIKANIE W ZAK£ADKÊ - DOKUMENT
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_SPECYFIKACJI_ZAKLADKA_DOKUMENT ); 
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);

 
pauza_1_1(max_czynnosci); 
 
 
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  
 
 
pauza_1_1(max_czynnosci);


//WCISKANIE - ALT+E
//------------------------------------------------------------------------------
keybd_event(0x12, 0, 0, 0); // ALT
keybd_event(0x45, 0, 0, 0); // E	 
keybd_event(0x45, 0, KEYEVENTF_KEYUP, 0); // E 	
keybd_event(0x12, 0, KEYEVENTF_KEYUP, 0); // ALT


pauza_1_1(max_czynnosci);


//WCISKANIE - STRZA£KA W DÓ£
//------------------------------------------------------------------------------
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£     
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci);


//WCISKANIE - STRZA£KA W DÓ£
//------------------------------------------------------------------------------
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 


pauza_1_1(max_czynnosci);


//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  


pauza_1_1(max_czynnosci*4);


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB
	

pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_1_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            dokument_nazwa_porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


pauza_1_1(max_czynnosci);


if (dokument_nazwa_porownanie == dokument_nazwa) {
    
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_wersja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_wersja_tekst) + 1); //text size + \0 character
    memcpy(dokument_wersja_zmienna,dokument_wersja_tekst,strlen(dokument_wersja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_wersja_zmienna);
        CloseClipboard();
    }
} 

  
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V    


pauza_1_1(max_czynnosci);              
 
 
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  

}


if (dokument_nazwa_porownanie != dokument_nazwa && dokument_nazwa_porownanie != indeks_nowy ) {
 
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+A (ZAZNACZANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	     
keybd_event(0x41, 0, 0, 0); // A	   
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL  
keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0); // A  


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+C (KOPIOWANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x43, 0, 0, 0); // C	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0); // C 


pauza_1_1(max_czynnosci);


//KOPIOWANIE ZE SCHOWKA DO ZMIENNEJ
//------------------------------------------------------------------------------
#ifdef _WIN32
    if(OpenClipboard(NULL))
    {
        HANDLE data = GetClipboardData(CF_TEXT);
        if(data)
        {
            dokument_nazwa_porownanie = reinterpret_cast<char *>(GlobalLock(data));
            GlobalUnlock(data);
        }
        CloseClipboard();
    }
#endif


pauza_1_1(max_czynnosci);


if (dokument_nazwa_porownanie == dokument_nazwa) {
    
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB 


pauza_1_1(max_czynnosci);


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_wersja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_wersja_tekst) + 1); //text size + \0 character
    memcpy(dokument_wersja_zmienna,dokument_wersja_tekst,strlen(dokument_wersja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_wersja_zmienna);
        CloseClipboard();
    }
} 

  
pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V - WKLEJANIE
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL 
keybd_event(0x56, 0, 0, 0); // V           
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V    


pauza_1_1(max_czynnosci);              
 
 
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  

}

}


if (dokument_nazwa_porownanie == indeks_nowy) {
    
//KLIKANIE W POZYCJE
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_DOKUMENT_POZYCJA );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);    


pauza_1_1(max_czynnosci); 

 
//WCISKANIE - F5
//------------------------------------------------------------------------------
keybd_event(0x74, 0, 0, 0); // F5
keybd_event(0x74, 0, KEYEVENTF_KEYUP, 0); // F5 
 
 
pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB   
 
 
pauza_1_1(max_czynnosci); 


//WCISKANIE - D
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x44, 0, 0, 0); // D	 
keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0); // D 
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT    


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB   


pauza_1_1(max_czynnosci); 

      
//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_nazwa_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_nazwa_tekst) + 1); //text size + \0 character
    memcpy(dokument_nazwa_zmienna,dokument_nazwa_tekst,strlen(dokument_nazwa_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_nazwa_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);  


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_rodzaj_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_rodzaj_tekst) + 1); //text size + \0 character
    memcpy(dokument_rodzaj_zmienna,dokument_rodzaj_tekst,strlen(dokument_rodzaj_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_rodzaj_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);               
       
       
//WCISKANIE - 000
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);               
       
       
//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_wersja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_wersja_tekst) + 1); //text size + \0 character
    memcpy(dokument_wersja_zmienna,dokument_wersja_tekst,strlen(dokument_wersja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_wersja_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);              
 
 
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  

}





/*
else {
    
//KLIKANIE W POZYCJE
//------------------------------------------------------------------------------
SetCursorPos( ZMIANA_MATERIALU_ZAKLADKA_DOKUMENT_POZYCJA );
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0,0,0,0);    


pauza_1_1(max_czynnosci); 

 
//WCISKANIE - F5
//------------------------------------------------------------------------------
keybd_event(0x74, 0, 0, 0); // F5
keybd_event(0x74, 0, KEYEVENTF_KEYUP, 0); // F5 
 
 
pauza_1_1(max_czynnosci); 
 

//WCISKANIE - STRZA£KA W DÓ£
//------------------------------------------------------------------------------	
keybd_event(0x28, 0, 0, 0); // STRZA£KA W DÓ£           
keybd_event(0x28, 0, KEYEVENTF_KEYUP, 0); // STRZA£KA W DÓ£ 


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB  
 
 
pauza_1_1(max_czynnosci); 


//WCISKANIE - D
//------------------------------------------------------------------------------
keybd_event(0xA0, 0, 0, 0); // LEWY SHIFT 
keybd_event(0x44, 0, 0, 0); // D	 
keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0); // D 
keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0); // LEWY SHIFT    


pauza_1_1(max_czynnosci); 


//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB   


pauza_1_1(max_czynnosci); 

      
//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_nazwa_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_nazwa_tekst) + 1); //text size + \0 character
    memcpy(dokument_nazwa_zmienna,dokument_nazwa_tekst,strlen(dokument_nazwa_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_nazwa_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);  


//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_rodzaj_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_rodzaj_tekst) + 1); //text size + \0 character
    memcpy(dokument_rodzaj_zmienna,dokument_rodzaj_tekst,strlen(dokument_rodzaj_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_rodzaj_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);               
       
       
//WCISKANIE - 000
//------------------------------------------------------------------------------
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 
keybd_event(0x30, 0, 0, 0); // 0	 
keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0); // 0 


pauza_1_1(max_czynnosci);       
       
       
//WCISKANIE - TABULACJA
//------------------------------------------------------------------------------
keybd_event(0x09, 0, 0, 0); // TAB	 
keybd_event(0x09, 0, KEYEVENTF_KEYUP, 0); // TAB         
    
      
pauza_1_1(max_czynnosci);               
       
       
//POBIERANIE ZMIENNEJ DO SCHOWKA
//------------------------------------------------------------------------------
{
    HGLOBAL dokument_wersja_zmienna = GlobalAlloc(GMEM_FIXED,strlen(dokument_wersja_tekst) + 1); //text size + \0 character
    memcpy(dokument_wersja_zmienna,dokument_wersja_tekst,strlen(dokument_wersja_tekst));  //text size + \0 character
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,dokument_wersja_zmienna);
        CloseClipboard();
    }
}


pauza_1_1(max_czynnosci);


//WCISKANIE - CTRL+V (WKLEJANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CRTL
keybd_event(0x56, 0, 0, 0); // V	 
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CRTL  
keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0); // V 


pauza_1_1(max_czynnosci);              
 
 
//WCISKANIE - ENTER
//------------------------------------------------------------------------------
keybd_event(0x0D, 0, 0, 0); // ENTER
keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0); // ENTER  

}
*/

 
pauza_1_1(max_czynnosci*4);  


//WCISKANIE - CTRL+S (ZAPISANIE)
//------------------------------------------------------------------------------
keybd_event(0x11, 0, 0, 0); // CTRL	    
keybd_event(0x53, 0, 0, 0); // S	    
keybd_event(0x11, 0, KEYEVENTF_KEYUP, 0); // CTRL   
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0); // S    


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = ZNACZEK_POLA_GLOWNEGO_OS_X;
os_y = ZNACZEK_POLA_GLOWNEGO_OS_Y;
       
         
do
{           
	HDC hdc = GetDC(NULL);
	DWORD color = GetPixel(hdc, os_x, os_y);
	unsigned int rr = GetRValue(color);
	unsigned int gg = GetGValue(color);
	unsigned int bb = GetBValue(color);
	
    a = rr;
    b = gg;
    c = bb;
    
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_ZIELONY_1_RGB_1); 	
//------------------------------------------------------------------------------ 
 
 
pauza_1_1(max_czynnosci);


//WCISKANIE - F3 (POWRACANIE)
//------------------------------------------------------------------------------
keybd_event(0x72, 0, 0, 0); // F3
keybd_event(0x72, 0, KEYEVENTF_KEYUP, 0); // F3


pauza_1_1(max_czynnosci);


//ROZPOZNANIE KOLORU
//------------------------------------------------------------------------------
os_x = STRZALKA_POLA_GLOWNEGO_OS_X;
os_y = STRZALKA_POLA_GLOWNEGO_OS_Y;
   
         
do
{     
          
    HDC hdc = GetDC(NULL);
    DWORD color = GetPixel(hdc, os_x, os_y);
    unsigned int rr = GetRValue(color);
    unsigned int gg = GetGValue(color);
    unsigned int bb = GetBValue(color);
    
    a = rr;
    b = gg;
    c = bb;
   
    
pauza_1_1(max_czynnosci);


}   while (KOLOR_SZARY_2_RGB_1); 	
//-----------------------------------------------------------------------------

         
}

//PRZYPISANIE DOKUMENTACJI DO MATERIA£U
//===============================================================================================================================================================================


dokument_nazwa_poprzedni_indeks = dokument_nazwa;
dokument_wersja_poprzedni_indeks = dokument_wersja;

plik<<"==========================================================================="<<endl;
//------------------------------------------------------------------------------
//ZMIANA MARSZRUTY TECHNOLOGICZNEJ

	
string data_koniec = currentDateTime();	

plik<< "Data zakoñczenia: "<< currentDateTime() <<endl;   
plik<< " " <<endl;
plik<< "<<<KONIEC>>>";
plik.close();


licznik--;


}


else {
    
cout<<"---------------------------------------------------------------------------"<<endl;
cout<<"BRAK DANYCH"<<endl;   
cout<<"---------------------------------------------------------------------------"<<endl; 
  
}


}


while (linia != ""); //przerwij je¿eli linia bêdzie pusta (dane w pliku siê skoñcz¹) UWAGA: Pamiêtaj, ¿eby w pliku zostawiæ ostatni¹ linijkê pust¹
przechwyt.close(); //zamykamy plik

	
cout<<" "<<endl;
cout<<"Powtórzyæ program (t/n): ";
cin>>x;


while (x != "t" and x != "n") {
cout<<"Niepoprawny znak. Wpisz ponownie: "; 
cin>>x;
} 


}
 
       
while( x == "t" );
    

if( x != "t" )
{
        
Sleep (CZAS_PAUZY_3);
cout<<" "<<endl;
cout<<"Koniec programu"<<endl;
       
}


fstream wszystkie_indeksy;
wszystkie_indeksy.close();


Sleep(100000);	
 
 
cin.get();
return 0;


}
