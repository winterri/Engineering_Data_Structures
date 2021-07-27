#include <string> // Included for string functionality
#include <ctime> // Included for time functionality
#include <iostream> // Included for displaying functionality


using namespace std;

#ifndef MEETING_CLASS //Include guards
#define MEETING_CLASS

class Meeting {
private:
	int duration; // Length of meeting (minutes)
	string* people[20]; // Array of pointers pointing at different strings representing the different individuals invited to the meeting, initialized to all null pointers (no invitees)
	string meetingTime; // Meeting Time
	string meetingDate; // Meeting Date
	string currentDate; // Current Date
	string currentTime; // Current Time
public:
	string subject; // Subject of meeting
	string organizer; // Organizer of meeting
	void setCurrentTime() { // Function for setting the current time
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		int hour = newtime.tm_hour;
		int min = newtime.tm_min;
		int sec = newtime.tm_sec;
		string h = to_string(hour);
		string m = to_string(min);
		string s = to_string(sec);
		if (hour < 10) {
			h = "0" + h;
		}
		if (min < 10) {
			m = "0" + m;
		}
		if (sec < 10) {
			s = "0" + s;
		}
		currentTime = h + ":" + m + ":" + s;
	};
	void setCurrentDate() { // Function for setting the current date
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		int year = newtime.tm_year + 1900; // tm_year gives the year since 1900
		int month = newtime.tm_mon + 1; // tm_mon goes from 0 to 11, so we have to add one to account for the shift in indexing
		int day = newtime.tm_mday;
		string y = to_string(year);
		string mon = to_string(month);
		string d = to_string(day);
		if (month < 10) {
			mon = "0" + mon;
		}
		if (day < 10) {
			d = "0" + d;
		}
		currentDate = mon + "/" + d + "/" + y;
	};
	string getCurrentTime() {
		return currentTime;
	}
	string getCurrentDate() {
		return currentDate;
	}
	Meeting() { // Default constructor that sets meeting time and date to the current time and date values
		setCurrentTime();
		setCurrentDate();
		duration = 0;
		meetingTime = currentTime;
		meetingDate = currentDate;
		for (int i = 0; i <= 19; i++) {
			string* individual = new string("x");
			people[i] = individual;
		}

	};
	Meeting(string desiredTime, string desiredDate) { // Non-default constructor that sets the meeting time and date to the parameters passed into the constructor
		duration = 0;
		meetingTime = desiredTime;
		meetingDate = desiredDate;
		for (int i = 0; i <= 19; i++) {
			string* individual = new string("x");
			people[i] = individual;
		}
	};
	~Meeting() { // Destructor
		for (int i = 0; i <= 19; i++) {
			delete people[i];
		}
	};
	int getDuration() { // Getter for duration
		return duration;
	};
	void setDuration(int durationValue) { // Setter for duration
		if (durationValue >= 0) { // Data validation: checks to make sure the value you want to set duration equal to is greater than or equal to zero
			duration = durationValue;
		}
	};
	string getMeetingTime() { // Getter for meeting time
		return meetingTime;
	};
	void setMeetingTime(string desiredMeetingTime, string desiredMeetingDate) { // Setter for meeting time
		setCurrentTime();
		setCurrentDate();
		if (desiredMeetingDate > currentDate) {
			meetingTime = desiredMeetingTime;
		}
		else if ((desiredMeetingDate == currentDate) && (desiredMeetingTime > currentTime)) {
			meetingTime = desiredMeetingTime;
		}
	};
	string getMeetingDate() { // Getter for meeting date
		return meetingDate;
	};
	void setMeetingDate(string desiredMeetingDate) { // Setter for meeting date
		setCurrentDate();
		if (desiredMeetingDate >= currentDate) {
			meetingDate = desiredMeetingDate;
		}
	};
	void addPerson(string personName) { // Function for adding person to the array of people invited to the meeting
		int i = 0;
		while (*people[i] != "x") { // Will find the index value where the new person needs to be added
			if (i < 19) {
				i = i + 1;
			}
			else {
				break;
			}
		}
		if (i <= 19) {
			*people[i] = personName;
		}
	};
	void printPeople() { // Function for displaying all of the different individuals invited to the meeting
		int i = 0;
		while (*people[i] != "x") {
			cout << *people[i] << endl;
			i = i + 1;
		}
	};
	void reminder() {
		cout << "Date: " << meetingDate << endl;
		cout << "Time: " << meetingTime << endl;
		cout << "Subject: " << subject << endl;
	};
};

class VideoMeeting : public Meeting {
private:
public:
	string platform;
	string link;
	VideoMeeting() {

	};
	VideoMeeting(string desiredTime, string desiredDate, string desiredPlatform) {
		Meeting(desiredTime, desiredDate);
		platform = desiredPlatform;
	};
	void reminder() {
		cout << "Date: " << getMeetingDate() << endl;
		cout << "Time: " << getMeetingTime() << endl;
		cout << "Subject: " << subject << endl;
		cout << "Link: " << link << endl;
	}
};

#endif