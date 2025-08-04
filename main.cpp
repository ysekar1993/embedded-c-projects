/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include<cstring>

using namespace std;

#define max_slots 5
#define max_appointments 20
#define max_doctors 10
#define ADMIN_PASSWORD "admin123"


class Doctor
{
    public:
    int ID;
    string  name;
    string specialization;
    char slots[max_slots][10];
    int slotcount;

    void input()
    {
        cout<<"enter the doctor ID:"<<endl;
        cin>>ID;
        cout<<"Enter the doctor name: "<<endl;
        cin>>name;
        cout<<"enter the specialization"<<endl;
        cin>>specialization;
        cout<<"enter the no of slots"<<endl;
        cin>>slotcount;
        for (int i=0;i<slotcount;++i)
        {
            cout<<"enter the slots "<<(i+1)<<":";
            cin>>slots[i];

        }


    }

    void display()
    {
        cout<<"ID :"<<ID<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"specialist in :"<<specialization<<endl;
        cout<<"slots available : "<<endl;

        for(int i=0;i<slotcount;++i)
        {

            cout<<slots[i]<<" ";
        }
        cout<<"\n";
    }

};


class Appointment
{
public:
    int doctorID;
    string patientname;
    string timeslot;

    void input()
    {
        cout<<"enter the doctor id :";
        cin>>doctorID;
        cout<<"enter the patient name :";
        cin>>patientname;
        cout<<"enter the time slot: ";
        cin>>timeslot;
    }
    void display()
    {
        cout<<doctorID<<"\t\t"<<patientname<<"\t\t"<<timeslot<<endl;

    }

};

class admission
{
    Doctor D[max_doctors];
    Appointment A[max_appointments];

    int doctorcount=0;
    int appointmentcount=0;

    bool adminLogin()
    {
        string password;
        cout<<"Please enter your password : ";
        cin>>password;
        return password==ADMIN_PASSWORD;

    }

    void printline()
    {
        cout<<"-----------------------------------------------------------------\n"<<endl;
    }

    public:
        void addorEditdoctordetails()
        {
            if(!adminLogin())
            {
                cout<<"access Denied"<<endl;
                return;
            }
            int id;
            cout<<"enter the doctor id";
            cin>>id;
            for(int i=0;i<doctorcount;++i)
            {
                if(D[i].ID == id)
                {
                    cout<<"Editing the existing doctor details ";
                    D[i].input();
                    cout<<"Doctor Details Updated";
                    return;

                }
            }
            if(doctorcount<max_doctors)
            {
                D[doctorcount].ID = id;
                D[doctorcount].input();
                doctorcount++;
                cout<<"Doctor added";

            }else{
                cout<<"Cannot add more doctors \n";
            }

        }
        void viewDoctors()
        {
            if(doctorcount==0)
            {
                cout<<"No Doctor Available";
                return;
            }
            for(int i=0;i<doctorcount;++i)
            {
                D[i].display()\n;
                printline();
            }

        }

        void bookappointment()
        {
            if(doctorcount== 0)
            {

            cout<<"No doctors available "<<endl;
            return;
            }

            if(appointmentcount>=max_appointments)
            {
                cout<<"Appointment is already reached limit"<<endl;
                return;
            }
            Appointment temp;
            temp.input();
            for(int i=0;i<appointmentcount;++i)
            {
                if(A[i].doctorID==temp.doctorID && (A[i].timeslot==temp.timeslot))
                {

                    cout<<"Doctor Slot is already Booked"<<endl;
                    return;
                }

            }
            A[appointmentcount++]=temp;
            cout<<"Appointment Booked successfully\n"<<endl;
            }
void CancelAppointment()
{
    if(!adminLogin())
    {
        cout<<"access Denied"<<endl;
        return;
    }
    int toBeCancel;
    string slot;
    string patientname;

    cout<<"Enter the Doctor id";
    cin>>toBeCancel;
    cout<<"Enter the time slot";
    cin>>slot;
    cout<<"enter the name of the patient";
    cin>>patientname;
    for(int i=0;i<appointmentcount;++i)
    {
        if(A[i].doctorID==toBeCancel && (A[i].timeslot==slot) && (A[i].patientname==patientname))
        {
            memmove(&A[i],&A[i+1],(appointmentcount-i-1)*sizeof(Appointment));
            appointmentcount--;
            cout<<"Appointment Cancelled";
            return;
        }
    }
    cout<<"Appointment Not Found";
}
void viewAppointments()
{
    if(!adminLogin())
    {
        cout<<"access denied";
        return;
    }
    if(appointmentcount==0)
    {
        cout<<"No appointment booked ";
        return;
    }
    printline();
    cout<<"Doctor Id\t timeslot\t Patientname\t";
    printline();
    for(int i=0;i<appointmentcount;++i)
    {
        A[i].display();

    }
return;
}

void menu()
{   int choice;

    do{
        printline();
        cout<<"Hospital Booking System";
        printline();
        cout<<"1.View Doctors\n";
        cout<<"2.Book Appointments\n";
        cout<<"3.Cancel Appointment\n";
        cout<<"4.Admininstrator-Add or Edit Doctors\n";
        cout<<"5.Admininstrator-View All Appointments\n";
        cout<<"0.EXIT\n";
        cin>>choice;

        switch(choice)
        {
            case 1:viewDoctors();
            break;
            case 2:bookappointment();
            break;
            case 3:CancelAppointment();
            break;
            case 4:addorEditdoctordetails();
            break;
            case 5:viewAppointments();
            break;
            case 0:cout<<"THANK YOU\n";
            break;
            default :cout<<"Invalid Choice";


        }
    }while(choice!=0);

        }


};
int main()
{
    admission admit;
    admit.menu();
return 0;
}




