#include "Image.h"

void Image::CheckCompatible() {
	// TODO - implement Image::CheckCompatible
	throw "Not yet implemented";
}


/**
 * @brief A function that will look at the first letters of the names of the Images that have been edited.
 * It will sort this list, using the bubble sort at this stage, and then move onto the next letter and repeat the process.
 */
QVector<shareClass::fileData> Image::SortAscendingName(QVector<shareClass::fileData> nameVector) {
	
    //Convert string to ASCII
	//Sort data
	//Convert back to string

    //Define some vectors
	
	//Array of Names to sort
    /*
    vector<int> numVector;

    for (unsigned int letterNo = 1; letterNo < longestImageNameLength; letterNo++)
    {
        for(unsigned int i = 0; i < nameVector.size(); i++){
            try {
                int a = nameVector[i].at(letterNo).toLower().toLatin1();
                numVector.push_back(a);
            } catch (nullptr_t e) {
                //If there is nothing left of the word then 0 will be returned
                numVector.push_back(0);
            }
            //Will produce a vector with ascii converted xth letters to sort through


	//When numArray finished
    //Sort the array into ascedning order (Bubble Sort)
        int temp;
        QString tempName;
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
    */

    ///////////////NEW SORT ALGORITHM ////////////
    bool swapped = false;


        for (int i = 0; i < nameVector.size() - 1; ++i) {
            for (int j = 0; j < nameVector.size() - 1 - i; ++j) {

                if (nameVector[j].name.toLower() > nameVector[j + 1].name.toLower()) {
                    shareClass::fileData temp = nameVector[j];
                    nameVector[j] = nameVector[j + 1];
                    nameVector[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
            swapped = false;
        }
        return nameVector;

}


QVector<shareClass::fileData> Image::SortDescendingName(QVector<shareClass::fileData> nameVector) {
    ///////////////NEW SORT ALGORITHM ////////////
    bool swapped = false;


        for (int i = 0; i < nameVector.size() - 1; ++i) {
            for (int j = 0; j < nameVector.size() - 1 - i; ++j) {

                if (nameVector[j].name.toLower() < nameVector[j + 1].name.toLower()) {
                    shareClass::fileData temp = nameVector[j];
                    nameVector[j] = nameVector[j + 1];
                    nameVector[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
            swapped = false;
        }
        return nameVector;
           // sorted list needs to be displayed to the gui
}

QVector<shareClass::fileData> Image::SortAscendingDate(QVector<shareClass::fileData> dateVector) {
    ///////////////NEW SORT ALGORITHM ////////////
    bool swapped = false;


        for (int i = 0; i < dateVector.size() - 1; ++i) {
            for (int j = 0; j < dateVector.size() - 1 - i; ++j) {

                if (dateVector[j].dateModified > dateVector[j + 1].dateModified) {
                    shareClass::fileData temp = dateVector[j];
                    dateVector[j] = dateVector[j + 1];
                    dateVector[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
            swapped = false;
        }
        return dateVector;
	// TODO - implement Image::SortAscendingDate
	throw "Not yet implemented";
}

QVector<shareClass::fileData> Image::SortDescendingDate(QVector<shareClass::fileData> dateVector) {
    ///////////////NEW SORT ALGORITHM ////////////
    bool swapped = false;


        for (int i = 0; i < dateVector.size() - 1; ++i) {
            for (int j = 0; j < dateVector.size() - 1 - i; ++j) {

                if (dateVector[j].dateModified < dateVector[j + 1].dateModified) {
                    shareClass::fileData temp = dateVector[j];
                    dateVector[j] = dateVector[j + 1];
                    dateVector[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
            swapped = false;
        }
        return dateVector;

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
