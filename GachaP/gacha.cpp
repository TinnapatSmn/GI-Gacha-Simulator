#include "gacha.h"

void Gacha::getout_both()const{
    cout << "You have " << primogem << " primogems" << endl;
    cout << "you have " << crystal << " crystals" << endl;
}

void Gacha::set_rolls(){
    do{
    cout << "Enter your round it you want to rolls : " ;
    cin >> rolls;
    if(rolls>crystal)
    cout << "You don't have enough crystals please try again " << endl;
    }while(rolls>crystal);
}

void Gacha::set_both(){
    int primo,cryto;
    cout << "Enter your primogems : "; cin >> primo;
    cout << "Enter you crystal : ";cin >> cryto;
    cout << "(1 crystal = " << price << " primogems)" << endl;
    primogem += primo;
    crystal += cryto;
    crystal += (primogem/price);
    primogem -= (primogem/price)*price;
}

void Gacha::Rand(){
    int main_rolls,j=0,z;
    srand((time_t)time(NULL));
    for(z=rolls;z>0;--z){
        main_rolls = rand()%percent_rolls +1;
        if(main_rolls>rate_ssr_upper && main_rolls<rate_ssr_under||garantee_ssr==89){
            int number=sizeof(SSR)/sizeof(SSR[0]);
            int chk=rand()%number;
            cout<<"Congratulations!!! you got SSR: " << SSR[chk]<<endl;
            data_save[j]=SSR[chk];
            crystal>0?crystal-=1:crystal = 0;
            garantee_ssr = 0;
            garantee_sr+=1;
        }
        else if(main_rolls >rate_sr_upper && main_rolls < rate_sr_under||garantee_sr==9){
            int number=sizeof(SR)/sizeof(SR[0]);
            int chk=rand()%number;
            cout <<"It's ok you got SR: " << SR[chk]<<endl;
            data_save[j]=SR[chk];
            crystal>0?crystal-=1:crystal = 0;
            garantee_ssr+=1;
            garantee_sr=0;
        }
        else if(main_rolls >rate_r_upper && main_rolls < rate_r_under){
            int number=sizeof(R)/sizeof(R[0]);
            int chk=rand()%number;
            cout << "HAHAAAAA you got SALT!!!: "<< R[chk]<<endl;
            data_save[j]=R[chk];
            crystal>0?crystal-=1:crystal = 0;
            garantee_ssr+=1;
            garantee_sr+=1;
        }
        ++j;
        ++total_rolls;
        cout << "total rolls : " << total_rolls << " and you have " << crystal << " crystals left." << endl;
        ++save_roll;
        //++save_chk;
    }
}



void Gacha::set_ssrchar()
{
    ifstream inFile;
    inFile.open("ssr_char.txt");
    if(inFile.fail()){
        cout << "Error SSR FILE" << endl;
        exit(1);
    }
    int num_chk=0;
    if(inFile.is_open())
    {
        while(getline(inFile,SSR[num_chk]))
            ++num_chk;
        inFile.close();
    }

}
void Gacha::set_srchar()
{
    ifstream inFile;
    inFile.open("sr_char.txt");
    if(inFile.fail()){
        cout << "Error SR FILE" << endl;
        exit(1);
    }
    int num_chk=0;
    if(inFile.is_open())
    {
        while(getline(inFile,SR[num_chk]))
            ++num_chk;
        inFile.close();
    }

}
void Gacha::set_rchar()
{
    ifstream inFile;
    inFile.open("r_char.txt");
    if(inFile.fail()){
        cout << "Error R FILE" << endl;
        exit(1);
    }
    int num_chk=0;
    if(inFile.is_open())
    {
        while(getline(inFile,R[num_chk]))
            ++num_chk;
        inFile.close();
    }
}

void Gacha::cal_price()
{
    int case_chk;
    cout << "What Currency do you want?" << endl
         << "(1)USD:US DOLLARS" << endl
         << "(2)THB:THAI BATH" << endl
         << "(3)JPY:JAPAN YEN" << endl
         << "(4)CNY:CHINA YUAN" << endl
         << " Choose : "; cin >> case_chk;
    switch(case_chk)
    {
        case(1):
            cout << "You spend " << total_rolls*3 << " USD!" << endl;
            break;
        case(2):
            cout << "You spend " << total_rolls*100 << " THB!" << endl;
            break;
        case(3):
            cout << "You spend " << total_rolls*344.66 << " JPY!" << endl;
            break;
        case(4):
            cout << "You spend " << total_rolls*19.10 << " CNY!" << endl;
            break;
    }

}
void Gacha::topup()
{
    string user_input;
    if(rolls!=0)
    {
        cout << "--------------------------" << endl
             << "You want to top up?(YES/NO): "; cin >> user_input;
        if(user_input == "YES" || user_input == "yes")
        {
            cout << "Enter your primogems for top-up : "; cin >> primogem;
            cout << "Enter you crystal for top-up : ";cin >> crystal;
            crystal += (primogem/price);
            primogem -= (primogem/price)*price;
        }
        cout << "--------------------------" << endl;
    }
}
void Gacha::save_data_output()
{
    ofstream outfile;
    outfile.open("data_save.txt");
    if(outfile.is_open())
    {
     outfile<<primogem<<endl;
     outfile<<crystal<<endl;
     //outfile<<save_chk<<endl;
        for(int i=0;i<save_roll;++i){
        outfile<<data_save[i]<<endl;
        //++bug_chk;
        //cout << " n " << data_save[i] << endl;
        }
    outfile.close();
    }
    else
        cout<<"FILE DATA SAVE ERROR!"<<endl;
}

void Gacha::data_output()
{
   for(int i=0 ;i<total_rolls;++i)
   {
    cout<<data_save[i]<<endl;
   }
}

void Gacha::save_data_input()
{
    ifstream infile;
    string filename="data_save.txt";
    infile.open(filename);

    if(infile.is_open())
    {
        cout<<"This is data you had save>>>>>>"<<endl;
        infile>>primogem;
        infile>>crystal;

        //infile>>save_chk;
        getout_both();
        int chk,i=0;
        cout<<"If you want to check you list type 1 and 0 for not: ";
        cin>>chk;
        if(chk==1)
        {
            cout<<endl<<"In your list have:"<<endl;
            cout<<"########################################################";

               while(getline(infile, data_save[i])){
                cout<<data_save[i]<<endl;
                ++i;
                }

            cout<<"########################################################"<<endl<<endl;
        }
        else
            cout<<"If you won't is ok let's go-----------------------"<<endl;
        infile.close();
    }
    else
        cout<<"file data save error" <<endl;
    }
