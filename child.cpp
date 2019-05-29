#include <iostream>
#include <map>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/assign.hpp>


void handler(int signal) {
    std::cout << "handling signal" << std::endl;
}


int main() {
    std::cout << "I am child" << std::endl;

    // https://stackoverflow.com/questions/3071665/getting-a-directory-name-from-a-filename/3071722
    // prepare to write file
    std::map<int64_t, int64_t> foo = boost::assign::map_list_of (rand(), rand());
    boost::filesystem::path myFile = boost::filesystem::current_path().parent_path() / "myfile.dat";

    // debug
    //std::cout << "filename: " << myFile << std::endl;
    //std::cout << "parent path: " << myFile.parent_path() << std::endl;

    // write file
    boost::filesystem::ofstream ofs(myFile/*.native()*/);
    boost::archive::text_oarchive ta(ofs);
    ta << foo; // foo is empty until now, it's fed by myFile

    // end
    std::cout << "Wrote " << foo.size() << " random entries to " << myFile << "\n";
    return 0;
}
