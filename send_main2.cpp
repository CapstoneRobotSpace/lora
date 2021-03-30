#include "serial.hpp"
#include <iostream>
#include <string>
/*int main(int argc,char **argv){
	using namespace std;
	//string port_name = ;
	cout<<"test...."<<endl;	
	Serial lora("/dev/ttyUSB2",9600);
	char send_buf = 'F';
	cout<<"I'm ready to send"<<endl;
	while(1){
			if(lora.swrite("FFFFF", sizeof(char)*6)>0){
			cout<<"I send :"<<send_buf<<endl;
			sleep(1); 
		}
	}
	return 0;
}*/

/*
int main(int argc,char **argv){
	using namespace std;
	string read;
	cout<<"test...."<<endl;	
	Serial lora("/dev/ttyUSB2",9600);
	char read_buf;
	cout<<"I'm ready to read"<<endl;
	while(1){
		while(1){
			if(lora.sread(&read_buf, sizeof(char))>0){
				read += read_buf;
				if(read_buf == '\0'){
					cout<<"I read :"<<read<<endl;
					break;}
			}
		}
		read = "";
		
	}
	
	return 0;
}
*/

int main(int argc, char **argv){
	using namespace std;
	Serial lora("/dev/ttyUSB2", 9600);
	string read;
	string send_b;
	string gps_b("234.567, 123.456");
	char read_buf;
	send_b = "b" + gps_b;
	while(1){
		if(read[0] == 'a'){
			read = "";
			cout<<"I'm ready to send"<<endl;
			if(lora.swrite(send_b.c_str(), send_b.size()+1)>0){
				cout<<"I send :"<<send_b.c_str()<<endl;
			}
			
		}
		else{
			read = "";
			cout<<"I'm ready to read"<<endl;
			while(1){
				if(lora.sread(&read_buf, sizeof(char))>0){
					read += read_buf;
					if(read_buf == '\0'){
						cout<<"I read : "<<read<<endl;
						break;
					}
				}			
			}
		}
	}
	return 0;
}

