/*
The code is not clean and i cba to clean it. however, i'm considering integrating this project into a web application with a cool gui using a framework later on and clean it. <3
  */
#include<iostream>
#include<string>
#include<bits.h>
#include<fstream>

using namespace std;

struct deta {
	int d, m, y;
};


struct user {
	string name;
	string phone_no, address, departurecity;
	deta departuredate;
	long id;
	int userntks;
	int tks[10];

}users[10] = { { "ismail", "01277393329", "nasr city", "suez", 1, 5, 2023, 2022170064, 0 }, { "eslam ahmed", "01201594195", "alex", "cairo", 14, 1, 2023, 2022170050, 0 } };
//int nuser = 2;
//int currentuser = -1;
struct tickets {
	int tno;
	long userid;
	int flightno;
	int nseats;
};
tickets tk[100];
int ntk = 0;

int i = 2; //user array index
struct end_flight
{
	char flight[50];
	int seats_booked;
	char clock_runed[50];
	int cost;
	deta time;

} endss[4] = { { "MOROCCO", 6, "4:30 AM", 300, { 6, 10, 2023 } }, { "UNITED STATES", 5, "6:10 AM", 250, { 8, 6, 2023 } }, { "TUNISIA", 4, "7:15 PM", 200, { 7, 12, 2023 } }, { "TOKYO", 3, "3:45 AM", 160, { 6, 6, 2023 } } };




struct adminss {

	string name;
	long long id;
}
admins[6] = { { "eslam khaled", 2022170066 }, { "ahmed hesham", 2022170046 }, { "amr tarek", 2022170290 }, { "seif samir", 2022170196 }, { "islam nabil", 2022170062 }, { "admin", 123 } };



struct flightinformation
{
	char flightname[50];
	int flightnumber;
	int seatsnumber;
	char clock[50];
	int cost;
	deta deta_flight;


};
flightinformation flights[10] = {
	{ "London", 1, 250, "3:30 PM", 50, { 1, 5, 2023 } },
	{ "Paris", 2, 200, "2:15 AM", 20, { 1, 6, 2023 } },
	{ "Dubai", 3, 300, "5:25 AM", 90, { 1, 7, 2023 } },
	{ "Mecca", 4, 400, "4:10 PM", 40, { 1, 8, 2023 } },
	{ "Berlin", 5, 500, "2:20 PM", 20, { 1, 9, 2023 } },
	{ "Ajax", 6, 200, "2:50 PM", 10, { 1, 10, 2023 } },
	{ "China", 7, 275, "7:20 PM", 45, { 1, 11, 2023 } }
};
int nflights = 7;

user s_user;
int login_id;

//varibles
// varibles








bool check_num(string num)
{
	for (int i = 0; i < num.length(); i++)
	{
		if (isdigit(num[i]) == false)
			return false;
	}
	return true;
}


int input_num()
{
	string num;
	cin >> num;
	while (!check_num(num))
	{
		cout << "\033[31m" << "Please enter a valid number: " << "\033[0m";
		cin >> num;
	}
	return stoi(num);
}

int sign;
int userORadmin() {
	cout << "Choose whether you're a user or an admin:\n 1: User \n 2: Admin " << endl;
	sign = input_num();


	return sign;
	system("cls");
}


bool contains_number(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			return false;
			break;
		}
	}
	return true;
}
int add_user = 0;

