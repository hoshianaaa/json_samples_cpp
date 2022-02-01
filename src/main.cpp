#include <fstream>
#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

using namespace rapidjson;

int main(int, char **)
{
    std::ifstream ifs("sample.json");
    IStreamWrapper isw(ifs);

    Document doc;
    doc.ParseStream(isw);

    std::cout << "a: " << doc["a"].GetInt() << std::endl;
}
