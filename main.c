#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// Görsel bar çizdirmek için yardýmcý fonksiyon
void durumCubuguCiz(char* etiket, int mevcut, int maks) {
    int i;
    int barUzunlugu = 20;
    int doluKisim = (mevcut * barUzunlugu) / maks;

    printf("%-10s: [", etiket);

    for (i = 0; i < barUzunlugu; i++) {
        if (i < doluKisim)
            printf("#");
        else
            printf("-");
    }
    printf("] %d/%d\n", mevcut, maks);
}

int main() {
    // --- DEGISKEN TANIMLAMALARI ---
    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0;
    char komut;
    char sonMesaj[200] = "Oyun basladi. Hayatta kalmaya calis!";

    // Ara degiskenler
    int i;
    int sans;
    int hasar;
    int toplamHasar;
    int girilenSifre;

    srand(time(NULL));

    printf("=== HAYATTA KALMA SIMULATORU ===\n");

    // OYUN DÖNGÜSÜ
    do {
        // --- EKRAN GÜNCELLEME ---
        printf("\n\n\n");
        printf("==========================================\n");
        printf(">> DURUM RAPORU <<\n");
        durumCubuguCiz("SAGLIK", saglik, 100);
        durumCubuguCiz("ENERJI", enerji, 100);
        printf("YEMEK     : %d Adet\n", yemek);
        if (siginak == 1)
            printf("SIGINAK   : VAR (Guvendesin)\n");
        else
            printf("SIGINAK   : YOK (Tehlikedesin)\n");

        printf("==========================================\n");

        printf("SON OLAY: %s\n", sonMesaj);
        printf("------------------------------------------\n");
        printf("KOMUTLAR: [A]vlan [S]iginak [R]Dinlen [F]Tehlike [P]Sifre [X]Cikis\n");
        printf("Ne yapacaksin? >> ");

        scanf(" %c", &komut);
        komut = toupper(komut);

        // --- MANTIK KISMI ---
        switch (komut) {
            case 'A': // Avlan
                if (enerji >= 20) {
                    enerji -= 15;
                    sans = rand() % 100;

                    if (sans > 40 || (saglik > 80 && sans > 20)) {
                        yemek++;
                        sprintf(sonMesaj, "Basarili! Avlandin ve yemek buldun. (-15 Enerji)");
                    } else {
                        saglik -= 5;
                        sprintf(sonMesaj, "Avlanma basarisiz. Yaralandin. (-5 Saglik, -15 Enerji)");
                    }
                } else {
                    sprintf(sonMesaj, "Yetersiz enerji! Avlanmak icin en az 20 enerji lazim.");
                }
                break;

            case 'S': // Sýðýnak
                if (siginak == 1) {
                    sprintf(sonMesaj, "Zaten bir siginagin var!");
                } else {
                    if (enerji > 10 && (rand() % 100 < 50)) {
                        siginak = 1;
                        enerji -= 10;
                        sprintf(sonMesaj, "Tebrikler! Guvenli bir siginak buldun.");
                    } else {
                        enerji -= 10;
                        sprintf(sonMesaj, "Siginak aradin ama bulamadin. (-10 Enerji)");
                    }
                }
                break;

            case 'R': // Dinlen
                if (siginak == 1) {
                    enerji += 30;
                    saglik += 10;
                    sprintf(sonMesaj, "Siginakta guzelce uyudun. (+30 Enerji, +10 Saglik)");
                } else {
                    enerji += 15;
                    sprintf(sonMesaj, "Disarida titreyerek uyudun. (+15 Enerji)");
                }

                if (enerji > 100) enerji = 100;
                if (saglik > 100) saglik = 100;
                break;

            case 'F': // Tehlike (GÜNCELLENDÝ: ÖDÜL EKLENDÝ)
                toplamHasar = 0;
                printf("\n--- TEHLIKE SALDIRISI BASLADI! ---\n");

                // For döngüsü ile 3 dalga saldýrý
                for (i = 1; i <= 3; i++) {
                    hasar = rand() % 15; // 0 ile 14 arasý hasar ihtimali
                    if (hasar > 5) {
                        saglik -= hasar;
                        toplamHasar += hasar;
                        printf("%d. Dalga: %d hasar aldin!\n", i, hasar);
                    } else {
                        printf("%d. Dalga: Iska gecti.\n", i);
                    }
                    if (saglik <= 0) break; // Ölürse döngüden çýk
                }

                // --- ÖDÜL KONTROLÜ ---
                if (saglik > 0) {
                    // Eðer hayatta kaldýysa ödül ver
                    yemek += 1;
                    enerji += 10;
                    if (enerji > 100) enerji = 100;

                    // Son mesajý güncelle
                    sprintf(sonMesaj, "Saldiriyi atlattin! GANIMET BULUNDU: +1 Yemek, +10 Enerji. (Hasar: %d)", toplamHasar);
                } else {
                    sprintf(sonMesaj, "Saldiri sirasinda hayatini kaybettin...");
                }
                break;

            case 'P': // Þifre
                printf("\n--- KILITLI KAPI ---\n");
                do {
                    printf("Sifreyi coz (Ipucu: 1234): ");
                    scanf("%d", &girilenSifre);
                    if (girilenSifre != 1234) printf("Yanlis sifre!\n");
                } while (girilenSifre != 1234);

                yemek += 2;
                sprintf(sonMesaj, "Sifreyi cozdun ve 2 adet erzak buldun!");
                break;

            case 'X':
                sprintf(sonMesaj, "Cikis yapiliyor...");
                break;

            default:
                sprintf(sonMesaj, "Gecersiz bir komut girdin.");
        }

        if (saglik <= 0) {
            printf("\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
            printf("   OLDU! HAYATTA KALAMADIN.\n");
            printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
            break;
        }

    } while (komut != 'X');

    printf("\nCikmak icin bir tusa basin...");
    // getchar(); getchar();

    return 0;
}
