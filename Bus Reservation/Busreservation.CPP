#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>

class user                 //parent class
 {
  public:
    char name[20];        //variable for taking user's name
    char curc[10];        //variable for taking user's current city
    char desc[10];        //variable for taking user's destination city
    char phone[20];       //variable for taking user's phone number
    int x,y;

    void takedata();      //function takes input from users
    void showdata();      //function shows ouput on screen(console)

 };

void user::takedata()     //takedata() starts here
 {
	cleardevice();
	cout<<"Enter your name: ";
	gets(name);
	cout<<"Enter your phone number: ";
	gets(phone);
	cout<<endl<<"1. Ranchi\n2. Jamshedpur\n3. Bokaro\n4. Kolkata\n5. Orissa\n";
	cout<<"Select your current city: ";
	cin>>x;
	switch(x)
	 {
	  case 1: strcpy(curc,"Ranchi");
		  break;
	  case 2: strcpy(curc,"Jamshedpur");
		  break;
	  case 3: strcpy(curc,"Bokaro");
		  break;
	  case 4: strcpy(curc,"Kolkata");
		  break;
	  case 5: strcpy(curc,"Orissa");
		  break;
	  default: cout<<"Please enter correct option";
		  break;
	 }
	 cout<<endl<<"1. Ranchi\n2. Jamshedpur\n3. Bokaro\n4. Kolkata\n5. Orissa\n";
	 cout<<"Select your destination city: ";
	 cin>>y;
	 switch(y)
	 {
	  case 1: strcpy(desc,"Ranchi");
		  break;
	  case 2: strcpy(desc,"Jamshedpur");
		  break;
	  case 3: strcpy(desc,"Bokaro");
		  break;
	  case 4: strcpy(desc,"Kolkata");
		  break;
	  case 5: strcpy(desc,"Orissa");
		  break;
	  default: cout<<"Please enter correct option";
		  break;
	 }
 }

void user::showdata()       //showdata() starts here
 { cleardevice();
   outtextxy(20,20,"Name");
   outtextxy(150,20,"Phone Number");
   outtextxy(280,20,"Current City");
   outtextxy(410,20,"Destination City");
   outtextxy(20,40,name);
   outtextxy(150,40,phone);
   outtextxy(280,40,curc);
   outtextxy(410,40,desc);
 }

class fileoperate: public user        //child class inheriting class user
 { public:
    void storefile();               //stores user data to a file
    void searchfile(char*,char*);   //enables user to check there status
    void deletefile(char*,char*);   //enables user to remove their status permanently
    void updatefile(char*,char*);   //enable user to update their status
 };

void fileoperate::storefile()       //storefile() starts here
 {
   ofstream fout;
   fout.open("userdata.dat",ios::app|ios::binary);
   fout.write((char*)this,sizeof(*this));
   fout.close();
 }

void fileoperate::searchfile(char*p,char*nme)    //searchfile() starts here
 {
    int count=0;
    ifstream fin;
    fin.open("userdata.dat",ios::in|ios::binary);
    if(!fin)
       { cout<<"\n File not found";
	 getch();
	 exit(0);
       }

    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
      { if(!strcmp(p,phone)&&!strcmp(nme,name))
	    {
	      showdata();
	      count++;
	    }
	fin.read((char*)this,sizeof(*this));
      }

      if(count==0)
       {
	 cout<<endl<<"Your status either has been cancelled or there is no such record.";
       }
       fin.close();
 }

void fileoperate::deletefile(char*p,char*nme)     //deletefile() starts here
 {
   ifstream fin;
   ofstream fout;
   fin.open("userdata.dat",ios::in|ios::binary);
   if(!fin)
    cout<<"\nFile not found";
   else
    {
     fout.open("tempfile.dat",ios::out|ios::binary);
     fin.read((char*)this,sizeof(*this));
     while(!fin.eof())
      {
	if(strcmp(p,phone)&&strcmp(nme,name))
	 {
	  fout.write((char*)this,sizeof(*this));
	 }
	fin.read((char*)this,sizeof(*this));
      }
     fin.close();
     fout.close();
     remove("userdata.dat");
     rename("tempfile.dat","userdata.dat");
    }
 }

