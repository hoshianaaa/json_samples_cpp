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

      // (ref) 
      // https://www.qoosky.io/techs/5bc254637c
      std::string json = "{\"project\":\"rapidjson\",\"stars\":10}";
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
    }

}
