#include<iostream>
#include<string>
using namespace std;
class CGPA{
	int c[7],g[7];
	string lg[7];
	int sum_cg=0;
	float credits=0;
	float sgpa=0;
	public:
	void read();
	void grad_to_point();
	void calc();
	void display();
	int sump();
	int sumq();
};


	void CGPA::read(){
		for(int i=0;i<7;i++){
			cout<<"Sub"<<i+1<<" Credits & Grade = ";
			cin>>c[i]>>lg[i];
		}
	}
	
	void CGPA::grad_to_point(){
		for(int i=0;i<7;i++){
			g[i]=(lg[i]=="O")?10:(lg[i]=="A+")?9:(lg[i]=="A")?8:(lg[i]=="B+")?7:(lg[i]=="B")?6:0;
		}
	}
	
	void CGPA::calc(){
		for(int i=0;i<7;i++){
			credits+=c[i];
			sum_cg+=c[i]*g[i];
		}
		sgpa=sum_cg/credits;
	}
	
	void CGPA::display(){
		if(sgpa>10){
			cout<<"Oops... Something you have entered wrongly...";
		}
		else{
			cout<<"SGPA = "<<sgpa;
		}
	}
	
	int CGPA::sump(){
		return sum_cg;
	}
	int CGPA::sumq(){
		return credits;
	}
	
	
int main(){
	cout<<"\t\t---- CGPA CALCULATOR ----\n\n";
	CGPA x[8];
	int n;
	cout<<"How many Semesters completed? ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<endl<<"Enter the Credits and the Grade you earned in each subject of Semester "<<i+1<<endl;
		x[i].read();
		x[i].grad_to_point();
		x[i].calc();
		x[i].display();
	}
	float p=0,q=0;
	for(int i=0;i<n;i++){
		p+=x[i].sump();
		q+=x[i].sumq();
	}
	cout<<"\nCGPA = "<<p/q;
	return 0;
}
