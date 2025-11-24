#include <iostream>
#include <string>


std::string ucusGuvenligiKontrol(int yuk, int hiz, int yukseklik) {
    
    int pil_seviyesi = 100 - (yuk + hiz + yukseklik);

    std::cout << "[Pil Seviyesi Hesaplandı]: %" << pil_seviyesi << std::endl;
    
    
    if (yuk > 30) { 
        return "Ağır yük, uçamaz!"; 
    }
    
    if (pil_seviyesi <= 20) { 
        return "Pil seviyesi düşük, uçuş güvensiz!"; 
    }
    
    if (yukseklik > 100 || hiz > 80) { 
        return "Radar dışı, uçuş güvensiz!"; 
    }
    
    return "Uçuş güvenli!";
}

using namespace std;

int main() {
    int drone_sayisi;
    
 
    const int MAX_DRONE = 100;
    
    
    string ucus_durumlari[MAX_DRONE]; 
    
    cout << "Basit Drone Kontrol Sistemi (Maks. " << MAX_DRONE << " Drone)  "<< endl;
    
    
    
    cout << "Lütfen kontrol edilecek **DRONE SAYISINI** giriniz: ";
    cin >> drone_sayisi; 
    
    
    if (drone_sayisi <= 0 || drone_sayisi > MAX_DRONE) {
        cout << "Geçersiz drone sayısı veya kapasite aşımı. Program sonlandırılıyor." << endl;
        return 0;
    }

   
    cout << "GİRİŞ DEĞERLERİNİ ALMA " << endl;
   

 
    for (int i = 0; i < drone_sayisi; ++i) {
        int yuk, hiz, yukseklik;
        
        cout << "DRONE " << i + 1 << " için girişler:" << endl;
        cout << "Yük (0-100): "; 
        cin >> yuk; 
        cout << "Hız (km/s): "; 
        cin >> hiz;
        cout << "Yükseklik (metre): "; 
        cin >> yukseklik;
        
       
        string sonuc = ucusGuvenligiKontrol(yuk, hiz, yukseklik);
        ucus_durumlari[i] = sonuc; 
        
        ;
    }

 
    cout << "TÜM DRONE'LARIN UÇUŞ GÜVENLİK DURUMU  "<< endl;
   

    for (int i = 0; i < drone_sayisi; ++i) {
        cout << "DRONE " << i + 1 << " UÇUŞ DURUMU: **" << ucus_durumlari[i]  << endl;
        if (i < drone_sayisi - 1) {
         
        }
    }


    return 0;
}