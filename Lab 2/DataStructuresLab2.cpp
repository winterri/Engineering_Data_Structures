#include "DataStructuresLab2.h"

using namespace std;

int main() {

	int testFunction;
	Meeting testMeeting;
	bool exit = true;
	char again;
	int durationValue;
	string testMeetingTime;
	string testMeetingDate;
	string additionalPerson;
	char addPerson;
	bool anotherPerson = true;
	string testSubject;

	while (exit == true) {
		cout << "Which function would you like to test?" << endl;
		cout << "1) setDuration/getDuration" << endl;
		cout << "2) setMeetingTime/getMeetingTime" << endl;
		cout << "3) setMeetingDate/getMeetingDate" << endl;
		cout << "4) addPerson/printPeople" << endl;
		cout << "5) reminder" << endl;
		cout << "6) exit" << endl;
		cout << "7) Check current date and time" << endl;
		cin >> testFunction;
		cout << endl;

		switch (testFunction) {
		case 1:
			cout << "What would you like to set the duration to be (in minutes): ";
			cin >> durationValue; // User will input what they want to set the duration to be
			cout << endl;
			testMeeting.setDuration(durationValue); // Tests the setDuration function of the Meeting class
			cout << "The meeting duration is set to be " << testMeeting.getDuration() << " minutes long." << endl; // Tests the getDuration function of the Meeting class
			cout << "Would you like to test again (y/n)?" << endl;
			cin >> again; // User will input 'y' or 'n' based on whether or not they would like to test another function
			cout << endl;
			if ((again == 'n') || (again == 'N')) {
				exit = false; // If the user selects 'n' for "no", then the exit variable will be set to false and the whole while loop will exit
			}
			else if ((again != 'n') && (again != 'N') && (again != 'y') && (again != 'Y')) {
				cout << "Please input only 'y' for yes or 'n' for no: ";
				cin >> again;
				cout << endl;
			}
			break;
		case 2:
			cout << "What would you like to set the meeting time to be (HH:MM:SS): ";
			cin >> testMeetingTime;
			cout << endl;
			cout << "What would you like to set the meeting date to be (MM/DD/YYYY): ";
			cin >> testMeetingDate;
			cout << endl;
			testMeeting.setMeetingTime(testMeetingTime, testMeetingDate);
			cout << "The meeting time is set to be (HH:MM:SS): " << testMeeting.getMeetingTime() << endl;
			cout << "Would you like to test again (y/n)?" << endl;
			cin >> again; // User will input 'y' or 'n' based on whether or not they would like to test another function
			cout << endl;
			if ((again == 'n') || (again == 'N')) {
				exit = false; // If the user selects 'n' for "no", then the exit variable will be set to false and the whole while loop will exit
			}
			else if ((again != 'n') && (again != 'N') && (again != 'y') && (again != 'Y')) {
				cout << "Please input only 'y' for yes or 'n' for no: ";
				cin >> again;
				cout << endl;
			}
			break;
		case 3:
			cout << "What would you like to set the meeting date to be (MM/DD/YYYY): ";
			cin >> testMeetingDate;
			cout << endl;
			testMeeting.setMeetingDate(testMeetingDate);
			cout << "The meeting date is set to be (MM/DD/YYYY): " << testMeeting.getMeetingDate() << endl;
			cout << "Would you like to test again (y/n)?" << endl;
			cin >> again; // User will input 'y' or 'n' based on whether or not they would like to test another function
			cout << endl;
			if ((again == 'n') || (again == 'N')) {
				exit = false; // If the user selects 'n' for "no", then the exit variable will be set to false and the whole while loop will exit
			}
			else if ((again != 'n') && (again != 'N') && (again != 'y') && (again != 'Y')) {
				cout << "Please input only 'y' for yes or 'n' for no: ";
				cin >> again;
				cout << endl;
			}
			break;
		case 4:
			anotherPerson = true;
			while (anotherPerson == true) {
				cout << "What is the name of the individual you would like to add to the list of people invited to the meeting: ";
				cin >> additionalPerson;
				cout << endl;
				testMeeting.addPerson(additionalPerson);
				cout << "Would you like to add another person to the list of people invited (y/n): ";
				cin >> addPerson;
				cout << endl;
				if (addPerson == 'n') {
					anotherPerson = false;
				}
			}
			cout << "The list of people invited to the meeting is: " << endl;
			testMeeting.printPeople();
			cout << "Would you like to test again (y/n)?" << endl;
			cin >> again; // User will input 'y' or 'n' based on whether or not they would like to test another function
			cout << endl;
			if ((again == 'n') || (again == 'N'))) {
				exit = false; // If the user selects 'n' for "no", then the exit variable will be set to false and the whole while loop will exit
			}
			else if ((again != 'n') && (again != 'N') && (again != 'y') && (again != 'Y')) {
				cout << "Please input only 'y' for yes or 'n' for no: ";
				cin >> again;
				cout << endl;
			}
			break;
		case 5:
			cout << "What would you like to set the meeting time to be (HH:MM:SS): ";
			cin >> testMeetingTime;
			cout << endl;
			cout << "What would you like to set the meeting date to be (MM/DD/YYYY): ";
			cin >> testMeetingDate;
			cout << endl;
			cout << "What would you like the meeting subject to be: ";
			cin >> testSubject;
			cout << endl;
			testMeeting.setMeetingDate(testMeetingDate);
			testMeeting.setMeetingTime(testMeetingTime, testMeetingDate);
			testMeeting.subject = testSubject;
			testMeeting.reminder();
			cout << "Would you like to test again (y/n)?" << endl;
			cin >> again; // User will input 'y' or 'n' based on whether or not they would like to test another function
			cout << endl;
			if ((again == 'n') || (again == 'N')) {
				exit = false; // If the user selects 'n' for "no", then the exit variable will be set to false and the whole while loop will exit
			}
			else if ((again != 'n') && (again != 'N') && (again != 'y') && (again != 'Y')) {
				cout << "Please input only 'y' for yes or 'n' for no: ";
				cin >> again;
				cout << endl;
			}
			break;
		case 6:
			exit = false;
			break;
		case 7:
			testMeeting.setCurrentDate();
			testMeeting.setCurrentTime();
			cout << "Current Date: " << testMeeting.getCurrentDate();
			cout << "Current Time: " << testMeeting.getCurrentTime();
			break;
		default:
			cout << "Invalid choice.  Please choose again." << endl;
			break;
		}
	}

	return 0;
}