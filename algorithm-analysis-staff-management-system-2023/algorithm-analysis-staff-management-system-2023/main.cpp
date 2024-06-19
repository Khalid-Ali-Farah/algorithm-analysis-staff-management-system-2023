
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>  
#include <stdlib.h>

using namespace std;

struct StaffRecord {
public:
    StaffRecord(
        int id,
        string firstName,
        string lastName,
        int age,
        string phoneNumber,
        double salary
    ) {
        Id = id;
        FirstName = firstName;
        LastName = lastName;
        Age = age;
        PhoneNumber = phoneNumber;
        Salary = salary;
    }
    void display() {
        cout << "   Staff ID: " << Id << endl;
        cout << "   First Name: " << FirstName << endl;
        cout << "    Last Name: " << LastName << endl;
        cout << "          Age: " << Age << endl;
        cout << " Phone Number: " << PhoneNumber << endl;
        cout << "          Salary RM: " << Salary << endl;
        cout << endl;

    }

    int Id;
    string FirstName;
    string LastName;
    string PhoneNumber;
    int Age;
    double Salary;

};

void displayStaffs(vector<StaffRecord>& staffs) {

    for (auto staff : staffs) {
        staff.display();

    }

}
//bubble sort function to sorts the records in ascending order by ID

void  bubbleSort(vector<StaffRecord>& staffs) {

    system("cls");
    clock_t tStart = clock();
    int countingswap = 0;
    int i, j, temp = 0;
    // Loop through the list of elements
    for (int i = 0; i < staffs.size() - 1; i++) {
        // Flag variable to track if any swaps were made in the current iteration
        bool swapped = false;

        // Loop through the remaining unsorted elements
        for (int j = 0; j < staffs.size() - i - 1; j++) {
            // Compare the current element with the next element
            if (staffs[j].Id > staffs[j + 1].Id) {
                // Swap the two elements if the current element is larger
                std::swap(staffs[j], staffs[j + 1]);
                swapped = true;
                countingswap++;
            }
        }

        // If no swaps were made, the list is already sorted, so break out of the loop
        if (!swapped) {
            break;
        }
    }

    cout << "------------------------------------------------------------------" << endl;
    cout << "\tTOTAL NUMBER OF SWAP FOR BUBBLE SORT IS : " << countingswap << endl;
    printf("\tTime taken: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    cout << "------------------------------------------------------------------" << endl << endl;


}

// Selection sorts to sorts the records in ascending order by ID.
void selectionSort(vector<StaffRecord>& staffs)
{
    system("cls");
    clock_t tStart = clock();
    int countingswap = 0;
    for (int i = 0; i < staffs.size() - 1; i++)
    {
        // Find the index of the minimum element in the unsorted part of the array.
        int minIndex = i;
        for (int j = i + 1; j < staffs.size(); j++) {
            if (staffs[j].Id < staffs[minIndex].Id) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element in the unsorted part of the array.
        std::swap(staffs[i], staffs[minIndex]);
        countingswap++;

    }
    cout << "------------------------------------------------" << endl;
    cout << "\tTOTAL NUMBER OF SWAP FOR SELECTION SORT IS : " << countingswap << endl;
    printf("\tTime taken: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    cout << "------------------------------------------------" << endl << endl;


}

int BinarySearch(const std::vector<StaffRecord>& staffs, int id) {

    clock_t tStart = clock();

    int left = 0;
    int right = staffs.size() - 1;
    while (left <= right) {

        int mid = left + (right - left) / 2;
        if (staffs[mid].Id == id) {
            cout << "------------------------------------------------" << endl;
            printf("\tTime taken: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
            cout << "------------------------------------------------" << endl << endl;
            return mid;
        }
        else if (staffs[mid].Id < id) {
            left = mid + 1;
        }
        else {
            right = mid - 1;


        }



    }
    return -1;

}

void callBinarySearch(vector<StaffRecord>& staffs) {

    clock_t tStart = clock();
    int id;
    cout << "--------------- Binary Search -----------------------: " << endl;
    cout << "\n Please Enter Staff ID That You Want to Search: ";
    cin >> id;
    int index = BinarySearch(staffs, id);
    if (index >= 0) {
        cout << "------------------------------------------------: " << endl;
        cout << "Record with ID " << id << " Found at index " << index << endl;
        cout << "------------------------------------------------: " << endl;
    }
    else {
        cout << "------------------------------------------------: " << endl;
        cout << "Record with ID \t " << id << " Not found" << endl;
        cout << "------------------------------------------------: " << endl;
    }



}

int LinearSearch(const std::vector<StaffRecord>& staffs, int id) {
    clock_t tStart = clock();

    for (int i = 0; i < staffs.size(); i++) {

        if (staffs[i].Id == id) {

            cout << "------------------------------------------------" << endl;
            printf("\tTime taken: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
            cout << "------------------------------------------------" << endl << endl;
            return i;

        }

    }

    return -1;


}

void callLinearSearch(vector<StaffRecord>& staffs) {

    int id;
    cout << "----------------- Linear Search --------------------: " << endl;
    cout << "\n Please Enter Staff ID That You Want to Search: ";
    cin >> id;

    int index = LinearSearch(staffs, id);
    if (index >= 0) {
        cout << "------------------------------------------------: " << endl;
        std::cout << "Record with id " << id << " found at index " << index << std::endl;
        cout << "------------------------------------------------: " << endl;
    }
    else {
        cout << "------------------------------------------------: " << endl;
        cout << "Record with id " << id << " not found" << std::endl;
        cout << "------------------------------------------------: " << endl;
    }

}

void averageSalary(vector<StaffRecord>& staffs) {

    // Calculate the sum of the salaries
    int sum = 0;
    for (const StaffRecord& staffs : staffs) {
        sum += staffs.Salary;
    }

    // Calculate the average salary
    int num_staff = staffs.size();
    double average_salary = static_cast<double>(sum) / num_staff;
    cout << "------------------------------------------------" << endl << endl;
    cout << "   Average Salary For 100 Staff Is : " << average_salary << endl;
    cout << "------------------------------------------------" << endl << endl;
}

void SalaryType(vector<StaffRecord>& staffs)
{
    cout << "------------------------------------ " << endl << endl;
    int staffSalary;
    cout << "Enter Staff Salary : ";
    cin >> staffSalary;
    cout << "------------------------------------ " << endl << endl;


    // Use switch statement to handle different job 

    switch (staffSalary)
    {
    case 5000:
        cout << "\t\t Manager" << endl << endl;
        break;
    case 4000:
        cout << "\t\t Developer" << endl << endl;
        break;
    case 3000:
        cout << "\t\t Designer" << endl << endl;
        break;
    case 2000:
        cout << "\t\t Accountant" << endl << endl;
        break;
    default:
        std::cout << "Performing other duties\n";
    }

    cout << "------------------------------------ " << endl << endl;
}


void login() {

    cout << "\t\t\t Staff Management System" << endl;
    cout << "------------------------------------------------------------------" << endl << endl;
    cout << "\t\t BITP 2113_ Algorithm Analysis" << endl << endl;
    cout << "\t\t Dr. Intan Ermahani" << endl << endl << endl;


    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == "admin")
    {
        cout << "Login successful!" << endl;
    }
    else
    {
        cout << "Invalid username or password." << endl;
    }
    system("cls");
}
void display100Data(vector<StaffRecord>& staffs)
{

    char back;

choose:
    cout << "============================================================================" << endl;
    cout << "To Display 100 Staff Data ??" << endl << endl;
    cout << "============================================================================" << endl << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << " \t GO BACK? (Y/N)" << endl;
    cout << "------------------------------------------------------------------" << endl;


    cin >> back;
    if (back == 'Y' || back == 'y')
    {
        // Display 100  staff data 
        for (int i = 0; i < 100; i++) {





            cout << "   Staff ID: " << staffs[i].Id << endl;
            cout << "   First Name: " << staffs[i].FirstName << endl;
            cout << "    Last Name: " << staffs[i].LastName << endl;
            cout << "          Age: " << staffs[i].Age << endl;
            cout << " Phone Number: " << staffs[i].PhoneNumber << endl;
            cout << "          Salary RM: " << staffs[i].Salary << endl;
            cout << endl;

        }
    }
    else
    {
        goto choose;
    }




}
int main()
{
    system("Color 1B");


    //login();
    vector<StaffRecord> staffs;
    ifstream inputFile;
    inputFile.open("E:\staff-records.csv");
    string line = "";



    int line_count = 0;
    while (getline(inputFile, line)) {

        stringstream inputString(line);

        //StaffId, Last Name, FirstName, Age, Phone Number, Salary
        int staffId;
        string lastName;
        string firstName;
        int age;
        string phone;
        double salary;
        string tempString;

        getline(inputString, tempString, ',');
        staffId = atoi(tempString.c_str());
        getline(inputString, lastName, ',');
        getline(inputString, firstName, ',');
        getline(inputString, tempString, ',');
        age = atoi(tempString.c_str());
        getline(inputString, phone, ',');
        getline(inputString, tempString);
        salary = atof(tempString.c_str());

        StaffRecord Staff(staffId, lastName,
            firstName, age, phone, salary);
        staffs.push_back(Staff);
        line = "";



        //line_count++;

        //// Break if we have read 100 lines
        //if (line_count == 1000) {
        //    break;
        //}




    }
    inputFile.close();







    int input;
menu:
    cout << "\t\t\t Staff Management System" << endl;
    cout << "------------------------------------------------------------------" << endl << endl;
    cout << "\t\t 1 - To Display 100 Staff Data (CSV File)." << endl << endl;
    cout << "\t\t 2 - Sort The Data Using Bubble Sort." << endl << endl;
    cout << "\t\t 3 - Sort The Data Using Selection Sort." << endl << endl;
    cout << "\t\t 4 - Search The Data Using Binary Search." << endl << endl;
    cout << "\t\t 5 - Search The Data Using Linear Search." << endl << endl;
    cout << "\t\t 6 - To Calculate The Average Salary For 100 Staff." << endl << endl;
    cout << "\t\t 7 - Job Types ." << endl << endl;


    cout << "------------------------------------------------------------------" << endl;
    cout << " YOUR CHOICE : ";
    cin >> input;
    cout << endl << endl;



    switch (input) {
    case 1:


        display100Data(staffs);

        char back;

    choose:
        cout << "------------------------------------------------------------------" << endl;
        cout << " \t GO BACK? (Y/N)" << endl;
        cout << "------------------------------------------------------------------" << endl;


        cin >> back;
        if (back == 'Y' || back == 'y')
        {
            goto menu;
        }
        else
        {
            goto choose;
        }

        break;
    case 2:
        bubbleSort(staffs);


        displayStaffs(staffs);

        //To display sorted data 100

        display100Data(staffs);


        char back2;
    choose2:
        cout << " GO BACK? (Y/N)" << endl;
        cin >> back2;
        if (back2 == 'Y' || back2 == 'y')
        {


            goto menu;
        }
        else
        {
            goto choose2;
        }

        break;

    case 3:

        selectionSort(staffs);

        displayStaffs(staffs);

        //To display sorted data 100
        display100Data(staffs);


        char back3;
    choose3:
        cout << " GO BACK? (Y/N)" << endl;
        cin >> back3;
        if (back3 == 'Y' || back3 == 'y')
        {


            goto menu;
        }
        else
        {
            goto choose3;
        }

        break;


    case 4:

        selectionSort(staffs);

        displayStaffs(staffs);


        callBinarySearch(staffs);


        char back4;
    choose4:
        cout << " GO BACK? (Y/N)" << endl;
        cin >> back4;
        if (back4 == 'Y' || back4 == 'y')
        {


            goto menu;
        }
        else
        {
            goto choose4;
        }

        break;

    case 5:

        selectionSort(staffs);

        displayStaffs(staffs);





        callLinearSearch(staffs);

        char back5;

    choose5:

        cout << " GO BACK? (Y/N)" << endl;
        cin >> back5;
        if (back5 == 'Y' || back5 == 'y')
        {


            goto menu;
        }
        else
        {
            goto choose5;
        }

        break;

    case 6:


        displayStaffs(staffs);


        averageSalary(staffs);


        char back6;

    choose6:

        cout << " GO BACK? (Y/N)" << endl;
        cin >> back6;
        if (back6 == 'Y' || back6 == 'y')
        {


            goto menu;
        }
        else
        {
            goto choose6;
        }

        break;

    case 7:


        displayStaffs(staffs);

        SalaryType(staffs);

        char back7;

    choose7:

        cout << " GO BACK? (Y/N)" << endl;
        cin >> back7;
        if (back7 == 'Y' || back7 == 'y')
        {


            goto menu;
        }
        else
        {
            goto choose7;
        }

        break;

    default:

        cout << " Wrong Choice!! Please Enter Valid Number " << endl;
    }

    return 0;

}//end main 