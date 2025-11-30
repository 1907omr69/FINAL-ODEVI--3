# Hayatta Kalma Simülatörü

Bu proje, tamamen C dili kullanılarak geliştirilmiş basit bir **konsol
tabanlı hayatta kalma oyunu** içerir.\
Oyuncu sağlık, enerji, yemek ve barınak gibi kaynakları yöneterek mümkün
olduğunca uzun süre hayatta kalmaya çalışır.

------------------------------------------------------------------------

## 🎮 Oyun Özellikleri

-   **Sağlık ve Enerji Yönetimi:**\
    Karakterin sağlık ve enerji seviyeleri sürekli olarak takip edilir.
    Bazı eylemler enerji harcar, bazıları sağlık kaybettirir.

-   **Avlanma Sistemi:**\
    Enerjin yeterliyse avlanabilir, yemek bulabilir veya başarısız olup
    hasar alabilirsin.

-   **Barınak Kurma:**\
    Sığınak bulabilirsen daha güvenli dinlenirsin. Aksi halde risk
    altındasın.

-   **Dinlenme Mekaniği:**\
    Sığınakta dinlenmek daha verimlidir.

-   **Tehlike Sistemi (3 Dalgalı Saldırı):**\
    Üç dalga hâlinde gelen saldırılara dayanırsan ganimet kazanırsın.

-   **Şifre Mini Oyunu:**\
    Basit bir kapı şifresi çözülerek ek erzak elde edilir.

------------------------------------------------------------------------

## 📁 Dosya Yapısı

-   `main.c` --- Oyunun tüm kaynak kodunu içerir.

------------------------------------------------------------------------

## 🚀 Derleme ve Çalıştırma

### Linux / MacOS

``` bash
gcc main.c -o hayatta_kalma
./hayatta_kalma
```

### Windows (MinGW)

``` bash
gcc main.c -o hayatta_kalma.exe
hayatta_kalma.exe
```

------------------------------------------------------------------------

## ⌨️ Komutlar

  Komut   Açıklama
  ------- -----------------
  **A**   Avlan
  **S**   Sığınak ara
  **R**   Dinlen
  **F**   Tehlike dalgası
  **P**   Şifre çöz
  **X**   Çıkış

------------------------------------------------------------------------

## 📊 Durum Çubukları

Oyun, sağlık ve enerji seviyelerini görsel bir bar şeklinde gösterir:

    SAGLIK   : [##########--------] 50/100
    ENERJI   : [##############----] 75/100

------------------------------------------------------------------------

## 🧩 Koddan Bazı Mekanik Detayları

-   Avlanma başarısı rastgelelik + sağlık durumuna bağlı.
-   Tehlike dalgası 3 turdan oluşur ve hasar oranları rastgele
    belirlenir.
-   Enerji 100'ün üzerine çıkamaz.\
-   Karakterin sağlığı 0'a düşerse oyun sona erer.

------------------------------------------------------------------------

## 📜 Lisans

Bu proje serbestçe kullanılabilir, düzenlenebilir ve paylaşılabilir.

------------------------------------------------------------------------

İyi eğlenceler! 🎉\
Her hamle hayatta kalmanı etkiler --- dikkatli oyna!