void Userdata() { // SIGN UP

	cout << "Enter your full name: " << endl;
	cin.ignore();
	getline(cin, users[i].name);
	while (true) {
		if (contains_number(users[i].name)) {
			break;
		}
		else {
			cout << "\033[31m" << "Invalid name!\n" << "\033[0m";
			cout << "Please enter a valid full name: \n";
			getline(cin, users[i].name);
		}
	}

	cout << "Enter your ID: " << endl;
	users[i].id = input_num();

	cout << "Enter your address: " << endl;
	cin.ignore();
	getline(cin, users[i].address);

	cout << "Enter your phone number: " << endl;
	cin >> users[i].phone_no;
	while (true) {
		if (users[i].phone_no[0] == '0' && users[i].phone_no[1] == '1' && users[i].phone_no.length() == 11)
			break;
		else {
			cout << "\033[31m" << "Invalid phone number!\n" << "\033[0m" << "Please enter a valid phone number (e.g. '01277393329'): \n";
			cin >> users[i].phone_no;
		}
	}

	cout << "What is your departure city?" << endl;
	cin.ignore();
	getline(cin, users[i].departurecity);

	cout << "When is your departure date?\n";
	cout << "Day: ";  users[i].departuredate.d = input_num(); ;
	cout << "Month: ";  users[i].departuredate.m = input_num();
	cout << "Year: ";  users[i].departuredate.y = input_num();
	while (true) {
		if (users[i].departuredate.y < 2023 || users[i].departuredate.y>2030) {
			cout << "\033[31m" << "Please enter a valid year: " << "\033[0m"; cin >> users[i].departuredate.y; cout << "\n";
		}
		else break;
	}

	for (int q = 0; q < 10; ++q) {
		flights[q].deta_flight.d = users[i].departuredate.d;
		flights[q].deta_flight.m = users[i].departuredate.m;
		flights[q].deta_flight.y = users[i].departuredate.y;
	}
	login_id = i;
	i++;
}



int j = 0, flight_num, seats, totalCost;
int k = 0;


void login_user()
{
	cout << "Enter your username: " << endl;
	cin.ignore();
	getline(cin, s_user.name);
	cout << "Enter your ID: " << endl;
	s_user.id = input_num();
	bool found = false;
	while (!found) {
		for (int j = 0; j < i; j++)
		{
			if (s_user.id == users[j].id && !s_user.name.compare(users[j].name))
			{
				found = true;
				login_id = j;
			}

		}
		if (!found) {
			cout << "\n" << s_user.id << " -- " << s_user.name << "\n";
			cout << "\033[31m" << "Invalid username and ID\n" << "\033[0m" << "Please enter your valid username and ID: " << endl;
			cin.ignore();
			getline(cin, s_user.name);
			s_user.id = input_num();
		}
	}

}

int counter;

void flightdata() {
	cout << "Flight number \t" << "Flight Name" << "\t" << "Flight Number" << "\t" << "Available Seats" << "\t" << "Flight Time\t" << "Cost\t\t" << "Flight Date" << endl;

	for (int l = 0; l < nflights; ++l) {
		if (flights[l].flightnumber == 0)
			continue;

		cout << l + 1 << "\t\t" << flights[l].flightname << "\t\t" << flights[l].flightnumber << "\t\t" << flights[l].seatsnumber << "\t\t" << flights[l].clock << "\t\t" << flights[l].cost << "$\t\t" << flights[l].deta_flight.d << "/" << flights[l].deta_flight.m << "/" << flights[l].deta_flight.y << "\n\n";
	}

	cout << "Please enter the flight number: ";

	do {
		flight_num = input_num();

		/*if (flight_num < 1 || flight_num > 7 + counter) {
		cout << "Invalid number. Please choose another number: ";
		flight_num = 10;
		}*/
		if (flight_num < 1 || flight_num > nflights) {
			cout << "\033[31m" << "Invalid number!" << "\033[0m\n" << "Please choose another number: ";
			flight_num = -1;
		}
	} while (flight_num == -1);

	//for (int p = 0; p < 10; ++p) {
	//	if (flight_num == flights[p].flightnumber) {
	flight_num -= 1;
	cout << "You have chosen: " << flights[flight_num].flightname << "\n" << "How many seats do you wish to book? \n";

	do {
		seats = input_num();

		if (seats <= flights[flight_num].seatsnumber) {
			flights[flight_num].seatsnumber -= seats;
			totalCost += seats * flights[flight_num].cost;
			break;
		}
		else {
			cout << "\033[31m" << "Only " << flights[flight_num].seatsnumber << " seats are available, please re-enter the number of seats: " << "\033[0m" << endl;
			seats = -1;
		}
	} while (seats == -1);
	//break;

	//}
	//}
	//nflights++;
}




