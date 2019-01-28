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
    Person(){};
};
class Sellsman
{
public:
    string slname;
    Sellsman(){};
    Sellsman(string n){
    slname=n;}
};
class Customer : public Person
{
public:
    Customer(){};
    int cid;
    int buycount;
    int total=0;
    Customer(string n,int id,int cnt)
    {
        this->name=n;
        cid=id;
        buycount=cnt;

    };

};
class Product
{
public:
    string itemname;
    string origin;
    string category;
    int id;
    int price;
    int quantity;
    int discount=0;
};
class Shop
{
public:
    Product a1;
    Date dte;
    Customer c1;

    Shop(string nm,string pnm,string catg,string org,int i,int p,int q,int c,string dt)
    {
        a1.itemname=pnm;
        a1.id=i;
        c1.name=nm;
        a1.category=catg;
        a1.origin=org;
        a1.price=p;
        a1.quantity=q;
        c1.buycount=c;
        dte.date=dt;
        if(c<3)
            {c1.total=q*p;}
        else {c1.total=floor(q*p-q*p*.10),a1.discount=floor(q*p*.10);}
    }

    void view()
    {
        cout<<"Customer Name     :"<<c1.name<<
        "\nproduct name      :"<<a1.itemname<<
        "\nProduct category  :"<<a1.category<<
        "\nProduct Origin    :"<<a1.origin<<
        "\nProduct id        :"<<a1.id<<
        "\nProduct Price     :"<<a1.price<<
        "\nProduct quantity  :"<<a1.quantity<<
        "\nTimes of Shopping :"<<c1.buycount<<
        "\nShopping Date     :"<<dte.date<<
        "\nTotal cost        :"<<a1.price*a1.quantity<<endl;

        if(c1.total!=a1.price*a1.quantity)
        {cout<<"...............\n10% discount      :"<<a1.discount<<"\n...............\n"<<"\n..............................\nTotal cost        :"<<c1.total<<endl;}
        else cout<<"\n........................\nTotal cost        :"<<c1.total<<endl;
       // cout<<"\nService by :"<<s1.slname<<endl;
    }
    void view_customer_name()
    {
        cout<<c1.name<<"\n"<<endl;
    }

    void view_product_name()
    {
        cout<<a1.itemname<<"\n"<<endl;
    }
    friend void serviceby();
    friend void option();


};
 void serviceby()
    {

        Sellsman s1;
        s1.slname="Mahfuz";
        cout<<"\nService by :"<<s1.slname<<"\n............................\n"<<endl;;
    }
    void option()
    {
    cout<<"press 1 to view all customer name.\npress 2 to view all product name\npress 3 to specific customer\npress 4 for view all customer info\nPress 0 to terminate\n\n10% discount for more than 3 times purchase\n"<<endl;

    }
int main()
{
    int i,j,x,y;
    ///10% discount for customer who shop at least 3 times.
    Shop *sh[]={
///input format:
///CustomerName_Itemname_Category_origin_ID_unit price_quantity_TimesofPurchaseOfCustomer_dateofPurchase
        new Shop("Nahidul alam nahid","Pen","Educational","Local",001,10,3,5,"11-11-18"),
        new Shop("Mahbub","Pants","Men","Local",002,750,5,1,"2-2-15"),
        new Shop("Abir","Spray","Cosmetics","China",003,800,2,5,"3-3-18"),
        new Shop("Fahad","Encyclopedia","book","America",004,2500,3,4,"3-3-18"),
        new Shop("Jony","Walmart","Gift","China",005,500,3,4,"3-1-19")};

    option();
    //cout<<"press 1 to view all customer name.\npress 2 to view all product name\npress 3 to specific customer\npress 4 for view all customer info\nPress 0 to terminate\n\n10% discount for more than 3 times purchase\n"<<endl;
    while(1)
    {
    cin>>x;
    if(x==0)
        return 0;
        switch(x)
        {
            case 1:
                {
                    cout<<"Customer name:"<<endl;
                    for(i=0;i<5;i++)
                    {
                    cout<<i+1<<".";
                    sh[i]->view_customer_name();
                    }
                    option();
                    break;

                }
            case 2:
                cout<<"Product name:"<<endl;
                for(i=0;i<4;i++)
                {
                    cout<<i+1<<".";
                    sh[i]->view_product_name();
                }

                option();
                break;
            case 3:
                {
                        cout<<"Showing specific customer info"<<endl;
                        while(1)
                        {
                            cout<<"Enter customer id to view info\n\nPress 0 to go back\n"<<endl;
                            for(i=0;i<5;i++)
                                {
                                cout<<i+1<<".";
                                sh[i]->view_customer_name();
                                }

                            cin>>y;
                            if(y==0)
                                {cout<<"press 1 to view all customer name.\npress 2 to view all product name\npress 3 to specific customer\npress 4 for view all customer info"<<endl;
                                break;}
                            sh[y-1]->view();serviceby();
                        }
                    }
                break;
            case 4:
                cout<<""<<endl;
                for(i=0;i<4;i++)
                {
                    cout<<i+1<<".";
                    sh[i]->view();serviceby();
                }
                option();
                break;

            default:
                cout<<"Type again"<<endl;
                option();
        }
    }
    /*sh[0]->view();serviceby();
    sh[1]->view();serviceby();
    sh[2]->view();serviceby();*/
    return 0;
}


