#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class Date
{
    public:
    string date;
    Date(){};
    Date(string d)
    {
        date=d;
    }
};
class Person
{
public:
    string name;
    Date date1;
    Person()
    {};
    Person(string n)
    {
       this->name=n;
    };
    Person(string name,string date)
    {
        this->name=name;
        date1.date=date;
    };

};

class Department
{
public:
    string dpt_name;
    Department(){};
    Department(string name)
    {
        dpt_name=name;
    }
};
class Contestant : public Person
{
  public:
      string id;
      int solveno;
      Department department;
      Contestant(){};
      Contestant(string name,string date,Department dp_name,string id_no,int solveno) : Person(name,date)
      {
        this->solveno=solveno;
        id=id_no;
        department=dp_name;
      }
      view_Contestant_info()
      {
          cout<<"Contestant Type      : Normal"<<endl;
          cout<<"Name                 : "<<name<<endl;
          cout<<"Department           : "<<department.dpt_name<<endl;
          cout<<"Contestant ID        : "<<id<<endl;
          cout<<"Contestant Birthday  : "<<date1.date<<endl;
          cout<<"Contestant solve no  : "<<solveno<<endl;
          cout<<"....................................."<<endl;
      }

};
class ACM_finalist: public Person
{
public:
      string id2;
      int solveno2;
      Department department2;
      ACM_finalist(){};
      ACM_finalist(string name,string date,Department dp_name,string id_no2,int solveno2) : Person(name,date)
      {
        this->solveno2=solveno2;
        id2=id_no2;
        department2=dp_name;
      }
      view_ACM_finalist_info()
      {
          cout<<"Contestant Type      : Acm finalist"<<endl;
          cout<<"Name                 : "<<name<<endl;
          cout<<"Department           : "<<department2.dpt_name<<endl;
          cout<<"finalist ID          : "<<id2<<endl;
          cout<<"finalist Birthday    : "<<date1.date<<endl;
          cout<<"finalist solve no    : "<<solveno2<<endl;
          cout<<"................................."<<endl;
      }
      friend dotdisplay();
      friend optionDisplay();

};
dotdisplay()
{
    cout<<"\n................................."<<endl;
}
optionDisplay()
{
    cout<<"1.View faculty members\n2.View all contestants\n3.View selected Contestants whom problems may be included\n0.Break"<<endl;
}

class Faculty : public Person
{
public:
    string designation;
    Department department;
    Faculty() {};
    Faculty(string designation,string name,Department department1):Person(name)
    {
        this->designation=designation;
        department=department1;
    }
    view_faculty()
    {
        cout<<"................................."<<endl;
        cout<<"Name       : "<<name<<endl;
        cout<<"Department : "<<department.dpt_name<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"................................."<<endl;
    }

};

