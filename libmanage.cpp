//~~~~~~~~~~~~~LIBRARY MANAGEMENT PROJECT~~~~~~~~~~~~~~~~~~~~

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class book
{
    int bno;
    char bname[50];
    char aname[20];
    int status;
    int bklib;

public:
    void create_book()
    {
        //clrscr();
        cout << "\nNEW BOOK ENTRY...\n";
        cout << "\n\nEnter Book No. of the Book : ";
        cin >> bno;
        cout << "\nEnter The Name of The Book : ";
        cin >> bname;
        cout << "\nEnter The Author's Name : ";
        cin >> aname;
        cout << "\n\n\nBook Created..";
    }
    void show_book()
    {
        cout << "\nBook no. : " << bno;
        cout << "\nBook Name : " << bname;
        cout << "\nAuthor Name : " << aname;
        if (status == 1)
        {
            cout << endl
                 << endl;
            cout << "Issued By : ";
            cout << "\n============================================";
            cout << "\n\tLibrary no. : " << bklib;
        }
    }

    void modify_book()
    {
        char bn[50], an[20];
        cout << "\nEnter new Book Name or press (.) to retain old one : ";
        cin >> bn;
        cout << "\nEnter new Author's Name or press (.) to retain old one : ";
        cin >> an;
        if (strcmp(bn, ".") != 0)
            strcpy(bname, bn);
        if (strcmp(an, ".") != 0)
            strcpy(aname, an);
    }

    int retbno()
    {
        return bno;
    }
    int retbklib()
    {
        return bklib;
    }

    int retstatus()
    {
        return status;
    }

    void addstatus()
    {
        status = 1;
    }

    void resetstatus()
    {
        status = 0;
    }

    void getbklib(int t)
    {
        bklib = t;
    }
    void report()
    {
        cout << bno << setw(30) << bname << setw(30) << aname << endl;
    }

}; //class ends here

class student
{
    int libno;
    char name[20];
    int Class;
    int stbno;
    int token;
    int id, im, iy, rd, rm, ry, cd, cm, cy;
    float fine;

public:
    void create_student()
    {
        //clrscr();
        cout << "\nNEW STUDENT ENTRY...\n";
        cout << "\n\nEnter Library No. of the Student: ";
        cin >> libno;
        cout << "\nEnter The Name of The Student : ";
        cin >> name;
        cout << "\nEnter Class of the Student : ";
        cin >> Class;
        cout << "\n\nStudent Record Created..";
    }

    void show_student()
    {
        cout << "\nLibrary no. : " << libno;
        cout << "\nStudent Name : " << name;
        cout << "\nClass : " << Class;
        if (token == 1)
        {
            cout << endl
                 << endl;
            cout << "Books issued : ";
            cout << "\n============================================";
            cout << "\n\tBook No : " << stbno;
            cout << "\n\tIssued on : " << id << " " << im << " " << iy;
            cout << "\n\tReturn Date : " << rd << " " << rm << " " << ry;
        }
    }

    void modify_student()
    {
        char sn[20];
        int c;
        cout << "\nEnter new Student Name or press (.) to retain old one: ";
        cin >> sn;
        cout << "\nEnter new Class or press (-1) to retain old one : ";
        cin >> c;
        if (strcmp(sn, ".") != 0)
            strcpy(name, sn);
        if (c != -1)
            Class = c;
    }

    void irdate()
    {
        cout << "\n\n\tEnter Issue Date (dd mm yy) : ";
        cin >> id >> im >> iy;
        cout << "\n\tYour Return Date Is : ";
        if (id < 15)
        {
            rd = id + 15;
            rm = im;
            ry = iy;
        }
        else if ((id >= 15) && (im != 12))
        {
            rd = id + 15 - 30;
            rm = im + 1;
            ry = iy;
        }
        else if ((id >= 15) && (im == 12))
        {
            rd = id + 15 - 30;
            if (rd == 0)
                rd = 1;
            rm = 1;
            ry = iy + 1;
        }
        cout << rd << " " << rm << " " << ry;
    }

