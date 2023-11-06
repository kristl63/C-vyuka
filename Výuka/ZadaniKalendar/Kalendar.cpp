#include <iostream>

//using namespace std;

struct Time { 

int minute; 

int hour; 

int day; 

int month; 

int year; 

 

Time(); 

Time(std::string time); 

bool operator < (const Time& obj); 

bool operator > (const Time& obj); 

bool operator == (const Time& obj); 

bool operator != (const Time& obj); 

 

friend std::ostream& operator << (std::ostream& out, const Time& obj); 

}; 

class Event 

{ 

private: 

std::string name; 

Time start_time; 

Time end_time; 

std::string place; 

std::string description; 

 

public: 

Event(std::string event); 

Event(std::string name, std::string start_time, std::string end_time, std::string place, std::string description); 

bool operator < (const Event& obj) const; 

bool operator > (const Event& obj) const; 

bool operator == (const Event& obj) const; 

bool operator != (const Event& obj) const; 

 

friend std::ostream& operator << (std::ostream& out, const Event& obj); 

}; 

class Calendar 

{

private: 

std::string name; 

std::string path; 

std::list<Event> events; 

 

public: 

Calendar(std::string name); 

Calendar(std::string name, std::string path); 

void addEvent(Event event); 

Calendar findEvent(std::string name); 

Calendar findEventsAfter(Time time); 

Calendar findEventsBefore(Time time); 



friend std::ostream& operator << (std::ostream& out, const Calendar& obj); 
};


int main() 

{ 

    Time t = Time("2023 1 10 20 53"); 

    std::cout << t << std::endl; 

 

    Event e = Event("Presentation","2023 2 2 14 00","2023 2 2 16 15","S9A/67","Information technology presentation.Complete projects and tasks"); 

    Calendar c = Calendar("TEST", "events.txt"); 

    std::cout << c << std::endl; 

 

    c.addEvent(e); 

 

    Event e1 = Event("Launch", "2023 3 2 12 00", "2023 3 2 13 00", "Canteen", " Enjoy your meal."); 

    c.addEvent(e1); 

    std::cout << c << std::endl; 

 

    std::cout << c.findEvent("Exam") << std::endl; 

 

    std::cout << c.findEventsAfter(Time("2023 3 2 15 40")) << std::endl; 

    std::cout << c.findEventsBefore(Time("2023 3 2 8 00")) << std::endl; 

} 