int main()
{
    Department dpt("cse");
    int x=0,y=0,index=0,index2=0,z;
    Faculty *faculty_member[3]=
    {
        new Faculty("Assistant Professor","Kamal Hossain Chowdhury",dpt),
        new Faculty("Assistant Professor","Mahmudul Hasan",dpt),
        new Faculty("Assistant Professor","Faisal Ahmed",dpt)
    };
    cout<<"Enter Number of Contestant     [Press 3]:"<<endl;
    cin>>x;
    cout<<"Enter Number of Acm finalist No[Press 4]:"<<endl;
    cin>>y;

    Contestant *a1[]={

    new Contestant("Mahbub","12-12-98",dpt,"1001",12),
    new Contestant("Kader","1-1-97",dpt,"102",11),
    new Contestant("Gony","1-2-97",dpt,"104",14)
    };
    ACM_finalist *a2[]=
    {
    new ACM_finalist("DON","1-10-98",dpt,"001",4),
    new ACM_finalist("Mian","1-11-97",dpt,"002",1),
    new ACM_finalist("Jony","1-13-98",dpt,"003",7),
    new ACM_finalist("Nahid","1-13-98",dpt,"004",11)
    };


    if(y==0)
    {
        int maximum;
        for(int z=0;z<x;z++)
        {
            if(z==0)
            {
                maximum=a1[z]->solveno;
            }
            if(z>0)
            {
                if(a1[z]->solveno>maximum)
                {
                   index=z;
                   maximum = a1[z]->solveno;
                }
            }
               if(z==x-1)
               {
                int maximum1;

                for(int m=0;m<x;m++)
                {
                    if(m==0)
                    {
                        maximum1=a1[m]->solveno;
                    }
                    if(m>0)
                    {
                        if(m!=index&&a1[m]->solveno>maximum1)
                        {
                           index=m;
                           maximum1 = a1[m]->solveno;
                        }
                    }
                 }
               }
        }
    }


    else if(y==1)
    {
        int maximum;
        for(int z=0;z<x;z++)
        {
            if(z==0)
            {
                maximum=a1[z]->solveno;
            }
            if(z>0)
            {
                if(a1[z]->solveno>maximum)
                {
                   index=z;
                   maximum = a1[z]->solveno;
                }
            }
        index2=0;
        }
    }

   else if(y>1)
    {
        int maximum;
        for(int z=0;z<y;z++)
        {
            if(z==0)
            {
                maximum=a2[z]->solveno2;
            }
            if(z>0)
            {
                if(a2[z]->solveno2>maximum)
                {
                   index=z;
                   maximum = a2[z]->solveno2;
                }
            }
               if(z==y-1)
               {
                int maximum1;

                for(int m=0;m<y;m++)
                {
                    if(m==0)
                    {
                        maximum1=a2[m]->solveno2;
                    }
                    if(m>0)
                    {
                        if(m!=index&&a2[m]->solveno2>maximum1)
                        {
                           index2=m;
                           maximum1 = a2[m]->solveno2;
                        }
                    }


                 }
               }
        }
    }
    //cout<<a2[index]->solveno2<<a2[index2]->solveno2<<"\n"<<endl;
    optionDisplay();
    int w;
    while(1)
    {

        cin>>w;
        if(w==0)
            break;
        switch(w)
        {
        case 1:
            for(int k=0;k<3;k++)
            {
                faculty_member[k]->view_faculty();

            }
            optionDisplay();
            break;
        case 2:
            {for(int l=0;l<x;l++)
                {dotdisplay();
                a1[l]->view_Contestant_info();}
            dotdisplay();
            for(int l=0;l<y;l++)
                {dotdisplay();
                a2[l]->view_ACM_finalist_info();}
            }
            optionDisplay();
            break;
        case 3:
            if(y==0)
                {
                cout<<"\n\nSELECTED CONTESTANT 1:"<<endl;
                a1[index]->view_Contestant_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                cout<<"\nSELECTED CONTESTANT 2:"<<endl;
                a1[index2]->view_Contestant_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                optionDisplay();
                break;}
            else if(y==1)
                {
                cout<<"\n\nSELECTED CONTESTANT 1:"<<endl;
                a1[index]->view_Contestant_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[0]->view_faculty();
                dotdisplay();
                cout<<"\nSELECTED CONTESTANT 2:"<<endl;
                a2[index2]->view_ACM_finalist_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                optionDisplay();
                break;}
            else if(y>=2)
                {
                cout<<"\n\nSELECTED CONTESTANT 1:"<<endl;
                a2[index]->view_ACM_finalist_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[0]->view_faculty();
                dotdisplay();
                cout<<"\nSELECTED CONTESTANT 2:"<<endl;
                a2[index2]->view_ACM_finalist_info();
                cout<<"Selected by :\n"<<endl;
                faculty_member[1]->view_faculty();
                dotdisplay();
                optionDisplay();
                break;
                }
            optionDisplay();
            break;


        default:
            cout<<"\"Type again correcty\""<<endl;
            optionDisplay();
        }

    }

    return 0;
}