    void calcfine()
    {
        cout << "\n\n\tEnter Today's Date (dd mm yy) : ";
        cin >> cd >> cm >> cy;
        cout << "\n\tYour Return Date was : ";
        cout << rd << " " << rm << " " << ry;
        if ((im == cm) && (iy == cy))
        {
            fine = ((cd - id) - 15) * 2;
        }
        else if ((iy == cy) && (im < cm))
        {
            fine = (((cm - im) * 30 + (cd - id)) - 15) * 2;
        }
        else if (iy != cy)
        {
            fine = (((cy - iy) * 365 + (cm - im) * 30 + (cd - id)) - 15) * 2;
        }
        if (fine < 0)
            fine = 0;
        cout << "\nFine to be deposited : RS. " << fine;
    }

    int retlibno()
    {
        return libno;
    }

    int retstbno()
    {
        return stbno;
    }

    int rettoken()
    {
        return token;
    }

    void addtoken()
    {
        token = 1;
    }

    void resettoken()
    {
        token = 0;
    }

    void getstbno(int t)
    {
        stbno = t;
    }

    void report()
    {
        cout << "\t" << libno << setw(20) << name << setw(10) << Class << setw(10) << token << endl;
    }

}; //class ends here

//***************************************************************
//    	global declaration for stream object, object
//****************************************************************

fstream fp, fp1;
book bk;
student st;

//***************************************************************
//    	function to write in file
//****************************************************************

