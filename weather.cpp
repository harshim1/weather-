#include<iostream>
#include<string>
using namespace std;

struct WeatherStation  {
	
	string StationDesignation;
	
	double Temperature;
	
};

int i(0);
double Calc(double fahren);
double Total(0),Celsius[5],Fahrenheit[5];  
double CelsiusLowTemperature(0), FahrenheitLowTemperature(1000), 
CelsiusHighTemperature(0), 
FahrenheitHighTemperature(-1000);
double Mean_Celsius, Mean_Fahrenheit;

void ShowList()
{
	
	cout<<"Command Choices................"<<"\n"<<endl;
	cout<<"_____________________________"<<"\n"<<endl;
	cout<<"\t"<<"Post Temperatures" <<"\n"<<endl;
	cout<<"\t"<<"Daily Report" <<"\n"<<endl;
	cout<<"\t"<<"High-Low Report" <<"\n" <<endl;
	cout<<"\t"<<"Quit" <<"\n"<<endl;
	cout<<"_____________________________"<<"\n"<<endl;

}	

void PostTemperatures()
{
	cout<< "Please enter reported temperatures..."<<"\n"<< "\n";
	cout<< "Weather Station Big Basin: "; 
	cin>>Fahrenheit[i];
	cout<< "Weather Station Foothill: "; 
	cin>>Fahrenheit[i];
	cout<< "Weather Station DeAnza: ";
	cin>>Fahrenheit[i];
	cout<< "Weather Station MiddleField: ";
	cin>>Fahrenheit[i];
	cout<< "Weather Station Redwood City: ";
	cin>>Fahrenheit[i];
	cout<<"\n"<<"\n"
	<<"----------------------------------------------"<<endl;
}

void DailyReport()
{
	cout<<"\t"<< "NGS Daily Temperature Report"<<endl;
	cout<<"================================================="<<endl;
	cout<<"                      Fahrenheit       Celsius                          "<<endl;
	cout<<" --------------------------------------------------------------"<<endl;
	
}

void HighLowReport()
{
	cout<< "===========NGS Temperature Data Report========="<<endl;
	//cout<<"Lowest Temperature:     "<<FahrenheitLowTemperature<<"         "<<CelsiusLowTemperature<<endl;
	cout<<" --------------------------------------------------------------"<<endl;
	//cout<<"Highest Temperature:    "<<FahrenheitHighTemperature<<"               "<<CelsiusHighTemperature<<endl;
	cout<<" --------------------------------------------------------------"<<endl;
	
}

void Quit()
{
	cout<<"===============End Temperature Data Report============="<<endl;
}

	
 int main()
{
	ShowList();
	PostTemperatures();
	
	for(i=0;i<5;i++) //Loops
		
	{
		
		cout<<"Weather Station "<<i+1<<" = ";// Takes input for Reported Temperatures For Weather Stations...
		
		cin>>Fahrenheit[i];
		
		if(Fahrenheit[i]<FahrenheitLowTemperature) // Conditionals  
			
            FahrenheitLowTemperature=Fahrenheit[i];
		
		if(Fahrenheit[i]>FahrenheitHighTemperature)
			
            FahrenheitHighTemperature=Fahrenheit[i];
		
		Celsius[i] = Calc(Fahrenheit[i]);
		
		Total+=Fahrenheit[i]; 
		
	}
	
	CelsiusLowTemperature = Calc(FahrenheitLowTemperature);
	
	CelsiusHighTemperature = Calc(FahrenheitHighTemperature);
	
	Mean_Fahrenheit = Total/5.0; // Calculates the mean for Fahrenheit
	
	Mean_Celsius = Calc(Mean_Fahrenheit); // Calculates the mean for Celsius
	
	
	
	cout.precision(3);
	
	cout<<" ========NGS Temperature Data Report======== "<<endl; 
	cout<<"                      Fahrenheit       Celsius                          "<<endl;
	cout<<" --------------------------------------------------------------"<<endl;
	cout<<"Lowest Temperature:     "<<FahrenheitLowTemperature<<"         "<<CelsiusLowTemperature<<endl;
	cout<<" --------------------------------------------------------------"<<endl;
	cout<<"Highest Temperature:    "<<FahrenheitHighTemperature<<"               "<<CelsiusHighTemperature<<endl;
	cout<<" --------------------------------------------------------------"<<endl;
	cout<<"Mean Temperature:       "<<Mean_Fahrenheit<<"          "<<Mean_Celsius<<endl;
	cout<<" --------------------------------------------------------------"<<endl;
	cout<<"Raw Data..."<<endl;
	cout<<"\n";
	
	// Outputs Data that include the following: Fahrenheit Low and High, Celsius Low and High and Mean...
	
	for(i=0;i<5;i++) // Loops
		
	{ 
		
		cout.precision(3);
		
		cout<<"WeatherStation "<< i <<" =     "<<Fahrenheit[i]<<"            "<<Celsius[i]<<endl;
		
	}
	
	cout<<" --------------------------------------------------------------"<<endl;
	cout<<" =============End Temperature Data Report============="<<endl;
	
}

double Calc(double fah) 

{
	
	double cel; // Converts Fahrenheit to Celsius
	
	cel = (5 *(fah - 32))/9.0;
	
	return cel;
	
}