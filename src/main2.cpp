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
    std::ifstream ifs("sample2.json");

    if (!ifs)
    {
      std::cout << "file not exist" << std::endl;

      // (ref) 
      // https://www.qoosky.io/techs/5bc254637c
      std::string json = "{\"data\": [0, 1, 2, 3 ]}";
      rapidjson::Document d;
      d.Parse(json.c_str());

      // write file
//      std::ofstream ofs("sample.json");

      std::string home_dir = std::getenv("HOME");
      std::cout << "home dir:" << home_dir << std::endl;
      std::ofstream ofs(home_dir + "/.ros/sample.json");
      OStreamWrapper osw(ofs);

      Writer<OStreamWrapper> writer(osw);
      d.Accept(writer);    

    }
    else
    {

      IStreamWrapper isw(ifs);

      Document doc;
      doc.ParseStream(isw);

      const Value& a = doc["data"];

      assert(a.IsArray());
for (SizeType i = 0; i < a.Size(); i++) // Uses SizeType instead of size_t
        printf("a[%d] = %d\n", i, a[i].GetInt());

      // write file
      std::ofstream ofs("output.json");
      OStreamWrapper osw(ofs);

      Writer<OStreamWrapper> writer(osw);
      doc.Accept(writer);    
    }

}