void showTickets() {

	for (int l = 0; l < users[login_id].userntks; l++) {
		int tik_ind = users[login_id].tks[l];
		cout << "\n" << l + 1 << " " << flights[tk[tik_ind].flightno].flightname << "  seats: " << tk[tik_ind].nseats << "\n";
	}
}


void cancel() {
	cout << "\n" << "Choose what to cancel:\n";
	showTickets();
	int c;
	c = input_num();
	//check c
	flights[tk[users[login_id].tks[c - 1]].flightno].seatsnumber += tk[users[login_id].tks[c - 1]].nseats;
	for (int k = c - 1; k < users[login_id].userntks; k++) {
		users[login_id].tks[k] = users[login_id].tks[k + 1];
	}
	users[login_id].userntks--;
}
void update() {
	cout << "\n" << "Choose what to update : \n";
	showTickets();
	int c;
	//check c
	c = input_num();
	flights[tk[users[login_id].tks[c - 1]].flightno].seatsnumber += tk[users[login_id].tks[c - 1]].nseats;
	cout << "What is the new number of seats:? \n";
	int ns;


	do {
		ns = input_num();

		if (ns <= flights[tk[users[login_id].tks[c - 1]].flightno].seatsnumber) {
			flights[flight_num].seatsnumber -= ns;
			//totalCost += seats * flights[flight_num].cost;
			tk[users[login_id].tks[c - 1]].nseats = ns;
			break;
		}
		else {
			cout << "\033[31m" << "Only " << flights[tk[users[login_id].tks[c - 1]].flightno].seatsnumber << " seats are available, please re - enter the number of seats : " << "\033[0m" << endl;
			ns = -1;
		}
	} while (ns == -1);


}

void ticket() {
	/*

	cout << "\t\t* YOUR TICKET **" << endl;
	cout << "Name: " << users[i].name << endl;
	cout << "ID: " << users[i].id << endl;
	cout << "Address: " << users[i].address << endl;
	cout << "Phone Number: " << users[i].phone_no << endl;
	cout << "Departure City: " << users[i].departurecity << endl;
	cout << "Departure Date: " << users[i].departuredate.d << "/" << users[i].departuredate.m << "/" << users[i].departuredate.y << endl;
	cout << "Destination City: " << flights[flight_num - 1].flightname << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Total Cost: " << totalCost << "$" << endl;
	*/
	cout << "\t\t** YOUR TICKET **" << endl;
	cout << "Name: " << users[login_id].name << endl;
	cout << "ID: " << users[login_id].id << endl;
	cout << "Address: " << users[login_id].address << endl;
	cout << "Phone Number: " << users[login_id].phone_no << endl;
	cout << "Departure City: " << users[login_id].departurecity << endl;

	cout << "Destination City: " << flights[flight_num].flightname << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Total Cost: " << totalCost << "$" << endl;
	tickets t;
	t.flightno = flight_num;
	t.tno = ntk;
	t.userid = login_id;
	t.nseats = seats;
	users[login_id].tks[users[login_id].userntks++] = ntk;
	tk[ntk++] = t;


}




void cancelation()
{
	int answer;

	cout << "If you want to \n 1: confirm \n 2: cancel  ";
	answer = input_num();
	cout << endl;
	switch (answer) {
	case 2:

		totalCost = 0;
		for (int a = 0; a < 11; a++) {
			if (flight_num == flights[a].flightnumber) {
				flights[a].seatsnumber += seats;
			}
		}


		char rebook;
		cout << "\033[32m" << "Your ticket have been canceled!" << "\033[0m" << endl;
		for (;;) {

			cout << "Do you want to book another ticket? (y/n)\n";

			cin >> rebook;
			if (rebook == 'y' || rebook == 'Y') {
				flightdata();
				ticket();
				return cancelation();
			}
			else
				break;
		}

	case 1:

		cout << "\033[32m" << "Your ticket has been confirmed \n" << "\033[0m";
		cout << "\033[35m" << "HAVE A SAFE FLIGHT! ENJOY!\n\n" << "\033[0m";
		cout << "__";
		char rrebook;
		
		for (;;) {

			cout << "Do you want to book another ticket? (y/n)\n";

			cin >> rrebook;
			if (rrebook == 'y' || rrebook == 'Y') {
				flightdata();
				ticket();
				return cancelation();
			}
			else
				break;
		}

		break;
	}


}




