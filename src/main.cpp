#include <fstream>
#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/writer.h"

using namespace rapidjson;

int main(int, char **)
{

    // read file
    std::ifstream ifs("sample.json");

    if (!ifs)
    {
      std::cout << "file not exist" << std::endl;
    }

    IStreamWrapper isw(ifs);

/*
    Document doc;
    doc.ParseStream(isw);

    std::cout << "a: " << doc["a"].GetInt() << std::endl;
    std::cout << "b: " << doc["b"].GetInt() << std::endl;
    std::cout << "c: " << doc["c"].GetInt() << std::endl;
    std::cout << " ---- " << std::endl;

    // change value
    doc["a"].SetInt(7); 

    std::cout << "a: " << doc["a"].GetInt() << std::endl;
    std::cout << "b: " << doc["b"].GetInt() << std::endl;
    std::cout << "c: " << doc["c"].GetInt() << std::endl;

    // write file
    std::ofstream ofs("output.json");
    OStreamWrapper osw(ofs);

    Writer<OStreamWrapper> writer(osw);
    doc.Accept(writer);    
    */
}
