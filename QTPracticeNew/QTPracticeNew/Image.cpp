#include "Image.h"

void Image::CheckCompatible() {
	// TODO - implement Image::CheckCompatible
	throw "Not yet implemented";
}

/**
 * @brief A function used to get an integer number for the vector
 * @param[in] name
 * @return
 */
int Image::convertToAscii(char name){
    cout << (int)name<< endl;
    return (int)name;
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
	
    //Convert string to ASCII
	//Sort data
	//Convert back to string

    //Define some vectors
	
	//Array of Names to sort
    vector<string> nameVector;
    vector<int> numVector;
    for (int letterNo = 1; letterNo < longestImageNameLength; letterNo++)
    {
        for(unsigned int i = 0; i < nameVector.size(); i++){
            try {
                numVector.push_back(convertToAscii(nameVector[i].at(letterNo)));
            } catch (nullptr_t e) {
                //If there is nothing left of the word then 0 will be returned
                numVector.push_back(0);
            }
        //Will produce a vector with ascii converted xth letters to sort through

	
	//When numArray finished
    //Sort the array into ascedning order (Bubble Sort)
        int temp;
        string tempName;
        for(unsigned int i=0;i<nameVector.size();i++){
            for(unsigned int j=i+1;j<nameVector.size()-1;j++){
                if(numVector[i]>numVector[j])
                {
                    temp = numVector[i];
                    numVector[i] = numVector[j];
                    numVector[j] = temp;
                    //Mimic this for the nameArray such that the numArray corresponds to the nameArray
                    tempName = nameVector[i];
                    nameVector[i] = nameVector[j];
                    nameVector[j] = tempName;
                }
            }
        }
        }

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