string logg;
long long id_log;


void admin() {
	bool logged_in = false;

	do {
		if (sign == 2) {
			cout << "Enter your username: ";
			cin.ignore();
			getline(cin, logg);

			cout << "Enter your ID: ";
			id_log = input_num();

			for (int i = 0; i < 6; i++) {
				if (logg == admins[i].name && id_log == admins[i].id) {
					logged_in = true;
					cout << "\t\tWelcome, " << admins[i].name << "!" << endl;
					break;
				}
			}

			if (!logged_in) {
				cout << "\033[31m" << "Wrong username or ID!\n" << "Please try again." << "\033[0m" << endl;
			}
		}
	} while (!logged_in);
}


int option_admin;


char again_add;
void add_flights() {
	do {
		cout << "Enter flight data:\n";
		cout << "Enter flight name: ";
		cin >> flights[nflights].flightname;

		cout << "Enter flight number: ";
		flights[nflights].flightnumber = 8 + counter;

		cout << "Enter number of seats: ";
		flights[nflights].seatsnumber = input_num();

		cout << "Enter flight time: ";
		cin >> flights[nflights].clock;

		cout << "Enter the price of a ticket: ";
		flights[nflights].cost = input_num();

		cout << "Enter flight date:\n";
		cout << "Enter flight day: ";
		flights[nflights].deta_flight.d = input_num();

		cout << "Enter flight month: ";
		flights[nflights].deta_flight.m = input_num();

		cout << "Enter flight year: ";
		flights[nflights].deta_flight.y = input_num();

		nflights++;

		cout << "Add another flight? (y/n): ";
		cin >> again_add;
		
	} while (again_add == 'y' || again_add == 'Y');
}


int   delet;

void delete_flight() {
	bool deleted = false;
	do {
		cout << "Flight name\tFlight number\tFlight date\tSeats available\tFlight time\tCost\n";
		for (int l = 0; l < 10; ++l) {
			if (flights[l].flightnumber == 0)
				continue;
			cout << flights[l].flightname << "\t\t" << flights[l].flightnumber << "\t\t10-2-2005\t" << flights[l].seatsnumber << "\t\t" << flights[l].clock << "\t" << flights[l].cost << "$\n\n";
		}

		cout << "Enter the flight number to delete, or 0 to exit: ";
		delet = input_num();
		if (delet != 0) {
			for (int i = 0; i < 10; ++i) {
				if (delet == flights[i].flightnumber) {
					cout << "\033[32m" << "\nDeleted\n" << "\033[0m";

							for (int u = 0; u < ntk; u++){
								if (tk[u].flightno == i){
									user ss = users[tk[u].userid];
									for (int y = 0; y < ss.userntks; y++){
										if (ss.tks[y] == u){

											for (int h = y; h < ss.userntks; h++){
												users[tk[u].userid].tks[h] = ss.tks[h + 1];
											}
											users[tk[u].userid].userntks--;
											break;
										}
									}
								}
							}


					flights[i] = {};
					deleted = true;
					break;
				}
			}
		}

		//cout << "Enter any number to continue deleting, or enter 0 to exit: ";
		//cin >> delet;
		if (deleted)
			break;

	} while (delet != 0);
}


