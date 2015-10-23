//Miguel Fletes
//10/22/15
//FileIO_B

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
    ifstream inResult;
    ofstream outResult;
    
    inResult.open("scores.txt");
    outResult.open("results.txt");
    
    if(inResult.fail())
    {
        cout << "error opening input file" << endl;
        exit(1);
    }
    
    if(outResult.fail())
    {
        cout << "error opening output file" << endl;
        exit(1);
    }
    
    string firstName, lastName, maxFirst, maxLast;
    double s1, s2, s3, s4, s5, s6, average;
    double max = -25000;//initializes max
    
    while(inResult >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
    {
        outResult.setf(ios::fixed);
        outResult.setf(ios::showpoint);
        outResult.precision(1);//sets precision to 1 for the scores
        outResult.setf(ios::left);
        
        average = (s1 + s2 + s3 + s4 + s5) / 5;//calculates the average
        
        if(average > max)
        {//checks for the highest score and changes max accordingly
            max = average;
            maxFirst = firstName;
            maxLast = lastName;
        }
        //Result
        //
        outResult  << setw(10) << firstName << setw(10) << lastName << setw(8) << s1 << setw(8) << s2  << setw(8) << s3 << setw(8) << s4 << setw(8) << s5;//prints all of the data from the data file
        
        outResult.precision(2);//sets precision to 2 for the averages
        
        outResult << setw(8) << average << endl;//orints the average
    }
    
    outResult << endl << "Highest score: " << maxFirst << " " << maxLast;//prints the highest score
    
    inResult.close();//closes the files
    outResult.close();
    return 0;
}
