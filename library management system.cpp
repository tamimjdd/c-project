#include<iostream>
 #include<fstream>
#include<string>
using namespace std;
class INFO_input{ //this class saves borrower info and book info
    public:
    char name1[100],name2[100],book1[100],book2[100],batch[100],writer1[100],writer2[100];
    int edition,id,day,month,year,day2,month2,year2,sell;
    float self_no;
    void person_info(){
        cout<<"enter person batch id no: \n";
        cin>>batch;
        cout<<"enter person sell no: \n";
        cin>>sell;
        cout<<"enter borrow date(day/year/month): \n";
    cin>>day;
    cin>>month;
    cin>>year;
    cout<<"enter 1st name of borrower: \n";
        cin>>name1;
        cout<<"enter 2nd name of borrower: \n";
        cin>>name2;
    }
    void borrowed_book(){
    cout<<"enter 1st name of book: \n";
    cin>>book1;
    cout<<"enter 2nd name of boook: \n";
    cin>>book2;
    cout<<"enter books writer 1st name: \n";
    cin>>writer1;
    cout<<"enter writer last name: \n";
    cin>>writer2;
    cout<<"enter book edition and self no: \n";
    cin>>edition;
    cin>>self_no;
    cout<<"enter expired date(day/year/month): \n";
    cin>>day2;
    cin>>month2;
    cin>>year2;
    }
};
    class save_INFO:public INFO_input//this class is about all file work save data and show data
    {
    public:
        void deleteline(){
        ifstream fs("D:\\new.txt");
    ofstream fout("D:\\new2.txt");
    string deletline,line;
    cout<<"enter the person info to remove: \n";
    cin>>deletline;
    while(getline(fs,line))
    {
        if(deletline!=line)
        {
            fout<<line<<"\n";
        }
    }
    fs.close();
    fout.close();
    remove("D:\\new.txt");
    rename("D:\\new2.txt","D:\\new.txt");
    }
    void filesave(){
     ofstream wr("D:\\new.txt",ios::app);
    wr<<name1<<name2<<"_"<<batch<<"_"<<sell<<"_"<<day<<'/'<<month<<'/'<<year<<"\n";
    wr<<book1<<book2<<"_"<<writer1<<writer2<<"_"<<edition<<"_"<<day2<<'/'<<month2<<'/'<<year2<<"\n\n";
    wr.close();
    }
    void showfileinfo(){
    ifstream fin("D:\\new.txt");
    char ch;
    while(!fin.eof()){
        fin.get(ch);
        cout<<ch;
    }
    fin.close();
    }
};
int main()
{
    save_INFO ob;
    int choose,choose2=1;
    cout<<"choose options: \n";
    cout<<"\t\t\t1.book and borrower info\t\t\t\n";
    cout<<"\t\t\t2.show info of borrowd books\t\t\t\n";
    cout<<"\t\t\t3.save data\t\t\t\n";
    cout<<"\t\t\t4.delet info\t\t\t\n";
    while(choose2){
        cout<<"enter (1,2,3,4) for options: \n";
            cin>>choose;
    switch(choose){
case 1:
    ob.person_info();
    ob.borrowed_book();
    cout<<"to continue press 1 else 0: \n";
    cin>>choose2;
    break;
case 2:
    ob.showfileinfo();
    cout<<"to continue press 1 else 0: \n";
    cin>>choose2;
case 3:
    ob.filesave();
    cout<<"to continue press 1 else 0: \n";
    cin>>choose2;
    break;
case 4:
    ob.deleteline();
    cout<<"to continue press 1 else 0: \n";
    cin>>choose2;
    break;
default:
    cout<<"no option: \n";
    }
}
}