void showFlights() {
	cout << "Flight name\tFlight number\tFlight date\tSeats available\tFlight time\tCost\n";
	for (int l = 0; l < nflights; ++l) {
		if (flights[l].flightnumber == 0)
			continue;
		cout << flights[l].flightname << "\t\t" << flights[l].flightnumber << "\t\t10-2-2005\t" << flights[l].seatsnumber << "\t\t" << flights[l].clock << "\t" << flights[l].cost << "$\n\n";
	}
}

int edit_fl, edit_num;
int q;
bool edit_check = 0;


void edit_flights() {
	do {
		cout << "Flight name" << "\t" << "Flight number" << "\t" << "Seats available" << "\t" << "Flight time\t" << "Cost\t" << "Flight date" << endl;
		for (int l = 0; l < 10; ++l) {
			if (flights[l].flightnumber == 0)
				continue;
			cout << flights[l].flightname << "\t" << "\t" << flights[l].flightnumber << "\t" "\t" << flights[l].seatsnumber << "\t\t  " << flights[l].clock << "\t" << flights[l].cost << "$" << "\t\t" << flights[l].deta_flight.d << "/" << flights[l].deta_flight.m << "/" << flights[l].deta_flight.y << "\n\n";
		}

		cout << "Enter flight number to edit\n";
		edit_num = input_num();

		for (int t = 0; t < nflights; ++t) {

			if (edit_num == flights[t].flightnumber && edit_num >= 1) {
				q = t;
				cout << "You chose: " << flights[t].flightname << endl;
				edit_check = 1;
				break;
			}
			else
				continue;
		}

		if (edit_check == 1) {
			for (;;) {
				cout << "\n 1: To edit flight's name:\n 2: Flight's seats:\n 3: Flight's time:\n 4: Flight's cost:\n 5: Flight's date:\n\n 0: To exit\n ";
				cout << "Enter what you want to edit: \n";
				edit_fl = input_num();

				switch (edit_fl) {
				case 1:
					cout << "Enter updated name: \n";
					cin >> flights[q].flightname;
					break;
				case 2:
					cout << "Enter updated seats number: \n";
					flights[q].seatsnumber = input_num();
					break;
				case 3:
					cout << "Enter updated time: \n";
					cin >> flights[q].clock;
					break;
				case 4:
					cout << "Enter updated cost: \n";
					cin >> flights[q].cost;
					break;
				case 5:
					cout << "Enter updated date: \n";
					flights[q].deta_flight.d = input_num();
					flights[q].deta_flight.m = input_num();
					flights[q].deta_flight.y = input_num();
					break;
				default:
					edit_check = 0;
					break;
				}

				if (edit_check == 0)
					break;
			}

		}
		else
			cout << "\033[31m" << "\a\nInvalid selection\n" << "\033[0m";
	} while (edit_fl != 0);
}





void option() {
	cout << "------------\n";
	cout << "1. Add Flight\n";
	cout << "2. Delete Flight\n";
	cout << "3. Edit Flight\n";
	cout << "4. Show Flights\n";
	cout << "0. Exit\n";
	cin >> option_admin;
	switch (option_admin) {
	case 1:
		add_flights();
		break;
	case 2:
		delete_flight();
		break;
	case 3:
		edit_flights();
		break;
	case 4:
		showFlights();
		break;
	case 0:
		break;
	default:
		cout << "Invalid option\n";
		break;
	}

	//userORadmin();
}


