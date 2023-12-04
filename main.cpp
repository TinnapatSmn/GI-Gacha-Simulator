#include <iostream>
#include <ctime>
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

#include "gacha.h"

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //ofstream fout("data.txt");
    cout << "Welcome to Gacha simurator -_-   XD  ^<>^ " << endl;
    Gacha player1,player2;
    int chest;
    //set predata

    player1.set_price(160);
    player1.set_percentrolls(1000);
    player1.set_rate_ssr(0,7);//0.6%
    player1.set_rate_sr(6,58);//5.1%
    player1.set_rate_r(57,1001);//94.3%
    player1.set_ssrchar();
    player1.set_srchar();
    player1.set_rchar();

    //data saved
    player1.save_data_input();

    //user start play
    player1.set_both();
    //player1.set_primogem();
    //player1.set_ctystal();
    player1.getout_both();
    player1.set_garantee_ssr();
   do
    {
        player1.set_rolls();
        player1.Rand();
        player1.getout_both();
        player1.topup();
    }while((player1.get_roll()>0)&&(player1.get_crystal()> 0));
    //player1.getout_primogem();
    //player1.getout_crystal();
    player1.cal_price();
    //player1.reset_data();
    player1.save_data_output();
    //cout << "Your data save is"<<endl;
    //player1.data_output();

    return 0;
}


