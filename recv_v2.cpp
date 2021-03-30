#include "serial.hpp"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

typedef tuple<string, int, float, float> msg;
Serial lora("/dev/ttyUSB0",9600);
char read_buf;

msg receive_massage(){
	string read, name_str, state_str, latitude_str, longitude_str;
	msg value;
	string null="";
	int state;
	float latitude, longitude;
	while(1){
		if(lora.sread(&read_buf, sizeof(char))>0){
			read += read_buf;
			if(read.size() == 2){
				if(read[0] != 'F'){
					cout<<"It`s not our massage"<<endl;
					return value = make_tuple(null, -1, -1, -1);
				}
				else{
					if(read[1] != 'F'){
						cout<<"It`s not our massage"<<endl;
						return value = make_tuple(null, -1, -1, -1);
					}
				}
			}
			if(read_buf == '\0'){
				break;
			}
		}
	}
	int count = 0;
	for(int i = 2; i < read.size(); i++){
		if(read[i] == ','){
			count++;
		}
		else if(count == 0){
			name_str += read[i];
		}
		else if(count == 1){
			state_str += read[i];
		}
		else if(count == 2){
			latitude_str += read[i];
		}
		else if(count == 3){
			longitude_str += read[i];
		}
	}
	state = stoi(state_str);
	latitude = stof(latitude_str);
	longitude = stof(longitude_str);
	value = make_tuple(name_str, state, latitude, longitude);
	return value;
}

int main(int argc, char** argv){
	cout<<"test...."<<endl;
	while(1){
		auto read_value = receive_massage();
		if(get<1>(read_value) == -1 && get<2>(read_value) == -1 && get<3>(read_value) == -1){
			cout<<"retry!!"<<endl;
		}
		else
			cout<<"name : "<<get<0>(read_value)<<", state : "<< get<1>(read_value)<<", latitude : "<< get<2>(read_value)<<", longitude : "<< get<3>(read_value)<<endl;
	}
}