void prev_reservation()
{
	/*if (s_user.name == users[i - 2].name && s_user.id == users[i - 2].id)
	{
	cout << "\n";
	cout << "Flight Name\tSeats Booked\tFlight Time\tTicket Cost\tFlight Date\n";
	cout << "--------------------------------------------------------------\n";
	cout << "\t" << endss[0].flight << "\t\t" << endss[0].seats_booked << "\t\t" << endss[0].clock_runed << "\t\t" << endss[0].cost << "$\t\t" << endss[0].time.d << "/" << endss[0].time.m << "/" << endss[0].time.y << "\n";
	cout << "\t" << endss[1].flight << "\t\t" << endss[1].seats_booked << "\t\t" << endss[1].clock_runed << "\t\t" << endss[1].cost << "$\t\t" << endss[1].time.d << "/" << endss[1].time.m << "/" << endss[1].time.y << "\n";
	}
	else
	{
	cout << "\n";
	cout << "Flight Name\tSeats Booked\tFlight Time\tTicket Cost\tFlight Date\n";
	cout << "--------------------------------------------------------------\n";
	cout << endss[2].flight << "\t\t" << endss[2].seats_booked << "\t\t" << endss[2].clock_runed << "\t\t" << endss[2].cost << "$\t\t" << endss[2].time.d << "/" << endss[2].time.m << "/" << endss[2].time.y << "\n";
	cout << endss[3].flight << "\t\t" << endss[3].seats_booked << "\t\t" << endss[3].clock_runed << "\t\t" << endss[3].cost << "$\t\t" << endss[3].time.d << "/" << endss[3].time.m << "/" << endss[3].time.y << "\n";
	}*/
	for (int k = 0; k < users[login_id].userntks; k++) {
		int n = users[login_id].tks[k];
		cout << "Ticket no: " << tk[n].tno << " flight: " << tk[n].flightno << " to " << flights[tk[n].flightno].flightname << "\n";
	}
}



void all()
{

	flightdata();
	ticket();
	cancelation();
}


void drawHeader() {
	cout << "\033[36m";
	cout << "\t\t" << "   ____________\n";
	cout << "\t\t" << " /\\                                            \\ \n";
	cout << "\t\t" << "/::\\               Airline Reservation System  \\\n";
	cout << "\t\t" << "\\:::\\___________\\\n";
	cout << "\t\t" << " \\:::/                                           \\\n";
	cout << "\t\t" << "  \\/                                             \\/\n\n";
	cout << "\033[0m";
}
int new_book;
void readfile(){
	char s;

	ifstream ins;
	ins.open("flights.txt");
	if (ins.is_open())
	{
		//  string line;

		ins >> ntk;



		for (int i = 0; i < ntk; i++){
			ins >> tk[i].tno>> s >> tk[i].flightno>> s >> tk[i].userid >> s >> tk[i].nseats;
			users[tk[i].userid].tks[users[tk[i].userid].userntks++] = tk[i].tno;
			flights[tk[i].flightno].seatsnumber -= tk[i].nseats;
		}
	}

}


void writefile(){
	ofstream outs;
	outs.open("flights.txt");
	outs <<  ntk << "\n";

	for (int i = 0; i < ntk; i++){
		outs << tk[i].tno << "," << tk[i].flightno<< "," << tk[i].userid << "," << tk[i].nseats << "\n";
	}

}


int main() {
	readfile();
	char ans;
	bool ay = false;

	do {
		drawHeader();
		userORadmin();

		if (sign == 2) {
			admin();
			option();
		}

		if (sign == 1) {
			int choi;
			cout << "Enter '1' to sign in or '2' to register new user: ";
			choi = input_num();

			if (choi == 2) {
				Userdata();
				all();
			}
			else if (choi == 1) {
				login_user();
				cout << "Choose:\n\t1: Book flight\n\t2: Previous reservation\n\t3: Cancel a reservation\n\t4: Update a previous reservation\n";
				int a;
				a = input_num();
				if (a == 1) {
					all();
				}
				if (a == 2) {
					prev_reservation();
					cout << endl << "_";
					cout << "1: to book new flight\n";
					cout << "2: to Exit\n";
					new_book = input_num();
					switch (new_book)
					{
					case 1:
						all();
						break;
					case 2:
						break;
					default:
						break;
					}

				}
				if (a == 3) {
					cancel();
				}
				if (a == 4) {
					update();
				}
			}
		}


		cout << "Do you want to return to the main menu? If yes press 'y', else press 'n': ";
		cin >> ans;

		if (ans == 'y' || ans == 'Y') {
			totalCost = 0;
			i++;
		}
	} while (ans == 'y' || ans == 'Y');
	writefile();
	system("pause");
	return 0;
}
