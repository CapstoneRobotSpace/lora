#include "serial.hpp"
#include <iostream>
#include <pthread.h>
#include <thread>
#include <string>

int main(int argc,char **argv){
	using namespace std;
	string read, read_a, read_b;
	cout<<"test...."<<endl;	
	Serial lora("/dev/ttyUSB0",9600);
	char read_buf;
	cout<<"I'm ready to read"<<endl;
	while(1){
		if(read[0]=='a'){
			read_a = read;
			read = "";
			cout<<"I read A : "<<read_a<<endl;
		}
		else if(read[0] == 'b'){
			read_b = read;
			read = "";
			cout<<"I read B : "<<read_b<<endl;
		}
		else{
			while(1){
				if(lora.sread(&read_buf, sizeof(char))>0){
					read += read_buf;
					if(read_buf == '\0'){
						break;}
				}
			}
		}
		
	}
	
	return 0;
}


/*using namespace std;	
Serial lora("/dev/ttyUSB0",9600);
char read_buf;

void *lora_cb1(void *count){
	while(1){
		if(lora.sread(&read_buf, sizeof(char))>0){
			cout<<"I read_1 :"<<read_buf<<endl;
		}
	}
}
void *lora_cb2(void *count){
	while(1){
		if(lora.sread(&read_buf, sizeof(char))>0){
			if(read_buf
			cout<<"I read_2 :"<<read_buf<<endl;
		}
	}
}
int main(int argc,char **argv){	
	int status, count;
	cout<<"test...."<<endl;
	cout<<"I'm ready to hear"<<endl;
	pthread_t _t1, _t2;	
	pthread_create(&_t1, NULL, lora_cb1, (void *)count);
	pthread_create(&_t2, NULL, lora_cb2, (void *)count);
	pthread_join(_t1, (void **)&status);
	pthread_join(_t2, (void **)&status);	
	return 0;
}*/