void write_book()
{
    char ch;
    fp.open("books.dat", ios::out | ios::app);
    do
    {
        //clrscr();
        bk.create_book();
        fp.write((char *)&bk, sizeof(book));
        cout << "\n\nDo you want to add more record..(y/n?) ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

void write_student()
{
    char ch;
    fp.open("students.dat", ios::out | ios::app);
    do
    {
        st.create_student();
        fp.write((char *)&st, sizeof(student));
        cout << "\n\ndo you want to add more record..(y/n?) ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_spb(int n)
{
    cout << "\n\n\tBOOK DETAILS";
    cout << "\n____________________________________________________________\n";
    int flag = 0;
    fp.open("books.dat", ios::in);
    while (fp.read((char *)&bk, sizeof(book)))
    {
        if (bk.retbno() == n)
        {
            bk.show_book();
            flag = 1;
        }
    }

    fp.close();
    if (flag == 0)
        cout << "\n\nBook does not exist";
    getch();
}

void display_sps(int n)
{
    cout << "\n\n\tSTUDENT DETAILS";
    cout << "\n____________________________________________________________\n";
    int flag = 0;
    fp.open("students.dat", ios::in);
    while (fp.read((char *)&st, sizeof(student)))
    {
        if (st.retlibno() == n)
        {
            st.show_student();
            flag = 1;
        }
    }

    fp.close();
    if (flag == 0)
        cout << "\n\nStudent does not exist";
    getch();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_book()
{
    int n;
    int found = 0;
    //clrscr();
    cout << "\n\n\tMODIFY BOOK REOCORD";
    cout << "\n____________________________________________________________";
    cout << "\n\n\tEnter The book no. of The book : ";
    cin >> n;
    fp.open("books.dat", ios::in | ios::out);
    while (fp.read((char *)&bk, sizeof(book)) && found == 0)
    {
        if (bk.retbno() == n)
        {
            bk.show_book();
            cout << "\n\nEnter The New Details of book" << endl;
            cout << "----------------------------------------------";
            bk.modify_book();
            int s = (int)sizeof(bk);
            int pos = -1 * s;
            fp.seekp(pos, ios::cur);
            fp.write((char *)&bk, sizeof(book));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }

    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}

void modify_student()
{
    int n;
    int found = 0;
    //clrscr();
    cout << "\n\n\tMODIFY STUDENT RECORD";
    cout << "\n____________________________________________________________";
    cout << "\n\n\tEnter The library no. of The student : ";
    cin >> n;
    fp.open("students.dat", ios::in | ios::out);
    while (fp.read((char *)&st, sizeof(student)) && found == 0)
    {
        if (st.retlibno() == n)
        {
            st.show_student();
            cout << "\n\nEnter The New Details of student" << endl;
            cout << "----------------------------------------------";
            st.modify_student();
            int s = (int)sizeof(st);
            int pos = -1 * s;
            fp.seekp(pos, ios::cur);
            fp.write((char *)&st, sizeof(student));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }

    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_student()
{
    int n, flag = 0;
    char confirm = 'n';
    //clrscr();
    cout << "\n\n\tDELETE STUDENT...";
    cout << "\n____________________________________________________________";
    cout << "\n\nEnter The library no. of the Student You Want To Delete : ";
    cin >> n;
    fp.open("students.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&st, sizeof(student)))
    {
        if (st.retlibno() == n)
        {
            st.show_student();
            flag = 1;
            cout << "\n\n\tDo you really want to delete the record?";
            cin >> confirm;
            if (confirm == 'n' || confirm == 'N')
                fp2.write((char *)&st, sizeof(student));
        }
        else
            fp2.write((char *)&st, sizeof(student));
    }
    fp2.close();
    fp.close();
    remove("students.dat");
    rename("Temp.dat", "students.dat");
    if (flag == 1)
        cout << "\n\n\tRecord Deleted ..";
    else
        cout << "\n\nRecord not found";
    getch();
}

void delete_book()
{
    int n;
    char confirm = 'n';
    //clrscr();
    cout << "\n\n\tDELETE BOOK";
    cout << "\n____________________________________________________________";
    cout << "\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin >> n;
    fp.open("books.dat", ios::in | ios::out);
    //fp.open("books.dat", ios::in || ios::out);
    fstream fp3;
    fp3.open("Temp1.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&bk, sizeof(book)))
    {
        if (bk.retbno() == n)
        {
            bk.show_book();
            cout << "\n\n\tDo you really want to delete the record?";
            cin >> confirm;
            if (confirm == 'n' || confirm == 'N')
                fp3.write((char *)&bk, sizeof(book));
        }
        else
            fp3.write((char *)&bk, sizeof(book));
    }

    fp3.close();
    fp.close();
    remove("books.dat");
    rename("Temp1.dat", "books.dat");
    cout << "\n\n\tRecord Deleted ..";
    getch();
}

//***************************************************************
//    	function to display all students list
//****************************************************************

void display_alls()
{
    //clrscr();
    fp.open("students.dat", ios::in);
    cout << "\n\n\t\tSTUDENT LIST\n\n";
    cout << "==================================================================\n";
    cout << "\tLibrary No." << setw(10) << "Name" << setw(10) << "Class" << setw(20) << "Book Issued\n";
    cout << "==================================================================\n";

    while (fp.read((char *)&st, sizeof(student)))
    {
        st.report();
    }

    fp.close();
}

//***************************************************************
//    	function to display Books list
//****************************************************************

void display_allb()
{
    //clrscr();
    fp.open("books.dat", ios::in);
    cout << "\n\n\t\tBook LIST\n\n";
    cout << "=========================================================================\n";
    cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author\n";
    cout << "=========================================================================\n";

    while (fp.read((char *)&bk, sizeof(book)))
    {
        bk.report();
    }
    fp.close();
}

//***************************************************************
//    	function to issue book
//****************************************************************

void book_issue()
{
    int sn, bn;
    int found = 0, flag = 0;
    //clrscr();
    cout << "\n\n\tBOOK ISSUE";
    cout << "\n____________________________________________________________";
    cout << "\n\n\tEnter The student's admission no.";
    cin >> sn;
    fp.open("students.dat", ios::in | ios::out);
    fp1.open("books.dat", ios::in | ios::out);
    while (fp.read((char *)&st, sizeof(student)) && found == 0)
    {
        if (st.retlibno() == sn)
        {
            found = 1;
            if (st.rettoken() == 0)
            {
                cout << "\n\n\tEnter the book no. ";
                cin >> bn;
                while (fp1.read((char *)&bk, sizeof(book)) && flag == 0)
                {
                    if (bk.retbno() == bn)
                    {
                        if (bk.retstatus() == 0)
                        {
                            bk.show_book();
                            flag = 1;
                            st.addtoken();
                            bk.addstatus();
                            st.getstbno(bk.retbno());
                            bk.getbklib(st.retlibno());
                            st.irdate();
                            int s = (int)sizeof(st);
                            int pos = -1 * s;
                            fp.seekp(pos, ios::cur);
                            fp.write((char *)&st, sizeof(student));
                            int s1 = (int)sizeof(bk);
                            int pos1 = -1 * s1;
                            fp1.seekp(pos1, ios::cur);
                            fp1.write((char *)&bk, sizeof(book));
                            cout << "\n\n\t Book issued successfully";
                        }
                        else
                        {
                            flag = 1;
                            cout << "\nBook already issued...";
                        }
                    }
                }
                if (flag == 0)
                    cout << "Book no does not exist";
            }
            else
                cout << "\n\tYou have not returned the last book ";
        }
    }
    if (found == 0)
        cout << "Student record not exist...";
    getch();
    fp.close();
    fp1.close();
}

//***************************************************************
//    	function to deposit book
//****************************************************************

void book_deposit()
{
    int sn, bn;
    int found = 0, flag = 0;
    //clrscr();
    cout << "\n\n\tBOOK DEPOSIT";
    cout << "\n____________________________________________________________";
    cout << "\n\n\tEnter The student library no.";
    cin >> sn;
    fp.open("students.dat", ios::in | ios::out);
    fp1.open("books.dat", ios::in | ios::out);
    while (fp.read((char *)&st, sizeof(student)) && found == 0)
    {
        if (st.retlibno() == sn)
        {
            found = 1;
            if (st.rettoken() == 1)
            {
                while (fp1.read((char *)&bk, sizeof(book)) && flag == 0)
                {
                    if (bk.retbno() == st.retstbno())
                    {
                        bk.show_book();
                        flag = 1;
                        st.resettoken();
                        st.calcfine();
                        bk.resetstatus();
                        int s = (int)sizeof(st);
                        int pos = -1 * s;
                        fp.seekp(pos, ios::cur);
                        fp.write((char *)&st, sizeof(student));
                        int s1 = (int)sizeof(bk);
                        int pos1 = -1 * s1;
                        fp1.seekp(pos1, ios::cur);
                        fp1.write((char *)&bk, sizeof(book));
                        cout << "\n\n\t Book deposited successfully";
                    }
                }
                if (flag == 0)
                    cout << "Book no does not exist";
            }
            else
                cout << "No book is issued..please check!!";
        }
    }
    if (found == 0)
        cout << "Student record not exist...";
    getch();
    fp.close();
    fp1.close();
}

//***********************************************************
//		Main Function
//***********************************************************

int main()
{
    //clrscr();
    int num, c, c1, c2;
    cout << "\n\n\t\t***************************************************";
    cout << "\n\n\t\t\t\tLIBRARY MANAGEMENT";
    cout << "\n\n\t\t***************************************************";
    cout << "\n\t\t\tPRESS ANY KEY TO CONTINUE........";
    getch();
main_menu:
    //clrscr();
    cout << "\n\n\n\tCHOOSE THE SECTION YOU WANT TO ACCESS :>";
    cout << "\n--------------------------------------------------------";
    cout << "\n\n\t\t[1]. :=>  ACCESS THE ADMIN SECTION";
    cout << "\n\n\t\t[2]. :=>  ACCESS THE LIBRARY SECTION";
    cout << "\n\n\t\t[3]. :=>  QUIT";
    cout << "\n\nENTER YOUR CHOICE :=>";
    cin >> c;
admin_menu:
    switch (c)
    {
    case 1:
        //clrscr();
        cout << "\n\n\t\t\t\tADMIN SECTION";
        cout << "\n\t============================================================";
        cout << "\n\n\t\t(1). :=>  ENTER NEW BOOK RECORD";
        cout << "\n\n\t\t(2). :=>  ENTER NEW STUDENT RECORD";
        cout << "\n\n\t\t(3). :=>  SEE ALL BOOK RECORDS";
        cout << "\n\n\t\t(4). :=>  SEE ALL STUDENT RECORDS";
        cout << "\n\n\t\t(5). :=>  MODIFY BOOK RECORD";
        cout << "\n\n\t\t(6). :=>  MODIFY STUDENT RECORD";
        cout << "\n\n\t\t(7). :=>  DELETE BOOK RECORD";
        cout << "\n\n\t\t(8). :=>  DELETE STUDENT RECORD";
        cout << "\n\n\t\t(9). :=>  BACK TO MAIN MENU";
        cout << "\n\nENTER YOUR CHOICE :=>";
        cin >> c1;
        switch (c1)
        {
        case 1:
            // clrscr();
            write_book();
            goto admin_menu;

        case 2:
            //clrscr();
            write_student();
            goto admin_menu;

        case 3:
            // clrscr();
            display_allb();
            cout << "\n\t\t\tPRESS ANY KEY TO CONTINUE........";
            getch();
            goto admin_menu;

        case 4:
            // clrscr();
            display_alls();
            cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE........";
            getch();
            goto admin_menu;

        case 5:
            //clrscr();
            modify_book();
            goto admin_menu;

        case 6:
            // clrscr();
            modify_student();
            goto admin_menu;

        case 7:
            //clrscr();
            delete_book();
            goto admin_menu;

        case 8:
            //clrscr();
            delete_student();
            goto admin_menu;

        case 9:
            goto main_menu;
        default:
            cout << "!!!SORRY....WRONG CHOICE.  TRY AGAIN!!!";
            goto admin_menu;
        }
    library_menu:
    case 2:
        //clrscr();
        cout << "\n\n\t\t\t\tLIBRARY SECTION";
        cout << "\n\t========================================================";
        cout << "\n\n\t\t(1). :=>  ISSUE BOOKS";
        cout << "\n\n\t\t(2). :=>  DEPOSIT BOOKS";
        cout << "\n\n\t\t(3). :=>  SEARCH BOOK";
        cout << "\n\n\t\t(4). :=>  SEARCH STUDENT";
        cout << "\n\n\t\t(5). :=>  BACK TO MAIN MENU";
        cout << "\n\nENTER YOUR CHOICE :=>";
        cin >> c2;
        switch (c2)
        {
        case 1:
            //clrscr();
            book_issue();
            goto library_menu;

        case 2:
            //clrscr();
            book_deposit();
            goto library_menu;

        case 3:
            //clrscr();
            cout << "\n\n\tPlease Enter The book No. ";
            cin >> num;
            display_spb(num);
            goto library_menu;

        case 4:
            //clrscr();
            cout << "\n\n\tPlease Enter The library no.. ";
            cin >> num;
            display_sps(num);
            goto library_menu;

        case 5:
            goto main_menu;

        default:
            cout << "!!!SORRY....WRONG CHOICE.  TRY AGAIN!!!";
            goto library_menu;
        }
    case 3:
        exit(0);
    default:
        cout << "!!!SORRY....WRONG CHOICE.  TRY AGAIN!!!";
        goto main_menu;
    }
    return 0;
}
