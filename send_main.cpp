#include "serial.hpp"
#include <iostream>
#include <string>
int main(int argc,char **argv){
	using namespace std;
	cout<<"test...."<<endl;	
	Serial lora("/dev/ttyUSB1",9600);
	char send_buf = 'H';//or serial_port replace with port name
	cout<<"I'm ready to send"<<endl;
	string gps_a("123.456, 012.345");
	string send_a;
	send_a = "a" + gps_a;
	while(1){
		if(lora.swrite(send_a.c_str(), send_a.size()+1)>0){ //보낼 데이터가 있다면 양수, 수신도 마찬가지
			cout<<"I send :"<<send_a.c_str()<<endl;
			sleep(1); 
		}
	}
	return 0;
}
