/*Author : Abdelrahman Ehab Deghedy */
/***********************************************/
/* Dear Dr El Habrok:
* For the love of GOD, let me pass..
*    ------
*   |  ---  \
*   | |    \ \
*   | |     \ |
*   | |     | |
*   | |     / /
*   |  --- / /
*    -------     eghedy
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include <sstream>
#include <utility>
#include <stdlib.h>
using namespace std;


// Global Variables
int current_month;
int current_year;


// Structs --> 17 structs

struct ID
{
    int type;
    string number;
};

struct homeAddress
{
    int flatNumber;
    int houseNumber;
    string streetName;
    string areaName;
    string cityName;
    string governorateName;
    string country;
    int postalCode;
};

struct mailAddress
{
    int flatNumber;
    int houseNumber;
    string streetName;
    string areaName;
    string cityName;
    string governorateName;
    string country;
    int postalCode;
};

struct date
{
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
};


struct paymentDetails
{
    int amountPaid;
    int transictionNumber;
    int BankOfTransaction;
    date tranaction;
};

struct payments
{
    int accountRegis = INT_MAX;
    int money;
    string history;
    int typeOfFunding;
    int numberOfPayments;
    int totalAmountPaid;
    paymentDetails payment[1000];
};

struct contact
{
    string mobileNumber;
    string homeNumber;
    string email;
};

struct creditHour
{
    int maxHours;
    int finishedHours;
    int currentHours;
    int remainingHours;
};
struct GPA
{
    double currentSemster;
    double semestersCount;
    double semesterIndividual [10];
};

struct courseTutors
{
    string lecturerName;
    string GTAname;
    string labGTAname;
};

struct marks
{
    double firstMidTerm;
    double secondMidTerm;
    double yeatWork;
    double finalExam;
    double totalSum;
};
struct semester
{
  double semsterIndex;              //contains index + 1 of a semester
  double semsterGrades[10];         // each element represents the sum of grades for each semester
  double semesterCourseCounter[10]; // contains number of courses per semester, so that you can predict the full marks of overall courses

};

struct courseDetails
{
  string code;
  string name;
  int creditHours;
  int courseRepeatTimes;
  courseTutors tutor;
  marks mark;
  double percentageAbsence;
  string grade;
};

struct finished
{
    int numberOfCourses;
    int numberOfCreditHours;
    int totalMarks;
    courseDetails finishedCourses[100];
};
struct current
{
    int numberOfCourses;
    int numberOfCreditHours;
    int totalMarks;
    courseDetails currentCourse[8];
};

struct courses
{
    finished finish;
    current cur;
};

struct student
{
    string firstName;
    string middle_name;
    string lastName;
    bool gender;
    string nationality;
    int department;
    int firstEnrollmentTerm;
    homeAddress studentHomeAddress;
    mailAddress studentMailAddress;
    date studentDate;
    payments studentPay;
    semester studentSemester;
    contact studentContact;
    courses studentCourse;
    creditHour studCredit;
    GPA studGPA;
    ID studentID;
};

// Functions --> 22 functions

string menu ()
{
    string option;
    cout << "[1] Enter new student\n";
    cout << "[2] print student info\n";
    cout << "[3] Read student info from a text file\n";
    cout << "[4] Print student info in a text file\n";
    cout << "[5] Enter new payment\n";
    cout << "[6] Check Payment Details\n";
    cout << "[7] Edit Student Details\n";
    cout << "[8] Sort\n";
    cout << "[9] Courses Enrollment\n";
    cout << "[10] Courses Information\n";
    cout << "[11] Exit The Program\n\n[12] About\n";
    cout << "Enter the number that corresponds to the option you want!\n";
    cin >> option;
    return option;
}

string current_time ()
{
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
	string x (tm);
	return x;
}

int calculate_age (int year, int mon)
{
    time_t curr_time;
	curr_time = time(NULL);

	char *tm = ctime(&curr_time);
	string x (tm);
    current_year = stoi(x.substr (20, 4));
    string month = x.substr(4, 3);
    string months [12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 1; i <= 12; i++)
    {
        if (months[i] == month)
        {
            current_month = i + 1;
            break;
        }
    }
    int age = current_year - year - 1;
    if (mon < current_month)
        age++;

    return age;
}

void get_age (date *age)
{
    int temp;
    cout << "Enter Your Day Of Birth: ";
    cin >> temp;
    while (temp < 1 || temp > 31 )
    {
        cout << "\nEnter a number between 1 ~ 31\n";
        cin >> temp;
    }
    age -> dayOfBirth = temp;
    cout << "\n";
    cout << "Enter Your Month Of Birth: ";
    cin >> temp;
    while (temp < 1 || temp > 12)
    {
        cout << "\nEnter a number between 1 ~ 12\n";
        cin >> temp;
    }
    age -> monthOfBirth = temp;
    cout << "\n";
    cout << "Enter Your Year Of Birth: ";
    cin >> temp;
    while (temp < 1980 || temp > 2020)
    {
        cout << "\nEnter a number between 1980 and 2020" << "\n";
        cin >> temp;
    }
    age -> yearOfBirth = temp;
    cout << "\n";
}

int determine_current_semester (const student *stud1)
{
    int current_semester;
    for (int i = 9; i >= 0; i--)
    {
        if (stud1->studentSemester.semesterCourseCounter[i] != 0)
            current_semester = i + 1;
    }
    return current_semester;
}

string generate_ID (student *stud1, int student_num)
{
    string x;
    x.append("2020");
    x.append(to_string(student_num));
    x.append(to_string(determine_current_semester(stud1)));
    return x;
}

void zero_init (student *stud1)
{
    stud1->studentCourse.cur.numberOfCourses = 0;
    stud1->studentCourse.cur.totalMarks = 0;
    stud1->studGPA.currentSemster = 0;
    stud1->studCredit.maxHours = 204;
    stud1->studCredit.currentHours = 0;
    stud1->studCredit.finishedHours = 0;
}

void readNewStudent (student *stud1, int student_num)
{
            zero_init(stud1);
            stud1->studentID.number = generate_ID(stud1, student_num);
            int min_choice, another_option;
            cout << "[1] Enter Basic Info\n";
            cout << "[2] Enter Your Address\n";
            cout << "[3] Go back to main menu\n";
            cin >> min_choice;
            if (min_choice == 1)
            {
            system("CLS");
            cout << "Enter First Name: ";
            cin >> stud1->firstName;
            cout << "\n";
            cout << "Enter Middle Name: ";
            cin >> stud1->middle_name;
            cout << "\n";
            cout << "Enter Last Name: ";
            cin >> stud1->lastName;
            cout << "\n";
            cout << "Enter Your Gender  (0 for male, 1 for female): ";
            int temp;
            cin >> temp;
            while (temp != 0 && temp != 1)
            {
                cout << "invalid input!, try again: ";
                cin >> temp;
            }
            stud1->gender = temp;
            cout << "\n";
            cout << "Enter Your Department: (0 For Computer, 1 For Electrical Engineering, 2 For Power, 3 For Production, 4 for Mechanics): \n";
            cin >> stud1->department;
            cout << "\n";
            cout << "Enter Your Nationality: ";
            cin >> stud1->nationality;
            cout << "\n";
            cout << "Enter Your Home Phone Number: ";
            cin >> stud1 ->studentContact.homeNumber;
            cout << "\n";
            cout << "Enter Your Mobile Number: ";
            cin >> stud1 ->studentContact.mobileNumber;
            cout << "\n";
            cout << "Enter Your Contact Email: ";
            cin >> stud1 ->studentContact.email;
            cout << "\n";

            get_age (&stud1 -> studentDate);
            cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
            cin >> another_option;
            if (another_option == 0)
            {
                system("CLS");
                return;
            }

            }
            else if (min_choice == 2)
            {
            system("CLS");
            cout << "Entering Home Address\n\n";
            cout << "Enter Country Name: ";
            cin >> stud1 -> studentHomeAddress.country;
            cout << "\n";
            cout << "Enter Governorate Name: ";
            cin >> stud1 -> studentHomeAddress.governorateName;
            cout << "\n";
            cout << "Enter City Name: ";
            cin >> stud1 ->studentHomeAddress.cityName;
            cout << "\n";
            cout << "Enter Area Name: ";
            cin >> stud1 ->studentHomeAddress.areaName;
            cout << "\n";
            cout << "Enter Street Name: ";
            cin >> stud1 ->studentHomeAddress.streetName;
            cout << "\n";
            cout << "Enter House Number: ";
            cin >> stud1 ->studentHomeAddress.houseNumber;
            cout << "\n";
            cout << "Enter Flat Number: ";
            cin >> stud1 ->studentHomeAddress.flatNumber;
            cout << "\n";
            cout << "Enter Postal Code: ";
            cin >> stud1 ->studentHomeAddress.postalCode;
            cout << "\n";

            int extra_info;
            cout << "Is your mail address same as your home address? (1 for yes, 0 for no): ";
            cin >> extra_info;
            if (extra_info == 0)
            {
            cout << "Entering Mail Address\n\n";
            cout << "Enter Country Name: ";
            cin >> stud1 ->studentMailAddress.country;
            cout << "\n";
            cout << "Enter Governorate Name: ";
            cin >> stud1 -> studentMailAddress.governorateName;
            cout << "\n";
            cout << "Enter City Name: ";
            cin >> stud1 ->studentMailAddress.cityName;
            cout << "\n";
            cout << "Enter Area Name: ";
            cin >> stud1 ->studentMailAddress.areaName;
            cout << "\n";
            cout << "Enter Street Name: ";
            cin >> stud1 ->studentMailAddress.streetName;
            cout << "\n";
            cout << "Enter House Number: ";
            cin >> stud1 ->studentMailAddress.houseNumber;
            cout << "\n";
            cout << "Enter Flat Number: ";
            cin >> stud1 ->studentMailAddress.flatNumber;
            cout << "\n";
            cout << "Enter Postal Code: ";
            cin >> stud1 ->studentMailAddress.postalCode;
            cout << "\n";
            cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
            cin >> another_option;
            if (another_option == 0)
            {
                system("CLS");
                return;
            }
            }
            else
            {
                stud1 ->studentMailAddress.areaName = stud1 ->studentHomeAddress.areaName;
                stud1 ->studentMailAddress.cityName = stud1 ->studentHomeAddress.cityName;
                stud1 ->studentMailAddress.country = stud1 ->studentHomeAddress.country;
                stud1 ->studentMailAddress.flatNumber = stud1 ->studentHomeAddress.flatNumber;
                stud1 ->studentMailAddress.governorateName = stud1 ->studentHomeAddress.governorateName;
                stud1 ->studentMailAddress.houseNumber = stud1 ->studentHomeAddress.houseNumber;
                stud1 ->studentMailAddress.postalCode = stud1 ->studentHomeAddress.postalCode;
                stud1 ->studentMailAddress.streetName = stud1 ->studentHomeAddress.streetName;
                cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
                cin >> another_option;
                if (another_option == 0)
                {
                    system("CLS");
                    return;
                }
            }
            }
            else
            {
                system("CLS");
                return;
            }


}

void printStudentData (const student *stud1)
{
            cout << "Student ID: " <<  stud1->studentID.number<< "\n";
            cout << "\nStudent First Name: ";
            cout << stud1 -> firstName;
            cout << "\n";
            cout << "Student Middle Name: ";
            cout << stud1 -> middle_name;
            cout << "\n";
            cout << "Student Last Name: ";
            cout << stud1 -> lastName;
            cout << "\n";
            cout << "Student Gender: ";
            if (stud1 -> gender == 0)
                cout << "Male";
            else
                cout << "Female";
            cout << "\n";
            cout << "Student Department: ";
            if (stud1->department == 0)
                cout << "Computer";
            else if (stud1->department == 1)
                cout << "Electrical Engineering";
            else if (stud1->department == 2)
                cout << "Power";
            else if (stud1->department == 3)
                cout << "Production";
            else if (stud1->department == 4)
                cout << "Mechanics";
            cout << "\n";
            cout << "Student Nationality: ";
            cout << stud1 -> nationality;
            cout << "\n";
            cout << "Student Date Of Birth: ";
            cout << stud1 -> studentDate.dayOfBirth << "/" << stud1 -> studentDate.monthOfBirth << "/" << stud1 -> studentDate.yearOfBirth;
            cout << "\n";
            cout << "Student Age: ";
            cout << calculate_age(stud1 -> studentDate.yearOfBirth, stud1 -> studentDate.monthOfBirth);
            cout << "\n";

            cout << "Enter Your Home Phone Number: ";
            cout << stud1 ->studentContact.homeNumber << "\n";
            cout << "Enter Your Mobile Number: ";
            cout << stud1 ->studentContact.mobileNumber << "\n";
            cout << "Enter Your Contact Email: ";
            cout << stud1 ->studentContact.email << "\n";
            cout << setw(50) << left << "\nPrinting Mail Address" << "Printing Home Address\n";
            cout << "Country Name: \n";
            cout << setw(50) << stud1 ->studentMailAddress.country << stud1 ->studentHomeAddress.country <<  "\n";
            cout << "Governorate Name: \n";
            cout << setw(50) << left << stud1 -> studentMailAddress.governorateName << stud1 ->studentHomeAddress.governorateName << "\n";
            cout << "City Name: \n";
            cout << setw(50) << left << stud1 ->studentMailAddress.cityName << stud1 ->studentHomeAddress.cityName<< "\n";
            cout << "Area Name: \n";
            cout << setw(50) << left << stud1 ->studentMailAddress.areaName << stud1 ->studentHomeAddress.areaName<< "\n";
            cout << "Street Name: \n";
            cout << setw(50) << left << stud1 ->studentMailAddress.streetName << stud1 ->studentHomeAddress.streetName<< "\n";
            cout << "House Number: \n";
            cout << setw(50) << left << stud1 ->studentMailAddress.houseNumber << stud1 ->studentHomeAddress.houseNumber<< "\n";
            cout << "Flat Number: \n";
            cout << setw(50) << left << stud1 ->studentMailAddress.flatNumber << stud1 ->studentHomeAddress.flatNumber<< "\n";
            cout << "Postal Code: \n";
            cout << setw(50) << left << stud1 ->studentMailAddress.postalCode << stud1 ->studentHomeAddress.postalCode<< "\n";
}

int getPayementDetailsMenu ()
{
    int choice;
    cout << "[1] Transactions\n";
    cout << "[2] Make New Payment\n";
    cout << "[3] Go Back\n";
    cin >> choice;
    return choice;
}

void getPayementDetails (student *stud1)
{
    int choice = -1;
    while (choice != 3)
    {
        choice = getPayementDetailsMenu();
        system("CLS");
        if (choice == 1)
        {
            int mini_choice;

            while (mini_choice != 3)
            {
                cout << "[1] Deposit\n";
                cout << "[2] Withdraw\n";
                cout << "[3] Go Back!\n";
                cin >> mini_choice;
                system("CLS");
                if (mini_choice == 1)
                {
                    int temp, another_option;
                    cout << "Enter the amount you want to deposit: ";
                    cin >> temp;
                    stud1 -> studentPay.money += temp;
                    stud1 -> studentPay.history.append("+ ");
                    stud1 -> studentPay.history.append(to_string(temp));
                    stud1 -> studentPay.history.append("\t\t");
                    stud1 -> studentPay.history.append(current_time());
                    stud1 -> studentPay.history.append("\n");
                    cout << "\nYou Finished Successfully, Enter 0 To Go Back To Payment Menu: ";
                    cin >> another_option;
                    if (another_option == 0)
                        {
                            system("CLS");
                            continue;
                        }
                }
                else if (mini_choice == 2)
                {
                    int temp, another_option;
                    cout << "Enter the amount you want to withdraw: ";
                    cin >> temp;
                    while (temp > stud1 -> studentPay.money)
                    {
                        cout << "Can't afford, enter less money!\n";
                        cin >> temp;
                    }
                    stud1 -> studentPay.money -= temp;
                    stud1 -> studentPay.history.append("- ");
                    stud1 -> studentPay.history.append(to_string(temp));
                    stud1 -> studentPay.history.append("\t\t");
                    stud1 -> studentPay.history.append(current_time());
                    stud1 -> studentPay.history.append("\n");
                    cout << "\nYou Finished Successfully, Enter 0 To Go Back To Payment Menu: ";
                    cin >> another_option;
                    if (another_option == 0)
                        {
                            system("CLS");
                            continue;
                        }
                }
                else
                {
                    system("CLS");
                    return;
                }
            }
            getPayementDetails(stud1);
        }
        else if (choice == 2)
        {
                int opt;
                if (stud1 -> studentPay.typeOfFunding == 1)
                {
                    cout << "You are grant-funded, you don't have to pay!, enter 0 to go back: ";
                    cin >> opt;
                    if (opt == 0)
                    {
                        system("CLS");
                        continue;
                    }
                }
                else
                {
                int temp, another_option;
                cout << "Enter the new payment value: ";
                cin >> temp;
                while (temp > stud1 -> studentPay.money)
                {
                    cout << "Can't afford, enter less money!\n";
                    cin >> temp;
                }
                    stud1 -> studentPay.money -= temp;
                    stud1 -> studentPay.history.append("- ");
                    stud1 -> studentPay.history.append(to_string(temp));
                    stud1 -> studentPay.history.append("\t\t");
                    stud1 -> studentPay.history.append(current_time());
                    stud1 -> studentPay.history.append("\n");
                    stud1 -> studentPay.totalAmountPaid += temp;
                    stud1 -> studentPay.numberOfPayments ++;
                    cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
                    cin >> another_option;
                    if (another_option == 0)
                    {
                        system("CLS");
                        continue;
                    }
                }
        }
        else
        {
            system("CLS");
            return;
        }


    }
    system("CLS");
    return;

}

void print_payment_details (const student *stud1)
{
    int temp;
    if (stud1 -> studentPay.accountRegis == INT_MAX)
    {
        int mini_op;
        cout << "Go back & Register first! (enter 0 to go back): ";
        cin >> mini_op;
        if (mini_op == 0)
        {
            system("CLS");
            return;
        }
    }
    cout << "Enter Your Registration Number: ";
    cin >> temp;
    while (temp != stud1 -> studentPay.accountRegis)
    {
        cout << "Invalid Number, try again: ";
        cin >> temp;
    }
    cout << "Type of Funding: ";
    if (stud1 ->studentPay.typeOfFunding == 1)
        cout << "Grant-Funded";
    else
        cout << "Self-Funded";
    cout << "\nHistory Of Transactions\n\n";
    cout << stud1 -> studentPay.history;
    cout << "\n";
    cout << "Remaining Money: ";
    cout << stud1 -> studentPay.money;
    cout << "\n";
    cout << "Number of payments: ";
    cout << stud1 -> studentPay.numberOfPayments;
    cout << "\n";


}

void enter_courses_info (student *stud1)
{
    int option;
    stud1->studCredit.maxHours = 204;
    cout << "[1] Enroll Current Courses\n[2] Enter Finished Courses\n[3] Go back\n";
    cin >> option;
    if (option == 1)
    {
        static int z = 0;
        int temp;
        system ("CLS");
        cout << "How many courses you want to enroll?\n";
        cin >> temp;
        while (temp > 8 || temp < 1)
        {
            cout << "invalid number, (only number from 1 to 8)\n";
            cin >> temp;
        }
        stud1->studentCourse.cur.numberOfCourses = temp;
        for (int i = z; i < 8 && i < z + temp; i++)
        {
            cout << "Enter course code: ";
            cin >> stud1->studentCourse.cur.currentCourse[i].code;
            cout << "\n";
            cout << "Enter course name: ";
            cin >> stud1->studentCourse.cur.currentCourse[i].name;
            cout << "\n";
            cout << "Enter course credit hours: (max: 3) ";
            {
                int temp;
                cin >> temp;
                while (temp > 3 || temp < 1)
                {
                    cout << "invalid input, try again: ";
                    cin >> temp;
                }
                stud1->studentCourse.cur.numberOfCreditHours += temp;
                stud1->studentCourse.cur.currentCourse[i].creditHours = temp;
                stud1->studCredit.currentHours += temp;
            }
            cout << "\n";
            cout << "Enter the number of times you took this course: ";
            cin >> stud1->studentCourse.cur.currentCourse[i].courseRepeatTimes;
            cout << "\n";
            cin.ignore();
            cout << "Enter course tutor full name: ";
            getline(cin, stud1->studentCourse.cur.currentCourse[i].tutor.lecturerName, '\n');
            cout << "\n";
            cout << "Enter course GTA full name: ";
            getline(cin, stud1->studentCourse.cur.currentCourse[i].tutor.GTAname, '\n');
            cout << "Entering course marks\nFirst midterm marks (out of 20): ";
            {
                double temp;
                cin >> temp;
                while (temp < 0 || temp > 20)
                {
                    cout << "Enter a valid input\n";
                    cin >> temp;
                }

            stud1->studentCourse.cur.currentCourse[i].mark.firstMidTerm = temp;
            }
            cout << "\n";
            cout << "Second midterm marks (out of 20): ";
            {
                double temp;
                cin >> temp;
                while (temp < 0 || temp > 20)
                {
                    cout << "Enter a valid input\n";
                    cin >> temp;
                }

                stud1->studentCourse.cur.currentCourse[i].mark.secondMidTerm = temp;
            }
            stud1->studentCourse.cur.currentCourse[i].mark.yeatWork = stud1->studentCourse.cur.currentCourse[i].mark.secondMidTerm + stud1->studentCourse.cur.currentCourse[i].mark.firstMidTerm;

            cout << "\n";
            cout << "Final exam marks (out of 60): ";
              {
                double temp;
                cin >> temp;
                while (temp < 0 || temp > 60)
                {
                    cout << "Enter a valid input\n";
                    cin >> temp;
                }

                stud1->studentCourse.cur.currentCourse[i].mark.finalExam = temp;
              }
              stud1->studentCourse.cur.currentCourse[i].mark.totalSum = stud1->studentCourse.cur.currentCourse[i].mark.finalExam + stud1->studentCourse.cur.currentCourse[i].mark.yeatWork;
              stud1->studentCourse.cur.totalMarks += stud1->studentCourse.cur.currentCourse[i].mark.totalSum;
            cout << "\n";
            cout << "Enter percentage absence during the course:% ";
            cin >> stud1->studentCourse.cur.currentCourse[i].percentageAbsence;
            cout << "\n";

        }
            z += temp;
            int mini_opt;
            cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
            cin >> mini_opt;
            if (mini_opt == 0)  return;
    }
    else if (option == 2)
    {
        static int z = 0;
        int temp;
        system ("CLS");
        cout << "How many courses you want to Enter?\n";
        cin >> temp;
        while (temp > 60 || temp < 1)
        {
            cout << "invalid number, (only number from 1 to 60)\n";
            cin >> temp;
        }
        stud1->studentCourse.finish.numberOfCourses = temp;
        for (int i = z; i < 60 && i < z + temp; i++)
        {
            cout << "Enter course code: ";
            cin >> stud1->studentCourse.finish.finishedCourses[i].code;
            cout << "\n";
            cout << "Enter course name: ";
            cin >> stud1->studentCourse.finish.finishedCourses[i].name;
            cout << "\n";
            cout << "Enter course credit hours: (max: 3) ";
            {
                int temp;
                cin >> temp;
                while (temp > 3 || temp < 1)
                {
                    cout << "invalid input, try again: ";
                    cin >> temp;
                }
                stud1->studentCourse.finish.numberOfCreditHours += temp;
                stud1->studentCourse.finish.finishedCourses[i].creditHours = temp;
                stud1->studCredit.finishedHours += temp;
            }
            cout << "\n";
            cout << "Enter the number of times you took this course: ";
            cin >> stud1->studentCourse.finish.finishedCourses[i].courseRepeatTimes;
            cout << "\n";
            cout << "Enter the semester in which you took this course: ";
            cin >> stud1->studentSemester.semsterIndex;
            int x = stud1->studentSemester.semsterIndex - 1;
            stud1->studentSemester.semesterCourseCounter[x] ++;


            cout << "\n";
            cout << "Enter course tutor full name: ";
            getline(cin, stud1->studentCourse.finish.finishedCourses[i].tutor.lecturerName, '\n');
            cout << "\n";
            cout << "Enter course GTA full name: ";
            getline(cin, stud1->studentCourse.finish.finishedCourses[i].tutor.GTAname, '\n');
            cout << "Entering course marks\nFirst midterm marks (out of 20): ";
            {
                double temp;
                cin >> temp;
                while (temp < 0 || temp > 20)
                {
                    cout << "Enter a valid input\n";
                    cin >> temp;
                }

                stud1->studentCourse.finish.finishedCourses[i].mark.firstMidTerm = temp;
            }
            cout << "\n";
            cout << "Second midterm marks (out of 20): ";
            {
                double temp;
                cin >> temp;
                while (temp < 0 || temp > 20)
                {
                    cout << "Enter a valid input\n";
                    cin >> temp;
                }

                stud1->studentCourse.finish.finishedCourses[i].mark.secondMidTerm = temp;
            }

            stud1->studentCourse.finish.finishedCourses[i].mark.yeatWork = stud1->studentCourse.finish.finishedCourses[i].mark.secondMidTerm + stud1->studentCourse.finish.finishedCourses[i].mark.firstMidTerm;
            cout << "\n";
            cout << "Final exam marks (out of 60): ";
              {
                double temp;
                cin >> temp;
                while (temp < 0 || temp > 60)
                {
                    cout << "Enter a valid input\n";
                    cin >> temp;
                }

                stud1->studentCourse.finish.finishedCourses[i].mark.finalExam = temp;
              }
              stud1->studentCourse.finish.finishedCourses[i].mark.totalSum = stud1->studentCourse.finish.finishedCourses[i].mark.finalExam + stud1->studentCourse.finish.finishedCourses[i].mark.yeatWork;
              stud1->studentCourse.finish.totalMarks += stud1->studentCourse.finish.finishedCourses[i].mark.totalSum;
              stud1->studentSemester.semsterGrades[x] += stud1->studentCourse.finish.finishedCourses[i].mark.totalSum;
            cout << "\n";

        }
        z += temp;
        int mini_opt;
        cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
        cin >> mini_opt;
        if (mini_opt == 0)  return;
    }
    else
    {
        system("CLS");
        return;
    }
}

string grade_calc (student *stud1, int sum)
{
    if (sum >= 93)
         return "A";
    else if (sum >= 90 && sum <= 92)
        return "A-";
    else if (sum >= 87 && sum <= 89)
        return  "B+";
    else if (sum >= 83 && sum <= 86)
        return  "B";
    else if (sum >= 80 && sum <= 82)
        return  "B-";
    else if (sum >= 77 && sum <= 79)
        return  "C+";
    else if (sum >= 73 && sum <= 76)
        return  "C";
    else if (sum >= 70 && sum <= 72)
        return  "C-";
    else if (sum >= 67 && sum <= 69)
        return  "D+";
    else if (sum >= 63 && sum <= 66)
        return  "D";
    else if (sum >= 60 && sum <= 62)
        return  "D-";
    else
        return  "F";
}

double GPA_calc (student *stud1, int sum)
{
    double gpa;
    if (sum == 0)
        return 0;
    return gpa = (double)sum / 20 - 1; // sum here must be <= 100
}

void set_GPA (student *stud1)
{
    if (stud1->studentCourse.cur.numberOfCourses == 0)
        stud1->studGPA.currentSemster = 0;
    else
        stud1->studGPA.currentSemster = GPA_calc(stud1, ((double)stud1->studentCourse.cur.totalMarks / stud1->studentCourse.cur.numberOfCourses));
    stud1->studGPA.semestersCount = 10;
    for (int i = 0; i < stud1->studGPA.semestersCount; i++)
    {
        if (stud1->studentSemester.semesterCourseCounter [i] == 0)
            continue;
        stud1->studGPA.semesterIndividual[i] = GPA_calc(stud1, (stud1->studentSemester.semsterGrades[i] / (double) stud1->studentSemester.semesterCourseCounter [i]));
    }
}

void print_gpa (const student *stud1)
{
    cout << "Current Semester GPA: " << setprecision(2) << fixed << stud1->studGPA.currentSemster << "\n";
    cout << "Previous Semesters GPA: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Semester " << i + 1 << "\t" << setprecision(2) << fixed << stud1->studGPA.semesterIndividual[i] << "\n";
    }
}

void set_credit_hours (student *stud1)
{
     stud1->studCredit.currentHours = stud1->studentCourse.cur.numberOfCreditHours;
     stud1->studCredit.finishedHours = stud1->studentCourse.finish.numberOfCreditHours;
}

void print_course_info (student *stud1)
{
    int choice;
    cout << "[1] print GPA\n[2] Credit Hours Info\n[3] Description Of Courses\n[4] Go back\n";
    cin >> choice;
    if (choice == 4)
    {
        system("CLS");
        return;
    }
    else if (choice == 1)
    {
        int another_option;
        system("CLS");
        print_gpa(stud1);
        cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
        cin >> another_option;
        if (another_option == 0)
        {
            system("CLS");
            return;
        }
    }
    else if (choice == 2)
    {
        int another_option;
        system("CLS");
        cout << "Finished: " << stud1->studCredit.finishedHours << "\n";
        cout << "Current: " << stud1->studentCourse.cur.numberOfCreditHours << "\n";
        cout << "Max: " << stud1->studCredit.maxHours << "\n";
        set_credit_hours(stud1);
        stud1->studCredit.remainingHours = stud1->studCredit.maxHours - stud1->studCredit.currentHours - stud1->studCredit.finishedHours;
        cout << "Remaining: " << stud1->studCredit.remainingHours << "\n";
        cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
        cin >> another_option;
         if (another_option == 0)
        {
            system("CLS");
            return;
        }
    }
    else if (choice == 3)
    {
        int another_option;
        system("CLS");
        cout << "Current Courses\n";
        for (int i = 0; i < stud1->studentCourse.cur.numberOfCourses; i++)
        {
            cout << "Course Code: " << stud1->studentCourse.cur.currentCourse[i].code << "\n";
            cout << "Course Name: " << stud1->studentCourse.cur.currentCourse[i].name << "\n";
            cout << "Course Credit Hours: " << stud1->studentCourse.cur.currentCourse[i].creditHours << "\n";
            cout << "Course Lecturer: " << stud1->studentCourse.cur.currentCourse[i].tutor.lecturerName<< "\n";
            cout << "Course GTA: " << stud1->studentCourse.cur.currentCourse[i].tutor.GTAname << "\n";
            cout << "Course Marks: " << stud1->studentCourse.cur.currentCourse[i].mark.totalSum << "\n";
            cout << "Course Grade: " << grade_calc(stud1, stud1->studentCourse.cur.currentCourse[i].mark.totalSum) << "\n";
            cout << "Student percentage absence: %" << stud1->studentCourse.cur.currentCourse[i].percentageAbsence << "\n";

        }

            cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
            cin >> another_option;
             if (another_option == 0)
            {
                system("CLS");
                return;
            }
    }
}

int read_file (vector <student> &students, int j)
{
    string myLovelyGarbage;
    ifstream reader ("read student.txt");
    if (!reader.is_open())
    {
        int min_opt;
        cout << "Can't found the file, please make sure to create a text file named (read student.txt) \nin the same directory as (main.cpp)\n";
        cout << "Enter 0 to go back to main menu: ";
        cin >> min_opt;
        if (min_opt == 0)
        {
            system("CLS");
            return j;
        }
    }
    getline(reader, myLovelyGarbage, '\n');
    getline(reader, myLovelyGarbage, '\n');
    myLovelyGarbage.clear();
    student stud1;

    while (!reader.eof())
    {
        int mini_choice;
        students.push_back(stud1);
        zero_init(&students[j]);
        students[j].studentID.number = generate_ID(&students[j], j);
        reader >> students[j].firstName;
        reader >> students[j].middle_name;
        reader >> students[j].lastName;
        reader >> students[j].gender;
        reader >> students[j].department;
        reader >> students[j].nationality;
        reader >> students[j].studentContact.homeNumber;
        reader >> students[j].studentContact.mobileNumber;
        reader >> students[j].studentContact.email;
        reader >> students[j].studentDate.dayOfBirth;
        reader >> students[j].studentDate.monthOfBirth;
        reader >> students[j].studentDate.yearOfBirth;
        reader >> students[j].studentHomeAddress.country;
        reader >> students[j].studentHomeAddress.governorateName;
        reader >> students[j].studentHomeAddress.cityName;
        reader >> students[j].studentHomeAddress.areaName;
        reader >> students[j].studentHomeAddress.streetName;
        reader >> students[j].studentHomeAddress.houseNumber;
        reader >> students[j].studentHomeAddress.flatNumber;
        reader >> students[j].studentHomeAddress.postalCode;
        reader >> mini_choice;
        if (mini_choice == 1)
        {
            string myLovelyGarbage;
            students[j].studentMailAddress.country =  students[j].studentHomeAddress.country;
            students[j].studentMailAddress.governorateName = students[j].studentHomeAddress.governorateName;
            students[j].studentMailAddress.cityName = students[j].studentHomeAddress.cityName;
            students[j].studentMailAddress.areaName = students[j].studentHomeAddress.areaName;
            students[j].studentMailAddress.streetName = students[j].studentHomeAddress.streetName;
            students[j].studentMailAddress.houseNumber = students[j].studentHomeAddress.houseNumber;
            students[j].studentMailAddress.flatNumber = students[j].studentHomeAddress.flatNumber;
            students[j].studentMailAddress.postalCode = students[j].studentHomeAddress.postalCode;
            getline(reader, myLovelyGarbage, '\n');
        }
        else
        {
            reader >> students[j].studentMailAddress.country;
            reader >> students[j].studentMailAddress.governorateName;
            reader >> students[j].studentMailAddress.cityName;
            reader >> students[j].studentMailAddress.areaName;
            reader >> students[j].studentMailAddress.streetName;
            reader >> students[j].studentMailAddress.houseNumber;
            reader >> students[j].studentMailAddress.flatNumber;
            reader >> students[j].studentMailAddress.postalCode;
        }
        j++;
    }
    j--;
    return j;
}

void write_file (vector <student> &students, int j)
{
    ofstream writer ("write student.txt" , ios::app);
    for (int i = 0; i < j; i++)
    {
        writer << setw(15) << left << students[i].firstName <<" ";
        writer << setw(15) << left << students[i].middle_name <<" ";
        writer << setw(15) << left << students[i].lastName <<" ";
        if (students[i].gender == 0)
            writer << setw(15) << left << "Male ";
        else
            writer << setw(15) << left << "Female ";
        if (students[i].department == 0)
            writer << setw(30) << left << "Computer ";
        else if (students[i].department == 1)
            writer << setw(30) << left << "Electrical Engineering ";
        else if (students[i].department == 2)
            writer << setw(30) << left << "Power ";
        else if (students[i].department == 3)
            writer << setw(30) << left << "Production ";
        else if (students[i].department == 4)
            writer << setw(30) << left << "Mechanics ";
        writer << setw(15) << left << students[i].nationality <<" ";
        writer << setw(15) << left << students[i].studentContact.homeNumber <<" ";
        writer << setw(15) << left << students[i].studentContact.mobileNumber <<" ";
        writer << setw(15) << left << students[i].studentContact.email <<" ";
        writer << "\n";
    }
}

int range_check (int j, int num)
{
        int flag = 0;
        while (num > j || num < 0)
        {
            cout << "Out of range! add this student first (0 to go back): ";
            cin >> num;
        }
        if (num == 0)
        {
            system("CLS");
            flag = 1;
        }
        return flag;
}

int ending_msg ()
{
        int another_option;
        cout << "\nYou Finished Successfully, Enter 0 To Go Back To Main Menu: ";
        cin >> another_option;
        if (another_option == 0)
        {
            system("CLS");
            return 1;
        }
        return ending_msg();
}

int main()
{
    int j = 0;
    string option;
    vector <student> students(0);
    while (option != to_string(11))
    {
    option = menu ();
    system("CLS");
    if (option == to_string(1))
    {
        student stud1;
        students.push_back(stud1);
        readNewStudent (&students[j], j);
        j++;
        continue;
    }
    else if (option == to_string(2))
    {
        int num, flag, x = 0;
        cout << "Enter Student Number: ";
        cin >> num;
        flag = range_check(j, num);
        if (flag == 1)
            continue;
        printStudentData (&students[num - 1]);
        if ((x = ending_msg()))   continue;

    }
    else if (option == to_string(3))
    {
        int x = 0;
        system("CLS");
        j = read_file(students, j);
        if ((x = ending_msg()))   continue;
    }
    else if (option == to_string(4))
    {
        int x = 0;
        system("CLS");
        write_file(students, j);
        cout << "check a file called (write student.txt) created in the same directory as (main.cpp)\n";
        if ((x = ending_msg()))   continue;
    }
    else if (option == to_string(5))
    {
        int num, flag;
        cout << "Enter Student Number: ";
        cin >> num;
        flag = range_check(j, num);
        if (flag == 1)
            continue;
        cout << "Select Your Funding Type (0 for self funding, 1 for grant-funded): ";
        cin >> students[num - 1].studentPay.typeOfFunding;
        cout << "\nEnter A New Registration Number: ";
        cin >> students[num - 1].studentPay.accountRegis;
        cout << "\n";
        getPayementDetails(&students[num - 1]);
        continue;
    }
    else if (option == to_string(6))
    {
        int num, flag, x = 0;
        cout << "Enter Student Number: ";
        cin >> num;
        flag = range_check(j, num);
        if (flag == 1)
            continue;
        print_payment_details(&students[num - 1]);
        if ((x = ending_msg()))   continue;
    }
    else if (option == to_string(7))
    {
        int num, flag;
        cout << "Enter Student Number: ";
        cin >> num;
        flag = range_check(j, num);
        if (flag == 1)
            continue;
        readNewStudent (&students[num - 1], num);
    }
    else if (option == to_string(8))
    {
        int x = 0;
        string elec, comp, mech, prod, po, gpa1, gpa2, gpa3, gpa4;
        cout << "Sorting Based on Department: \n\n";
        comp.append("\tComputer\n");
        elec.append("\tElectrical Engineering\n");
        po.append("\tPower\n");
        prod.append("\tProduction\n");
        mech.append("\tMechanics\n");
        for (int i = 0; i < j; i++)
        {
            if (students[i].department == 0)
            {
                comp.append(students[i].firstName);
                comp.append(" ");
                comp.append(students[i].lastName);
                comp.append("\n");
            }
            else if (students[i].department == 1)
            {
                elec.append(students[i].firstName);
                elec.append(" ");
                elec.append(students[i].lastName);
                elec.append("\n");
            }
            else if (students[i].department == 2)
            {
                po.append(students[i].firstName);
                po.append(" ");
                po.append(students[i].lastName);
                po.append("\n");
            }
            else if (students[i].department == 3)
            {
                prod.append(students[i].firstName);
                prod.append(" ");
                prod.append(students[i].lastName);
                prod.append("\n");
            }
            else if (students[i].department == 4)
            {
                mech.append(students[i].firstName);
                mech.append(" ");
                mech.append(students[i].lastName);
                mech.append("\n");
            }
        }
        cout << comp << elec << po << prod << mech;
        cout << "\nSorting Based on GPA: \n";
        for (int i = 0; i < j; i++)
        {
            if (students[i].studGPA.currentSemster >= 0 && students[i].studGPA.currentSemster < 1)
            {
                gpa1.append((students[i].firstName));
                gpa1.append(" ");
                gpa1.append((students[i].lastName));
                gpa1.append("\t");
                gpa1.append(to_string(students[i].studGPA.currentSemster / 4));
                gpa1.append("\n");
            }
            else if (students[i].studGPA.currentSemster >= 1 && students[i].studGPA.currentSemster < 2)
            {
                gpa2.append((students[i].firstName));
                gpa2.append(" ");
                gpa2.append((students[i].lastName));
                gpa2.append("\t");
                gpa2.append(to_string(students[i].studGPA.currentSemster));
                gpa2.append("\n");
            }
            else if (students[i].studGPA.currentSemster >= 2 && students[i].studGPA.currentSemster < 3)
            {
                gpa3.append((students[i].firstName));
                gpa3.append(" ");
                gpa3.append((students[i].lastName));
                gpa3.append("\t");
                gpa3.append(to_string(students[i].studGPA.currentSemster));
                gpa3.append("\n");

            }
            else
            {
                gpa4.append((students[i].firstName));
                gpa4.append(" ");
                gpa4.append((students[i].lastName));
                gpa4.append("\t");
                gpa4.append(to_string(students[i].studGPA.currentSemster));
                gpa4.append("\n");
            }
        }
        cout << "\nStudent With GPA (0 ~ 1):\n" << gpa1 << "\n";
        cout << "\nStudent With GPA (1 ~ 2):\n" << gpa2 << "\n";
        cout << "\nStudent With GPA (2 ~ 3):\n" << gpa3 << "\n";
        cout << "\nStudent With GPA (3 ~ 4):\n" << gpa4 << "\n";

        if ((x = ending_msg()))   continue;

    }
    else if (option == to_string(9))
    {
        int num, flag;
        cout << "Enter Student Number: ";
        cin >> num;
        flag = range_check(j, num);
        if (flag == 1)
            continue;
        enter_courses_info (&students[num - 1]);
        system("CLS");
        continue;
    }
    else if (option == to_string(10))
    {

        int num, flag;
        cout << "Enter Student Number: ";
        cin >> num;
       flag = range_check(j, num);
        if (flag == 1)
            continue;
        set_GPA (&students[num - 1]);
        print_course_info(&students[num - 1]);
        continue;
    }
    else if (option == to_string(12))
    {
        int x = 0;
        system("CLS");
        cout << "University Registration System V 1.00\t Created by: Abdelrahman Ehab   Deghedy\n\n";
        cout << "If you find any bug, please contact me at:\n\n\tDeghedy2016@gmail.com      or      FB.com/AbdelrahmandDghedy\n";
        if ((x = ending_msg()))   continue;
    }
    }
    return 0;
}
