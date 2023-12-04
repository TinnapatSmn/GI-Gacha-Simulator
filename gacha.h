#ifndef GACHA_H
#define GACHA_H
#include <iostream>
#include <ctime>
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Gacha{
public:
    Gacha():primogem(0),crystal(0),total_rolls(0){};
    Gacha(int a):primogem(a),total_rolls(0){};
    void set_rolls();
    void set_price(int a){price = a;};
    void set_ctystal(){cout << "Enter you crystal : ";cin >> crystal;};
    void set_primogem(){cout << "Enter your primogems : "; cin >> primogem;};
    void set_both();
    void set_garantee_ssr(){cout << "Enter your roll stack : ";
            cin>>garantee_ssr; garantee_sr=garantee_ssr%10;total_rolls=garantee_ssr;};
    void set_percentrolls(int a){percent_rolls = a;};
    void set_rate_ssr(int a,int b){rate_ssr_upper= a; rate_ssr_under = b;};
    void set_rate_sr(int a,int b){rate_sr_upper= a; rate_sr_under = b;};
    void set_rate_r(int a,int b){rate_r_upper= a; rate_r_under = b;};
    void Rand();
    void getout_primogem()const{cout << "You have " << primogem << " primogems" <<endl;};
    void getout_crystal()const{cout <<"You have "<< crystal <<" totall crystals" << endl;};
    void getout_both()const;
    void cal_price();
    void topup();
    void set_ssrchar();
    void set_srchar();
    void set_rchar();
    void set_data();
    int get_totalrolls(){return total_rolls;};
    void save_data_output();
    void data_output();
    void save_data_input();
    void reset_data(){primogem=0;crystal=0;};
    int get_roll(){return rolls;};
    int get_crystal(){return crystal;};
private:
    int percent_rolls,rolls,garantee_ssr,garantee_sr,total_rolls;
    int price,save_chk=0,save_roll=0;
    int primogem,crystal;
    int rate_ssr_upper,rate_ssr_under,rate_sr_upper,rate_sr_under,rate_r_upper,rate_r_under;
    string SSR[5];
    string SR[32];
    string R[13];
    string data_save[100];
};

#endif
