#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include "easyfind.hpp"


int main(void)
{
    //vector
    std::vector<int> vect(10); 
    int value = 2; 
    std::fill(vect.begin(), vect.end(), value);
    std::vector<int>::iterator found = easyfind(vect, 2);
    if (found == vect.end())
        std::cout << "[+]Vector[+]   Eror 404 Dont found" << std::endl;
    else
        std::cout << "[+]Vector[+]   Yeah " << *found << " is inside me in " << found - vect.begin() << std::endl;
    if (easyfind(vect, 666) == vect.end())
        std::cout << "[+]Vector[+]   Eror 404 Dont found" << std::endl;

    //map
    std::map<int, int> map; 
    map.insert(std::pair<int,int>( 2, 30 )); 
    map.insert(std::pair<int,int>( 1, 42 )); 
    map.insert(std::pair<int,int>( 3, 42 )); 
    std::map<int, int>::iterator foundMap = easyfind(map, 42);
    if (foundMap == map.end())
        std::cout << "[+]Map[+]      Eror 404 Dont found" << std::endl;
    else
        std::cout << "[+]Map[+]      Yeah " << foundMap->second << " is inside me in " << foundMap->first << std::endl;
    if (easyfind(map, 666) == map.end())
        std::cout << "[+]Map[+]      Eror 404 Dont found" << std::endl;
	
    //multimap
    std::multimap<int, int> multimap; 
    multimap.insert(std::pair<int,int>( 2, 30 )); 
    multimap.insert(std::pair<int,int>( 33, 9 )); 
    std::multimap<int, int>::iterator foundMP = easyfind(multimap, 9);
    if (foundMP == multimap.end())
        std::cout << "[+]MultiMap[+] Eror 404 Dont found" << std::endl;
    else
        std::cout << "[+]MultiMap[+] Yeah " << foundMP->second  <<" is inside me in " << foundMP->first << std::endl;
    if (easyfind(multimap, 666) == multimap.end())
        std::cout << "[+]MultiMap[+] Eror 404 Dont found" << std::endl;

	return (0);
}