void fileoperate::updatefile(char*p,char*nme)      //updatefile() starts here
 {
    fstream file;
    file.open("userdata.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
     {
       if(!strcmp(p,phone)&&!strcmp(nme,name))
	{
	 takedata();
	 file.seekp(file.tellp()-sizeof(*this));
	 file.write((char*)this,sizeof(*this));
	}
       file.read((char*)this,sizeof(*this));
     }
 }

void first();                 //function prototyping for first()

void main()                  //the main program starts here
 {
   clrscr();
   int opt,c,d;
   char phn[20];
   char nm[20];
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"c://turboc3//bgi");
  first();                    //function call for first()
  if(kbhit)
  { char ch=getch();
      if(ch==13)
	{ cleardevice();
	}
      else
       { cleardevice();
	 settextstyle(2,0,7);
	 outtextxy(20,150,"Please press correct button or start all over again.");
	 delay(2000);
	 exit(0);
       }
  }
   fileoperate obj;
   display:
    {
      cleardevice();
      settextstyle(2,0,5);
      outtextxy(220,150,"1. Check available buses");
      outtextxy(220,170,"2. Book");
      outtextxy(220,190,"3. Check your booking status");
      outtextxy(220,210,"4. Cancel your booking status");
      outtextxy(220,230,"5. Update your status");
      outtextxy(220,250,"6. Exit");
      outtextxy(170,280,"Enter the respective number among the following options: ");
      opt=getch();
      if(opt==49)
	goto one;
      else if(opt==50)
	goto two;
      else if(opt==51)
	goto three;
      else if(opt==52)
	goto four;
      else if(opt==53)
	goto five;
      else if(opt==54)
	goto six;
      else
	goto seven;
    }
   one:
    {
	clrscr();
	cout<<"Select your current city: ";
	cout<<endl<<"1. Ranchi";
	cout<<endl<<"2. Jamshedpur";
	cout<<endl<<"3. Bokaro";
	cout<<endl<<"4. Kolkata";
	cout<<endl<<"5. Orissa";
	cin>>c;

	cout<<"Select your destination city: ";
	cout<<endl<<"1. Ranchi";
	cout<<endl<<"2. Jamshedpur";
	cout<<endl<<"4. Bokaro";
	cout<<endl<<"5. Kolkata";
	cout<<endl<<"6. Orissa";
	cin>>d;

	if(c==1)
	 {
	   if(d==2)
	   {
	    cleardevice();
	    outtextxy(20,10,"Bus Number");
	    outtextxy(150,10,"Bus Name");
	    outtextxy(280,10,"Driver's Name");
	    outtextxy(430,10,"Driver's Number");
	    outtextxy(20,30,"B001");
	    outtextxy(150,30,"Arjun Rath");
	    outtextxy(280,30,"Kripal Singh");
	    outtextxy(430,30,"9220034508");
	   }
	   else if(d==3)
	   {
	    cleardevice();
	    outtextxy(20,10,"Bus Number");
	    outtextxy(150,10,"Bus Name");
	    outtextxy(280,10,"Driver's Name");
	    outtextxy(430,10,"Driver's Number");
	    outtextxy(20,30,"B002");
	    outtextxy(150,30,"Singh Tour & Travels");
	    outtextxy(280,30,"Ramesh Kumar");
	    outtextxy(430,30,"884509687");
	   }
	   else if(d==4)
	   {
	    cleardevice();
	    outtextxy(20,10,"Bus Number");
	    outtextxy(150,10,"Bus Name");
	    outtextxy(280,10,"Driver's Name");
	    outtextxy(430,10,"Driver's Number");
	    outtextxy(20,30,"B003");
	    outtextxy(150,30,"Kailash Rath");
	    outtextxy(280,30,"Sushil Kumar");
	    outtextxy(430,30,"709865874");
	   }
	   else if(d==5)
	   {
	    cleardevice();
	    outtextxy(20,10,"Bus Number");
	    outtextxy(150,10,"Bus Name");
	    outtextxy(280,10,"Driver's Name");
	    outtextxy(430,10,"Driver's Number");
	    outtextxy(20,30,"B004");
	    outtextxy(150,30,"Luxury Travels");
	    outtextxy(280,30,"Yogesh Ranjan");
	    outtextxy(430,30,"8129313913");
	   }

	 }

	 else if(c==2)
	  {
	     if(d==1)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B001");
		outtextxy(150,30,"Arjun Rath");
		outtextxy(280,30,"Raghunath Saah");
		outtextxy(430,30,"7674822928");
	      }
	     else if(d==3)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B005");
		outtextxy(150,30,"Lakshmi Rath");
		outtextxy(280,30,"Haroon Kumar");
		outtextxy(430,30,"8299218283");
	      }
	    else if(d==4)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B006");
	       outtextxy(150,30,"Vaishnav Travels");
	       outtextxy(280,30,"Somesh Nath");
	       outtextxy(430,30,"9873473482");
	      }
	    else if(d==5)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B004");
	       outtextxy(150,30,"Luxury Travels");
	       outtextxy(280,30,"Om Prakash");
	       outtextxy(430,30,"7082392998");
	      }

	   }

	  else if(c==3)
	   {
	     if(d==1)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B001");
		outtextxy(150,30,"Arjun Rath");
		outtextxy(280,30,"Kumar Ramnath");
		outtextxy(430,30,"9203913813");
	      }
	     else if(d==2)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B007");
		outtextxy(150,30,"Yash Travels");
		outtextxy(280,30,"Harmann Kumar");
		outtextxy(430,30,"8129831317");
	      }
	    else if(d==4)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B008");
	       outtextxy(150,30,"Lokesh Nath Tour & Travels");
	       outtextxy(280,30,"Govind Singh");
	       outtextxy(430,30,"8213102932");
	      }
	    else if(d==5)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B009");
	       outtextxy(150,30,"Natraj Travels");
	       outtextxy(280,30,"Prakash Rao");
	       outtextxy(430,30,"7082392344");
	      }
	   }

	 else if(c==4)
	  {
	     if(d==1)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B001");
		outtextxy(150,30,"Arjun Rath");
		outtextxy(280,30,"Raghunath Saah");
		outtextxy(430,30,"7674822928");
	      }
	     else if(d==3)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B005");
		outtextxy(150,30,"Lakshmi Rath");
		outtextxy(280,30,"Haroon Kumar");
		outtextxy(430,30,"8299218283");
	      }
	    else if(d==2)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B006");
	       outtextxy(150,30,"Vaishnav Travels");
	       outtextxy(280,30,"Ibram");
	       outtextxy(430,30,"9812731717");
	      }
	    else if(d==5)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B010");
	       outtextxy(150,30,"Vrindavaan Travels");
	       outtextxy(280,30,"Raja");
	       outtextxy(430,30,"912938312");
	      }

	   }

	 else if(c==5)
	  {
	     if(d==1)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B004");
		outtextxy(150,30,"Luxury Travels");
		outtextxy(280,30,"Bharat");
		outtextxy(430,30,"7674822928");
	      }
	     else if(d==3)
	      {
		cleardevice();
		outtextxy(20,10,"Bus Number");
		outtextxy(150,10,"Bus Name");
		outtextxy(280,10,"Driver's Name");
		outtextxy(430,10,"Driver's Number");
		outtextxy(20,30,"B005");
		outtextxy(150,30,"Lakshmi Rath");
		outtextxy(280,30,"Hari Narayan");
		outtextxy(430,30,"7213713217");
	      }
	    else if(d==2)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B006");
	       outtextxy(150,30,"Vaishnav Travels");
	       outtextxy(280,30,"Ahmed");
	       outtextxy(430,30,"9712312213");
	      }
	    else if(d==4)
	      {
	       cleardevice();
	       outtextxy(20,10,"Bus Number");
	       outtextxy(150,10,"Bus Name");
	       outtextxy(280,10,"Driver's Name");
	       outtextxy(430,10,"Driver's Number");
	       outtextxy(20,30,"B010");
	       outtextxy(150,30,"Vrindavaan Travels");
	       outtextxy(280,30,"Ram Janam");
	       outtextxy(430,30,"913123121");
	      }

	   }
	getch();
	goto display;
    }
    two:
     {
	cleardevice();
	obj.takedata();           //function call for takedata()
	obj.storefile();          //function call for storedata()
	goto display;
     }
     three:
      {
	 cleardevice();
	 cout<<"Enter the name provided by you: ";
	 gets(nm);
	 cout<<"Enter the phone number provided by you: ";
	 gets(phn);
	 obj.searchfile(phn,nm);       //function call for searchfile()
	 getch();
	 goto display;
      }
      four:
       {
	  cleardevice();
	  cout<<"Enter the name provided by you: ";
	  gets(nm);
	  cout<<"Enter your provided phone number: ";
	  gets(phn);
	  obj.deletefile(phn,nm);      //function call for deletefile()
	  goto display;
       }

      five:
	{
	  cleardevice();
	  cout<<"Enter the name provided by you: ";
	  gets(nm);
	  cout<<"Enter your provided phone number: ";
	  gets(phn);
	  obj.updatefile(phn,nm);       //function call for updatefile()
	  goto display;
	}
      seven:
	 {
	    cleardevice();
	    settextstyle(4,0,2);
	    outtextxy(220,150,"Please enter correct option.");
	    getch();
	    goto display;
	 }
      six:
	{
	    cleardevice();
	    settextstyle(5,0,3);
	    outtextxy(160,150,"Thank you! Please visit us soon.");
	    getch();
	    closegraph();
	    exit(0);
	}
}

void first()               //this function display the choices for user
{
  settextstyle(5,0,4);
  outtextxy(220,150,"Welcome to");
  setcolor(YELLOW);
  settextstyle(7,0,4);
  outtextxy(170,200,"Book Your Bus");
  settextstyle(1,0,1);
  setcolor(WHITE);
  settextstyle(2,0,4);
  outtextxy(273,270,"LOADING...");
  cout<<endl;
  for(int i=250; i<=340; i++)
  {
    line(i,290,i,295);
    delay(40);
  }
  outtextxy(230,300,"Press 'Enter' to continue");
}


