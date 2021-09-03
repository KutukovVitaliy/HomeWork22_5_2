#include <iostream>
#include <map>
#include <string>

int main() {
    std::string inString;
    std::map<std::string, int> registrationMap;
    bool exit = false;
    do{
        std::cout << "Please input 'next' or 'last name': ";
        std::cin >> inString;
        if(inString == "exit") exit = true;
        else if(inString == "next"){
            if(registrationMap.empty()){
                std::cout << "No last names in list!" << std::endl;
            }
            else if(registrationMap.begin()->second > 1){
                registrationMap.begin()->second -=1;
                std::cout << "->" << registrationMap.begin()->first << std::endl;
            }
            else{
                std::cout << "->" << registrationMap.begin()->first << std::endl;
                registrationMap.erase(registrationMap.begin());
            }
           /* std::map<std::string, int>::iterator it;
            for(it  = registrationMap.begin();it != registrationMap.end(); it++)
                std::cout << it->first << " " << it->second << std::endl;*/
        }
        else {
            std::map<std::string, int>::iterator it;
            it = registrationMap.find(inString);
            if(it != registrationMap.end()){
                it->second += 1;
            }
            else {
                registrationMap.insert(std::make_pair(inString,1));
                /*std::cout << "Current map:" << std::endl;
                std::map<std::string, int>::iterator it;
                for(it  = registrationMap.begin();it != registrationMap.end(); it++)
                    std::cout << it->first << " " << it->second << std::endl;*/
            }
        }
    }while(!exit);


    return 0;
}
