#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;


//Establishes our prices for the various costs to different locations.
const double OVER150 = 0.00;

const double TOUSALESSTHAN50 = 6.00;
const double TOUSA50TO100 = 9.00;
const double TOUSA100TO150 = 12.00;


const double TOCANLESSTHAN50 = 8.00;
const double TOCAN50TO100 = 12.00;
const double TOCAN100TO150 = 15.00;


const double TOAUSLESSTHAN50 = 10.00;
const double TOAUS50TO100 = 14.00;
const double TOAUS100TO150 = 17.00;

const double TOJAPLESSTHAN50 = 9.00;
const double TOJAP50TO100 = 13.00;
const double TOJAP100TO150 = 16.00;

//Establishes the ranges for the different price zones for later comparison
const double LOWESTPRICING = 50.00;
const double MIDTIERLOW = 50.01;
const double MIDTIERHIGH = 100.00;
const double HIGHTIERLOW = 100.01;
const double HIGHTIERHIGH = 150.00;

//The variable to represent the additional cost of a fragile item.
const double FRAGILEFEE = 2.00;

//Creates a string to handle our filename so users can edit it with ease to output to a different file
const string OUTFILENAME = "Order.txt";

int main()
{
    //Creates our local ofstream variable to be used with the functions.
    ofstream outFile;

    //Opens the output file
    outFile.open(OUTFILENAME);

    //Checks to see if the output file is open, and if not, sends an error to the user and closes program
    if (!outFile) {
        cout << "Error in opening the file:" << endl;
        outFile.close();
        return -1;
    }


    //Bank of local variables with zeroed out values to begin with
    string userPackage = "";
    string fragile = "";
    double orderTotal = 0.00;
    string destination = "";
    double shippingCost = 0.00;

    //Sets out precision for the console and output file along with always displaying two decimal points.
    cout << setprecision(2) << fixed;
    outFile << setprecision(2) << fixed;

    //Outputs the header for our program to the console and to our file
    cout << setfill('.') << setw(50) << "." << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setw(50) << "." << endl << endl;

    outFile << setfill('.') << setw(50) << "." << endl;
    outFile << "ITCS 2530 - Programming Assignment for week #3" << endl;
    outFile << setw(50) << "." << endl << endl;

    //Gives the user a prompt for their item input and then stores that data to our output file
    cout << "Please enter the item name (no spaces)" << right << setw(10) << ":";
    cin >> userPackage;
    outFile << "Please enter the item name (no spaces)" << right << setw(10) << ":" << userPackage;
    //sets the user inputed data to all caps
    transform(userPackage.begin(), userPackage.end(), userPackage.begin(), ::toupper);
    
    //Prompts the user for if fragile or not and outputs it to our file.
    cout << "Is the item fragile? (y=yes/n=no)" << right << setw(15) << ":";
    cin >> fragile;
    outFile << "\nIs the item fragile? (y=yes/n=no)" << right << setw(15) << ":" << fragile;
    //Converts fragile input to all caps to ensure easy comparison later on.
    transform(fragile.begin(), fragile.end(), fragile.begin(), ::toupper);

    //Throws an error statment and exits the program if incorrect data is entered.
    if (fragile != "Y" and fragile != "N") {
        cout << "\nInvalid entry, exiting" << endl;
        system("pause");
        return -1;
    }

    //Prompts the user to input data for their order total and throws an error if improper data was entered.
    cout << "Please enter your order total" << right << setw(19) << ":";
    if (cin >> orderTotal) {
        //Blank if statement as we do not want an output message at this point in the program, we simply are testing for if user inputed the incorrect type.
    }
    else {
        cout << "\nInvalid entry, exiting" << endl;
        system("pause");
        return 0;
    }
    //Writes the obtained data to our output file after verification
    outFile << "\nPlease enter your order total" << right << setw(19) << ":" << orderTotal;

    //Asks the user for their destination, and writes the prompt with their answer to the output file.
    cout << "Please enter destination. (usa/can/aus)" << right << setw(9) << ":";
    cin >> destination; 
    outFile << "\nPlease enter destination. (usa/can/aus)" << right << setw(9) << ":" << destination;
    //Converts the user input to all caps for easy comparison.
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

    //Ensures user inputed one of the proper locations, and if not, returns an error and closes the program.
    if (destination != "AUS" and destination != "CAN" and destination != "USA" and destination != "JAP") {
        cout << "\nInvalid entry, exiting" << endl;
        system("pause");
        return 0;
    }

    //Outputs the collected data for the user to see and writes it to the file with the uppercase changes made.
    cout << "\nYour item is" << setw(40) << "." << userPackage << endl;
    outFile << "\n\nYour item is" << setw(40) << "." << userPackage << endl;


    //Nested if statement used to figure out where it is being sent to and how much the order total was to calculate shipping cost.
    if (destination == "USA") {
        if (orderTotal < LOWESTPRICING) {
            shippingCost = TOUSALESSTHAN50;
        }
        else if (orderTotal <= MIDTIERHIGH and orderTotal >= MIDTIERLOW) {
            shippingCost = TOUSA50TO100;
        }
        else if (orderTotal <= HIGHTIERHIGH and orderTotal >= HIGHTIERLOW) {
            shippingCost = TOUSA100TO150;
        }
        else if (orderTotal > HIGHTIERHIGH) {
            shippingCost = OVER150;
        }
    }
    else if (destination == "CAN") {
        if (orderTotal < LOWESTPRICING) {
            shippingCost = TOCANLESSTHAN50;
        }
        else if (orderTotal <= MIDTIERHIGH and orderTotal >= MIDTIERLOW) {
            shippingCost = TOCAN50TO100;
        }
        else if (orderTotal <= HIGHTIERHIGH and orderTotal >= HIGHTIERLOW) {
            shippingCost = TOCAN100TO150;
        }
        else if (orderTotal > HIGHTIERHIGH) {
            shippingCost = OVER150;
        }
    }
    else if (destination == "AUS") {
        if (orderTotal < LOWESTPRICING) {
            shippingCost = TOAUSLESSTHAN50;
        }
        else if (orderTotal <= MIDTIERHIGH and orderTotal >= MIDTIERLOW) {
            shippingCost = TOAUS50TO100;
        }
        else if (orderTotal <= HIGHTIERHIGH and orderTotal >= HIGHTIERLOW) {
            shippingCost = TOAUS100TO150;
        }
        else if (orderTotal > HIGHTIERHIGH) {
            shippingCost = OVER150;
        }
    }
    else if (destination == "JAP") {
        if (orderTotal < LOWESTPRICING) {
            shippingCost = TOJAPLESSTHAN50;
        }
        else if (orderTotal <= MIDTIERHIGH and orderTotal >= MIDTIERLOW) {
            shippingCost = TOJAP50TO100;
        }
        else if (orderTotal <= HIGHTIERHIGH and orderTotal >= HIGHTIERLOW) {
            shippingCost = TOJAP100TO150;
        }
        else if (orderTotal > HIGHTIERHIGH) {
            shippingCost = OVER150;
        }
    }

    //Chest to see if the user said their package is fragile, if so adds $2 to the shipping cost value.
    if (fragile == "Y") {
        shippingCost += FRAGILEFEE;
    }

    //Outputs all the collected information to both console and the file, confirming for the user everything and calculating the total shipping cost.
    cout << "Your shipping cost is" << right << setw(32) << "$" << shippingCost << endl;
    outFile << "Your shipping cost is" << right << setw(32) << "$" << shippingCost << endl;
    cout << "You are shipping to" << right << setw(33) << "" << destination << endl;
    outFile << "You are shipping to" << right << setw(33) << "" << destination << endl;
    cout << "Your total shipping costs are" << right << setw(24) << "$" << shippingCost + orderTotal << endl << endl;
    outFile << "Your total shipping costs are" << right << setw(24) << "$" << shippingCost + orderTotal << endl << endl;

    //A thank you message to the user
    cout << setw(62) << setfill('-') << "Thank You!" << endl << endl;
    outFile << setw(62) << setfill('-') << "Thank You!" << endl << endl;

    //Closes our file and pauses so user gets to see console output instead of program terminating immediately
    outFile.close();
    system("pause");
}

