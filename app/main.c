#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pytania.h"
#include "wylosujPytanie.h"
#include "linux.h"



int kwoty[12] = {500, 1000, 2000, 5000, 10000, 20000, 40000, 75000, 125000, 250000, 500000, 1000000};

int obecna_kwota, wybor;



pytanie pyt[MAX] = {

             {"Jak nazywa sie stolica Polski?", {"Warszawa", "Krakow", "Gdansk", "Poznan"}, 0},
{"Ktory pierwiastek chemiczny oznacza sie symbolem O?", {"Tlen", "Wodor", "Azot", "Wegiel"}, 0},
{"Ile dni ma rok przestepny?", {"365", "366", "364", "367"}, 1},
{"Ktora planeta jest najblizej Slonca?", {"Mars", "Wenus", "Merkury", "Jowisz"}, 2},
{"Jakie jest najwyzsze pasmo gorskie swiata?", {"Himalaje", "Alpy", "Andy", "Karpaty"}, 0},
{"Kto napisal 'Pana Tadeusza'?", {"Adam Mickiewicz", "Juliusz Slowacki", "Henryk Sienkiewicz", "Boleslaw Prus"}, 0},
{"Ile wynosi liczba pi z dokladnoscia do dwoch miejsc po przecinku?", {"3.12", "3.14", "3.16", "3.18"}, 1},
{"Ktore zwierze jest najwiekszym ssakiem na Ziemi?", {"Slon afrykanski", "Pletwal blekitny", "Nosorozec bialy", "Hipopotam"}, 1},
{"W ktorym roku Polska wstapila do Unii Europejskiej?", {"2000", "2004", "2007", "2010"}, 1},
{"Jakie jest najwieksze jezioro w Polsce?", {"Sniardwy", "Mamry", "Wigry", "Hancza"}, 0},
{"Jakie miasto nazywane jest 'Wiecznym Miastem'?", {"Paryz", "Rzym", "Ateny", "Londyn"}, 1},
{"Kto byl pierwszym krolem Polski?", {"Mieszko I", "Boleslaw Chrobry", "Kazimierz Wielki", "Wladyslaw Lokietek"}, 1},
{"Ktory kolor nie wystepuje na fladze Francji?", {"Czerwony", "Niebieski", "Zielony", "Bialy"}, 2},
{"Ktory kontynent jest najmniejszy pod wzgledem powierzchni?", {"Australia", "Europa", "Ameryka Poludniowa", "Afryka"}, 0},
{"Jak nazywa sie glowna rzeka przeplywajaca przez Egipt?", {"Nil", "Amazonka", "Jangcy", "Ganges"}, 0},
{"Ktora z ponizszych planet nie ma pierscieni?", {"Mars", "Jowisz", "Saturn", "Uran"}, 0},
{"Kto jest autorem teorii wzglednosci?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 1},
{"Ktore z tych miast lezy w USA?", {"Toronto", "Chicago", "Vancouver", "Montreal"}, 1},
{"Jak nazywa sie pierwsza kobieta, ktora poleciala w kosmos?", {"Sally Ride", "Valentina Tierieszkowa", "Peggy Whitson", "Svetlana Savitskaya"}, 1},
{"Ktory jezyk jest najczesciej uzywany na swiecie?", {"Angielski", "Chinski", "Hiszpanski", "Hinduski"}, 1},
{"Ktory kraj slynie z sushi?", {"Chiny", "Korea Poludniowa", "Japonia", "Tajlandia"}, 2},
{"Jakie jest najwieksze panstwo na swiecie pod wzgledem powierzchni?", {"Kanada", "Chiny", "Stany Zjednoczone", "Rosja"}, 3},
{"W ktorym roku wybuchla II wojna swiatowa?", {"1938", "1939", "1940", "1941"}, 1},
{"Jak nazywa sie najwyzszy szczyt w Polsce?", {"Rysy", "Giewont", "Sniezka", "Kasprowy Wierch"}, 0},
{"Ktory ocean jest najwiekszy?", {"Atlantycki", "Indyjski", "Arktyczny", "Spokojny"}, 3},
{"Jakie jest najpopularniejsze warzywo na swiecie?", {"Ziemniak", "Pomidor", "Marchew", "Cebula"}, 1},
{"Ktore miasto jest stolica Wloch?", {"Mediolan", "Florencja", "Neapol", "Rzym"}, 3},
{"Kto namalowal 'Mona Lise'?", {"Vincent van Gogh", "Leonardo da Vinci", "Pablo Picasso", "Rembrandt"}, 1},
{"Jaka walute uzywa sie w Wielkiej Brytanii?", {"Euro", "Dolar", "Funt", "Frank"}, 2},
{"Ktory pierwiastek jest symbolem Fe?", {"Zelazo", "Fluor", "Cyna", "Wegiel"}, 0},
{"Jaka nazwe nosi najdluzsza rzeka w Polsce?", {"Wisla", "Odra", "Bug", "Warta"}, 0},
{"Ktory wynalazca jest kojarzony z zarowka?", {"Thomas Edison", "Nikola Tesla", "Alexander Bell", "James Watt"}, 0},
{"Kto napisal 'Romea i Julie'?", {"William Shakespeare", "Charles Dickens", "Johann Goethe", "Mark Twain"}, 0},
{"Jakie panstwo ma najwieksza populacje?", {"Indie", "Chiny", "USA", "Brazylia"}, 1},
{"Ktore z ponizszych zwierzat to ssak?", {"Zaba", "Rekin", "Delfin", "Aligator"}, 2},
{"Jak nazywa sie najmniejsza planeta w Ukladzie Slonecznym?", {"Mars", "Wenus", "Merkury", "Neptun"}, 2},
{"Ktora substancja jest glownym skladnikiem powietrza?", {"Tlen", "Azot", "Dwutlenek wegla", "Hel"}, 1},
{"Ktore morze lezy na polnoc od Polski?", {"Baltyckie", "Srodziemne", "Czarne", "Polnocne"}, 0},
{"W jakim miescie znajduje sie wieza Eiffla?", {"Londyn", "Berlin", "Paryz", "Madryt"}, 2},
{"Kto jest autorem teorii ewolucji?", {"Charles Darwin", "Isaac Newton", "Albert Einstein", "Gregor Mendel"}, 0},
{"Jak nazywa sie najdluzsza rzeka na swiecie?", {"Amazonka", "Nil", "Missisipi", "Jangcy"}, 0},
{"Jakie jest najwieksze miasto w Polsce pod wzgledem liczby ludnosci?", {"Krakow", "Warszawa", "Wroclaw", "Gdansk"}, 1},
{"Ktora planeta jest znana jako 'Czerwona Planeta'?", {"Merkury", "Mars", "Jowisz", "Saturn"}, 1},
{"Ktory kontynent ma najwiecej panstw?", {"Afryka", "Europa", "Azja", "Ameryka Poludniowa"}, 0},
{"Jak nazywa sie stolica Niemiec?", {"Monachium", "Hamburg", "Berlin", "Kolonia"}, 2},
{"Ile wynosi pierwiastek kwadratowy z 16?", {"2", "3", "4", "5"}, 2},
{"Jak nazywa sie najwiekszy ocean na Ziemi?", {"Atlantycki", "Spokojny", "Indyjski", "Arktyczny"}, 1},
{"Ktora z tych planet nie ma ksiezycow?", {"Merkury", "Wenus", "Ziemia", "Mars"}, 0},
{"Ktore z tych zwierzat jest miesozerne?", {"Kon", "Wilk", "Krowa", "Slon"}, 1},
{"Ktore panstwo jest znane z kangurow?", {"Nowa Zelandia", "Australia", "Kanada", "RPA"}, 1},
{"Ile wynosi 2 podniesione do potegi 5?", {"16", "32", "64", "128"}, 1},
{"Kto byl pierwszym czlowiekiem na Ksiezycu?", {"Yuri Gagarin", "Neil Armstrong", "Buzz Aldrin", "Michael Collins"}, 1},
{"Jak nazywa sie stolica Hiszpanii?", {"Madryt", "Barcelona", "Sewilla", "Walencja"}, 0},
{"Ktory pierwiastek jest symbolem Au?", {"Srebro", "Zloto", "Zelazo", "Platyna"}, 1},
{"Ktora rzeka jest najdluzsza w Europie?", {"Dunaj", "Wolga", "Ren", "Loara"}, 1},
{"Jakie jest najwieksze zwierze ladowe?", {"Nosorozec", "Slon afrykanski", "Zyrafa", "Hipopotam"}, 1},
{"Ktory kontynent jest najzimniejszy?", {"Antarktyda", "Europa", "Ameryka Polnocna", "Azja"}, 0},
{"Kto wynalazl telefon?", {"Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Samuel Morse"}, 0},
{"Jakie jest najwieksze panstwo w Ameryce Poludniowej?", {"Argentyna", "Brazylia", "Chile", "Kolumbia"}, 1},
{"Ktory rok jest uznawany za poczatek ery nowozytnej?", {"476", "1492", "1776", "1914"}, 1},
{"Ktore miasto jest znane jako 'Miasto Swiatla'?", {"Berlin", "Paryz", "Tokio", "Nowy Jork"}, 1},
{"Kto napisal 'Lalka'?", {"Boleslaw Prus", "Henryk Sienkiewicz", "Adam Mickiewicz", "Juliusz Slowacki"}, 0},
{"Jakie jest glowne zrodlo energii na Ziemi?", {"Geotermalna", "Energia Sloneczna", "Energia atomowa", "Energia wodna"}, 1},
{"Jak nazywa sie najwiekszy kontynent?", {"Europa", "Afryka", "Azja", "Ameryka Poludniowa"}, 2},
{"Jak nazywa sie stolica Norwegii?", {"Oslo", "Sztokholm", "Kopenhaga", "Helsinki"}, 0},
{"Ktory sport jest znany jako 'krol sportow'?", {"Pilka nozna", "Lekkoatletyka", "Koszykowka", "Tenis"}, 1},
{"Ile wynosi predkosc swiatla w prozni?", {"299 792 km/s", "300 000 km/s", "150 000 km/s", "299 792 458 m/s"}, 3},
{"Kto byl pierwszym prezydentem Stanow Zjednoczonych?", {"Thomas Jefferson", "Abraham Lincoln", "George Washington", "John Adams"}, 2},
{"Ktory kraj ma najwieksza liczbe wysp?", {"Indonezja", "Norwegia", "Szwecja", "Kanada"}, 0},
{"Ktory kwas znajduje sie w zoladku czlowieka?", {"Kwas cytrynowy", "Kwas siarkowy", "Kwas solny", "Kwas azotowy"}, 2},
{"Jakie jest glowne swieto narodowe w Stanach Zjednoczonych?", {"4 lipca", "1 stycznia", "25 grudnia", "31 grudnia"}, 0},
{"Jak nazywa sie najwiekszy wulkan na Ziemi?", {"Kilimandzaro", "Mount Everest", "Mauna Loa", "Vesuvius"}, 2},
{"Ktora planeta ma najwieksza liczbe ksiezycow?", {"Jowisz", "Saturn", "Uran", "Mars"}, 1},
{"Jaki jest okres obiegu Ziemi wokol Slonca?", {"24 godziny", "365 dni", "28 dni", "12 godzin"}, 1},
{"Kto byl pierwsza kobieta-noblistka?", {"Maria Sklodowska-Curie", "Rosalind Franklin", "Ada Lovelace", "Barbara McClintock"}, 0},
{"Ktore z tych miast lezy w Azji?", {"Buenos Aires", "Kair", "Tokio", "Kapsztad"}, 2},
{"Ktory z tych pierwiastkow jest gazem?", {"Miedz", "Hel", "Wegiel", "Srebro"}, 1},
{"Jak nazywa sie najglebszy kanion swiata?", {"Grand Canyon", "Kanion Colca", "Kanion Yarlung Zangbo", "Kanion Fish River"}, 2},
{"Jakie jest glowne miasto finansowe w USA?", {"Chicago", "Nowy Jork", "San Francisco", "Miami"}, 1},
{"Ktora z tych planet jest gazowym olbrzymem?", {"Mars", "Ziemia", "Jowisz", "Wenus"}, 2},
{"Ktore miasto jest stolica Kanady?", {"Toronto", "Vancouver", "Ottawa", "Montreal"}, 2},
{"Jakie zwierze jest symbolem Australii?", {"Emu", "Kangur", "Koala", "Dingo"}, 1},
{"Ktory kraj jest najwiekszym eksporterem ropy naftowej?", {"Arabia Saudyjska", "Rosja", "USA", "Iran"}, 0},
{"Jak nazywa sie stolica Szwecji?", {"Oslo", "Sztokholm", "Kopenhaga", "Helsinki"}, 1},
{"Ktora rzeka przeplywa przez Londyn?", {"Loara", "Tamiza", "Dunaj", "Ren"}, 1},
{"Ktore z ponizszych panstw lezy na polwyspie Iberyjskim?", {"Wlochy", "Grecja", "Portugalia", "Turcja"}, 2},
{"Ktory metal jest przewodnikiem pradu?", {"Zelazo", "Aluminium", "Srebro", "Wegiel"}, 2},
{"Kto jest autorem obrazu 'Dama z lasiczka'?", {"Pablo Picasso", "Rembrandt", "Leonardo da Vinci", "Vincent van Gogh"}, 2},
{"Ktory kraj ma najwieksza populacje w Europie?", {"Francja", "Niemcy", "Rosja", "Wielka Brytania"}, 2},
{"Jakie zwierze jest uznawane za najszybsze na ladowej powierzchni?", {"Gepard", "Antylopa", "Lew", "Kon"}, 0},
{"Ktory z tych instrumentow nalezy do sekcji detych drewnianych?", {"Tuba", "Klarnet", "Trabka", "Perkusja"}, 1},
{"Kiedy odkryto Ameryke?", {"1492", "1498", "1500", "1512"}, 0},
{"Jak nazywa sie najwyzszy budynek na swiecie?", {"Eiffel Tower", "Burj Khalifa", "Empire State Building", "Shanghai Tower"}, 1},
{"Ktory sport rozgrywany jest na trawie?", {"Golf", "Tenis", "Rugby", "Wszystkie powyzsze"}, 3},
{"Jak nazywa sie glowny bohater w powiesci 'Zbrodnia i kara'?", {"Raskolnikow", "Oblomow", "Szczedrin", "Dostojewski"}, 0},
{"Kto napisal 'Dziady'?", {"Adam Mickiewicz", "Juliusz Slowacki", "Zygmunt Krasinski", "Cyprian Norwid"}, 0},
{"Jakie miasto jest stolica Francji?", {"Lyon", "Marsylia", "Paryz", "Nicea"}, 2},
{"Ktora z planet jest najwieksza w Ukladzie Slonecznym?", {"Jowisz", "Saturn", "Uran", "Neptun"}, 0},
{"Ktory gaz jest najczestszym skladnikiem atmosfery Ziemi?", {"Tlen", "Hel", "Azot", "Dwutlenek wegla"}, 2},
{"Ile kontynentow jest na swiecie?", {"5", "6", "7", "8"}, 2},



};

void tel_do_przyjaciela(pytanie q)
{
    sleep_seconds(2);
    printf("Czesc! Widze, ze bierzesz udzial w programie Milionerzy i potrzebujesz pomocy\n");
    sleep_seconds(2);
    printf("To pytanie wydaje sie byc bardzo trudne. Musisz dac mi chwile\n");
    sleep_seconds(2);
    printf("Wydaje mi sie, ze poprawna odpowiedzi to: %d\n", q.poprawna_odpowiedz + 1);
}

void opinia_publicznosci(pytanie q)
{
    sleep_seconds(2);
    printf("Publicznosc sugeruje, ze poprawna odpowiedz to: %d\n", q.poprawna_odpowiedz + 1);
}


int main()
{
    int tel = 1, publicznosc = 1;

    for (int i = 0; i < 12; i++)
    {
        obecna_kwota = kwoty[i];
        printf("KWOTA O JAKA GRASZ: %d\n", obecna_kwota);
        sleep_seconds(3);
        int nr_pyt = wylosujPytanie();
        zadajPytanie(pyt[nr_pyt]);
        printf("\n");
        printf("Jesli chcesz skorzystac z telefonu do przyjaciela wpisz: 9\n");
        printf("Jesli chcesz spytac publicznosci o opinie wpisz: 8\n");

        int odpowiedz_poprawna = 0;
        while (!odpowiedz_poprawna)
        {
            printf("Podaj odpowiedz: ");
            scanf("%d", &wybor);

            if (wybor == 9)
            {
                if (tel == 1) {
                    tel_do_przyjaciela(pyt[nr_pyt]);
                    tel = 0;
                }
                else {
                    printf("Juz wykorzystales to kolo ratunkowe!");
                }
            }
            else if (wybor == 8)
            {
                if (publicznosc == 1) {
                    opinia_publicznosci(pyt[nr_pyt]);
                    publicznosc = 0;
                }
                else {
                    printf("Juz wykorzystales to kolo ratunkowe!");
                }
            }
            else if (wybor-1 == pyt[nr_pyt].poprawna_odpowiedz)
            {
                odpowiedz_poprawna = 1;
                if (obecna_kwota == 1000000)
                {
                    printf("GRATULACJE!!!\n ZOSTALES MILIONEREM!!!\n");
                    sleep_seconds(3);
                    system("cls");
                }
                else
                {
                    printf("Poprawna odpowiedz! Przechodzisz dalej!\n");
                    sleep_seconds(3);
                    system("cls");
                }
            }
            else if (wybor != 9)
            {
                printf("Niestety twoja odpowiedz nie jest poprawna. Odpadasz z gry.\n");
                printf("Poprawna odpowiedz to: %d\n", pyt[nr_pyt].poprawna_odpowiedz + 1);
                printf("Twoja wygrana to: %d\n", obecna_kwota);
                sleep_seconds(3);
                system("cls");
                return 0;
            }
        }
    }

    system("cls");
    printf("Dziekujemy za udzial w naszej grze!\n");
    sleep_seconds(3);
    return 0;
}