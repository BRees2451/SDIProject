#include "Image.h"

void Image::CheckCompatible() {
	// TODO - implement Image::CheckCompatible
	throw "Not yet implemented";
}


/**
 * @brief A function that will look at the first letters of the names of the Images that have been edited.
 * It will sort this list, using the bubble sort at this stage, and then move onto the next letter and repeat the process.
 */
void Image::SortAscendingName() {
	
    //Convert string to ASCII
	//Sort data
	//Convert back to string

    //Define some vectors
	
	//Array of Names to sort
    vector<string> nameVector = new vector<string>;
    vector<int> numVector;

    for (unsigned int letterNo = 1; letterNo < longestImageNameLength; letterNo++)
    {
        for(unsigned int i = 0; i < nameVector.size(); i++){
            try {
                numVector.push_back((int)nameVector[i].at(letterNo));
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


/**
 * @brief This will check any new images to potentially overwrite the longestImageNameLength.
 * @param[in] imageName
 */
void Image:: checkImageNameLength(string imageName)
{
    unsigned int nameLength = imageName.length();
    if (nameLength > longestImageNameLength) longestImageNameLength = nameLength;
}
