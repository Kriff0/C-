/*
 * 
 * 
 * SOM DAVID - BOLLIER VALENTIN
 * TP1 read_story
 * 
 * Salut BB
 * 
 * 
 */

#include<iostream>
#include<string>
#include<cmath>
#include <fstream>


//MAIN
using namespace std;



bool is_date(int day,int month,int year){
    // La date sera t-elle valide ?
    
    if ((day>31 || day < 1) || (month>12 || month<1) || (year < 1) ){
        cerr << "Error 2 : Date $dob not valid"<< endl;
        exit (2);
    }

    else { //  L'année est valide et on regarde si l'année estbissextile
         if ( (year%400==0) || ( (year%100!=0) && (year%4==0) ) ){
            cout << "L'année est bissextile"<< endl;
        
        }
            cout << "La date est valide"<< endl;
    }   
        
 return 0;   
}
   
// transformation de la chaine de caractere rentrée en variables int 
    // Séparation des chaines de caractères
bool parse_date(string date_name, int& day, int& month, int& year){ 
    
// On sépare les chaines suivant le séparateur "/"
    string str_day = date_name.substr(0, date_name.find("/"));
    date_name = date_name.substr(date_name.find("/")+1);
    string str_month = date_name.substr(0, date_name.find("/"));
    string str_year= date_name.substr(date_name.find("/")+1);

    // Conversion en int
    day=stoi(str_day);
    month=stoi(str_month);
    year=stoi(str_year);
    return(is_date( day, month, year));
  
}


void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr) // Importer car boost::replace & regex ne marchent pas 
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + replaceStr.size());
	}
}
 






int read_story(string filename, string name, string dob){
    
    ifstream flux1(filename,ios::in);     // Ouverture en mode lecture  fichier txt
    if(flux1)    
    {   
         string contenu; 
         string ligne;
         while(getline(flux1, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            findAndReplaceAll(ligne, "$(dob)",dob);
            findAndReplaceAll(ligne, "$(name)",name);
            cout << ligne << endl;  // on l'affiche
            }

        
        
    flux1.close(); // ferme la fenetre
    }
      
    else
    {
        cerr << "Error 3 : Story $filename not found avec $filename" << endl;
        exit (3);
    }
    return 0;
    
}




int main(int argc, char *argv[]){

if (argc<4){  // 4 argument car le fichier executable est le premier
       cerr << "Error 1 : Running out of arguments "<<  endl ;
       exit (1);
}
    //attribution des arguments
string file_name(argv[1]);
string name(argv[2]);
string date_name(argv[3]);

   int day;
   int month;
   int year;



    parse_date(date_name,day,month,year);
    read_story(file_name,name,date_name);


}



  
  
  
  
