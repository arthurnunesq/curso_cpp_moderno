#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void show(const std::unordered_map<std::string,std::string>& mymap){
	unsigned load_factor = mymap.load_factor();
	std::cout << "mymap load_factor is " << load_factor << ".\n";

	unsigned bucket_count = mymap.bucket_count();
	std::cout << "mymap has " << bucket_count << " buckets.\n";

	for (unsigned i=0; i<bucket_count; ++i) {
		std::cout << "bucket #" << i << " contains: ";
		for (auto it = mymap.begin(i); it!=mymap.end(i); ++it)
			std::cout << "[" << it->first << ":" << it->second << "] ";
			std::cout << "\n";
	}

}

// http://www.cplusplus.com/reference/unordered_map/unordered_map/bucket_count/
// http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
// http://www.cplusplus.com/reference/unordered_map/unordered_map/erase/
int main ()
{
	std::unordered_map<std::string,std::string> mymap = {
		{"house","maison"},
		{"apple","pomme"},
		{"tree","arbre"},
		{"book","livre"},
		{"door","porte"},
		{"grapefruit","pamplemousse"}
	};

	mymap.insert(std::make_pair("I", "je"));
	mymap.insert(std::make_pair("knee", "genou"));

  	mymap["flower"] = "fleur";

	show(mymap);

  	// FIND
	std::string input;
	std::cout << "who? ";
	getline (std::cin,input);

	std::unordered_map<std::string,std::string>::const_iterator got = mymap.find(input);

	if ( got == mymap.end() )
		std::cout << "not found";
	else
		std::cout << got->first << " is " << got->second;

	std::cout << std::endl;

	// ERASE
	// erase examples:
	mymap.erase ( mymap.begin() );      // erasing by iterator
	mymap.erase ("tree");             // erasing by key
	mymap.erase ( mymap.find("knee"), mymap.end() ); // erasing by range
	show(mymap);

	return 0;
}

