#include "Image.h"

void Image::CheckCompatible() {
	// TODO - implement Image::CheckCompatible
	throw "Not yet implemented";
}

int Image::convertToAscii(string name){
	
	for (int i = 0; i < name.length(); i++){
        	cout << (int)name[i]<< endl;
		int nameNum = nameNum.append((int)name[i]);
	return nameNum	
    	}
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
