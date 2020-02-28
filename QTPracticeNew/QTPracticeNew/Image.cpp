#include "Image.h"

void Image::CheckCompatible() {
	// TODO - implement Image::CheckCompatible
	throw "Not yet implemented";
}

int Image::convertToAscii(string name){

    for (int i = 0; i < name.size(); i++){
        	cout << (int)name[i]<< endl;
		int nameNum = nameNum.append((int)name[i]);
    return nameNum;
    	}
}

string Image::convertToString(string str, int len){
	int num = 0;
	for (int i = 0; i < len;i++){
		//Append current digit
		num = num * 10 + (str[i] - '0');
		
		//If num is within required range
		if (num >= 32 && num <= 122){
			
			//convert num to char
			char ch = (char)num;
			
			//Reset
			num = 0;
		}
	}
	return ch;
}

void Image::SortAscendingName() {
	
	//Convert string to ascii
	//Sort data
	//Convert back to string
	
	//Array of Names to sort
	nameArray =[];
	numArray = [];
	for(int i = 0; i < names.length(); i++){
		numArray[i] = convertToAscii(nameArray[i]);
	}
	
	//When numArray finished
	//Sort the array into ascedning order
	int temp;
	for(i=0;i<names.length();i++){
		for(j=i+1;j<nameArray.length();j++){
			if(numArray[i]>numArray[j])
			{
				temp = numArray[i];
				numArray[i] = numArray[j];
				numArray[j] = temp;
			}
		}
	}
	
	//Array is sorted so convert back to string
	for(int i=0;i<numArray.lenght();i++){
		numArray[i] = convertToString(numArray[i], numArray[i].length())
	}
	
	// TODO - implement Image::SortAscendingName
	throw "Not yet implemented";
}

void Image::SortDescendingName() {
	// TODO - implement Image::SortDescendingName
	throw "Not yet implemented";
}

void Image::SortAscendingDate() {
	// TODO - implement Image::SortAscendingDate
	throw "Not yet implemented";
}

void Image::SortDescendingDate() {
	// TODO - implement Image::SortDescendingDate
	throw "Not yet implemented";
}
